#include "qconnectorblob.h"
#include "ui_qconnectorblob.h"

unsigned int qconnectorblob::smIDcounter = 0;
bool qconnectorblob::DnDStartStopFlag = false;
QPoint qconnectorblob::smDragStartPosition;
QMap<unsigned int,QNodeConnectorTuple> qconnectorblob::Connections;

qconnectorblob::qconnectorblob(QWidget *parent, bool type,
                               QNodeWidget *myPWidget) :
    QRadioButton(parent)
{
    setAcceptDrops(true);
    this->setAutoExclusive(false);
    mNodeWidget = myPWidget;
    mtype = type;

    //Create a new Tuple for storing Connections
    QNodeConnectorTuple newConnection;
    //THIS
    newConnection.property[0] = this;
    newConnection.owner[0] = mNodeWidget;
    //THAT
    newConnection.property[1] = nullptr;
    newConnection.owner[1] = nullptr;

    Connections.insert(mID, newConnection);

    //Connect to NodeView for DnD Messageing
    QObject::connect(this, SIGNAL(messageSent(qDnDMessage)),
                     mNodeWidget->mParentView,
                     SLOT(handleDndMessage(qDnDMessage))
                     );

    //Incrementing the current mIDcounter
    mID = smIDcounter++;
}

void qconnectorblob::sendMessage(qDnDMessage::type type)
 {
     qDnDMessage newMessage;
     newMessage.mType = type;
     newMessage.senderObject = this;
     newMessage.dataModel = &Connections;

     thisDnDMessage = newMessage;
     emit messageSent(thisDnDMessage);
 }

void qconnectorblob::makeDrag()
{
    QDrag *dr = new QDrag(this);
    // The data to be transferred by the drag and drop operation is contained in a QMimeData object
    QMimeData *data = new QMimeData;
    data->setText("This is a test");
    // Assign ownership of the QMimeData object to the QDrag object.
    dr->setMimeData(data);
    // Start the drag and drop operation
    dr->start();
}

void qconnectorblob::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        smDragStartPosition = event->pos();
}

void qconnectorblob::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - smDragStartPosition).manhattanLength()
         < QApplication::startDragDistance())
        return;

    //This is for Debugging puposes only
    //QByteArray QConnectorID;
    //QConnectorID.append(this->mIDcounter);            //QConnectorID
    //QByteArray QNodeID;
    //QNodeID.append(this->mNodeWidget->mIDcounter);    //QNodeID

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setParent(this);

    //mimeData->setData(mimeType, data);
    drag->setMimeData(mimeData);

    //qDebug("Send DragStartMessage to the QNodeView");
    sendMessage(qDnDMessage::Drag);

    DnDStartStopFlag = true;
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    //Disconnect if dropped not on another qConnectorBlob
    if(DnDStartStopFlag){

        if(Connections[mID].property[1] != nullptr){
            qDebug("Disconnect: #QConnector: %i, #QNode: %i ",  Connections[mID].property[1]->mID,
                                                                Connections[mID].owner[1]->mID);
            qDebug("...from   : #QConnector: %i, #QNode: %i ", this->mID,
                                                                this->mNodeWidget->mID);

            Connections[Connections[mID].property[1]->mID].owner[1] = nullptr;
            Connections[Connections[mID].property[1]->mID].property[1] = nullptr;
        }

        Connections[mID].property[1] = nullptr;
        Connections[mID].owner[1] = nullptr;
        sendMessage(qDnDMessage::DndDisconnect);
    }
}

void qconnectorblob::dropEvent(QDropEvent *de){
    // Unpack dropped data and handle it the way you want
    // Like in Java :)
    qconnectorblob *draggedObject;
    draggedObject = (qconnectorblob*) de->mimeData()->parent();


    //write the data into the model
    if(draggedObject->mNodeWidget->mID != this->mNodeWidget->mID){
        if(draggedObject->mtype != this->mtype){
            qDebug("From: #QConnector: %i, #QNode: %i ", draggedObject->mID,
                                                         draggedObject->mNodeWidget->mID);
            qDebug("To  : #QConnector: %i, #QNode: %i ", this->mID,
                                                         this->mNodeWidget->mID);

            Connections[draggedObject->mID].property[1] = this;
            Connections[draggedObject->mID].owner[1]    = this->mNodeWidget;

            Connections[this->mID].property[1] = draggedObject;
            Connections[this->mID].owner[1]    = draggedObject->mNodeWidget;

            sendMessage(qDnDMessage::ValidDrop);
            DnDStartStopFlag = false;
        }
    }
}

void qconnectorblob::dragMoveEvent(QDragMoveEvent *de){
    // The event needs to be accepted here
    de->accept();
    //qDebug("Contents: %s", "Test");
}

void qconnectorblob::dragEnterEvent(QDragEnterEvent *event){
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

qconnectorblob::~qconnectorblob()
{

    //Delete "THAT" :-P (if you understand these lines everything else is easy as reading micky mouse)
    //Tipp: "0" is always "THIS" and "1" is always "THAT"
    if(Connections[mID].property[1] != nullptr){
        Connections[Connections[mID].property[1]->mID].owner[1] = nullptr;
        Connections[Connections[mID].property[1]->mID].property[1] = nullptr;
    }

    Connections.remove(mID);
}
