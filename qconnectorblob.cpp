#include "qconnectorblob.h"
#include "ui_qconnectorblob.h"

unsigned long qconnectorblob::smIDcounter = 0;
bool qconnectorblob::DnDStartStopFlag = false;
QPoint qconnectorblob::smDragStartPosition;
QMap<unsigned long,QNodeConnectorTuple> qconnectorblob::Connections;

qconnectorblob::qconnectorblob(QWidget *parent, bool type,
                               QNodeWidget *myPWidget, long myID, long connectToID) :
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

    //Draw the "noConnection"
    mConnector.setLine(this->getPositionInGView().x(),
                       this->getPositionInGView().y(),
                       this->getPositionInGView().x(),
                       this->getPositionInGView().y());

    //Set to Scene
    mNodeWidget->mParentView->scene()->addItem(&mConnector);

    if(myID == -1){
        //Incrementing the current mIDcounter
        mID = smIDcounter++;
        mConnectedToID = -1;
    }else{
        mID = myID;
        mConnectedToID = connectToID;
    }
}

void qconnectorblob::postLoadingConnect(){
    //Here will all connections be esablished after the whole Scene is generated


    repaintMyConnector();
}

QString qconnectorblob::getIDTuple(){
    QString IDTuple = "[" + QString::number(mID) +
                      "," + QString::number(mConnectedToID) + "]";
    return IDTuple;
}

void qconnectorblob::repaintMyConnector(){
    if(Connections[mID].property[1] != nullptr){
        qconnectorblob *toConnected = Connections[mID].property[1];
        mConnector.setLine(this->getPositionInGView().x(),
                           this->getPositionInGView().y(),
                           toConnected->getPositionInGView().x(),
                           toConnected->getPositionInGView().y());
        toConnected->mConnector.hide();
    }else
        mConnector.setLine(this->getPositionInGView().x(),
                           this->getPositionInGView().y(),
                           this->getPositionInGView().x(),
                           this->getPositionInGView().y());
    mConnector.show();
}

void qconnectorblob::moveEvent(QMoveEvent *event){
    //Repaint all of my Connections
    repaintMyConnector();
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

QPoint qconnectorblob::getPositionInGView(){
    return mNodeWidget->mapToParent(this->geometry().center());
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

    DnDStartStopFlag = true;
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    //Disconnect if dropped not on another qConnectorBlob
    if(DnDStartStopFlag){

        if(Connections[mID].property[1] != nullptr){
            qDebug("Disconnect: #QConnector: %ld, #QNode: %ld ",  Connections[mID].property[1]->mID,
                                                                Connections[mID].owner[1]->mID);
            qDebug("...from   : #QConnector: %ld, #QNode: %ld ", this->mID,
                                                                this->mNodeWidget->mID);

            Connections[Connections[mID].property[1]->mID].owner[1] = nullptr;
            Connections[Connections[mID].property[1]->mID].property[1] = nullptr;

            Connections[mID].property[1]->setChecked(false);
            Connections[mID].property[1]->repaintMyConnector();

            mConnectedToID = -1;
        }

        Connections[mID].property[1] = nullptr;
        Connections[mID].owner[1] = nullptr;

        repaintMyConnector();

        this->setChecked(false);
    }

    mNodeWidget->updateIOText();
}

void qconnectorblob::dropEvent(QDropEvent *de){
    // Unpack dropped data and handle it the way you want
    // Like in Java :)
    qconnectorblob *draggedObject;
    draggedObject = (qconnectorblob*) de->mimeData()->parent();


    //write the data into the model
    if(draggedObject->mNodeWidget->mID != this->mNodeWidget->mID){
        if(draggedObject->mtype != this->mtype){
            qDebug("From: #QConnector: %ld, #QNode: %ld ", draggedObject->mID,
                                                         draggedObject->mNodeWidget->mID);
            qDebug("To  : #QConnector: %ld, #QNode: %ld ", this->mID,
                                                         this->mNodeWidget->mID);

            Connections[draggedObject->mID].property[1] = this;
            Connections[draggedObject->mID].owner[1]    = this->mNodeWidget;

            Connections[this->mID].property[1] = draggedObject;
            Connections[this->mID].owner[1]    = draggedObject->mNodeWidget;

            mConnectedToID = draggedObject->mID;
            draggedObject->mConnectedToID = mID;

            DnDStartStopFlag = false;

            repaintMyConnector();
            mNodeWidget->updateIOText();

            draggedObject->setChecked(true);
            setChecked(true);
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
