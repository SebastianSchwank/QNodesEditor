#include "qnodewidget.h"
#include "ui_qnodewidget.h"


unsigned int QNodeWidget::mIDcounter = 0;

QMap<int,QNodeWidget*> QNodeWidget::QNodeCollector;

QNodeWidget::QNodeWidget(QWidget *parent, QNodeView *view, QString thisID, QPoint *myPos) :
    QWidget(parent),
    ui(new Ui::QNodeWidget)
{
    ui->setupUi(this);

    //Make this widget scalable
    this->setWindowFlags(Qt::SubWindow);

    QSizeGrip * sizeGrip = new QSizeGrip(this);
    ui->gridLayout_2->addWidget(sizeGrip, 0,0,1,1,Qt::AlignBottom | Qt::AlignRight);

    QHandle *_tmpHandlePtr = new QHandle(this,this);
    ui->verticalLayout_3->addWidget(_tmpHandlePtr);
    ui->verticalLayout->update();

    mParentView = view;
    mID = mIDcounter++;

    if(thisID == "") this->mName = "Node"+QString::number(mID);
    else this->mName = thisID;
    ui->lineEdit->setText(this->mName);

    if(myPos != nullptr) this->move(myPos->x(),myPos->y());

    QNodeCollector.insert(mID,this);
}

void QNodeWidget::addQConnection(qconnectorblob *newConn){
    if(newConn->mtype){
        mOutConnectors.push_back(newConn);
        ui->verticalLayout_2->insertWidget(1,newConn);
    }else{
        mInConnectors.push_back(newConn);
        ui->verticalLayout->insertWidget(1,newConn);
    }
}

void QNodeWidget::moveEvent(QMoveEvent *event){
    for(int i = 0; i < mInConnectors.size(); i++){
        mInConnectors[i]->moveEvent(event);
    }
    for(int i = 0; i < mOutConnectors.size(); i++){
        mOutConnectors[i]->moveEvent(event);
    }
}

QNodeWidget::~QNodeWidget()
{
    delete ui;
}

void QNodeWidget::updateIOText(){
    QString connectorsAsString;
    for(int i = 0; i < mInConnectors.size(); i++){
        connectorsAsString += mInConnectors[i]->getIDTuple() + ";";
    }
    ui->lineEdit_In->setText(connectorsAsString);

    connectorsAsString.clear();
    for(int i = 0; i < mOutConnectors.size(); i++){
        connectorsAsString += mOutConnectors[i]->getIDTuple() + ";";
    }
    ui->lineEdit_Out->setText(connectorsAsString);
}

void QNodeWidget::on_pushButton_pressed()
{
    qconnectorblob *newblob = new qconnectorblob(this,false,this);
    mInConnectors.push_back(newblob);
    ui->verticalLayout->insertWidget(1,newblob);
    updateIOText();
}

void QNodeWidget::on_pushButton_2_pressed()
{
    qconnectorblob *newblob = new qconnectorblob(this,true,this);
    mOutConnectors.push_back(newblob);
    ui->verticalLayout_2->insertWidget(1,newblob);
    updateIOText();
}

void QNodeWidget::on_pushButton_3_pressed()
{
    for(int i = mInConnectors.size()-1; i >= 0; i--){
        if(!(mInConnectors[i]->isChecked())){
            QWidget *tmp = mInConnectors[i];
            tmp->deleteLater();
            mInConnectors.removeAt(i);
        }
    }
    updateIOText();
}

void QNodeWidget::on_pushButton_4_pressed()
{
    for(int i = mOutConnectors.size()-1; i >= 0; i--){
        if(!(mOutConnectors[i]->isChecked())){
            QWidget *tmp = mOutConnectors[i];
            tmp->deleteLater();
            mOutConnectors.removeAt(i);
        }
    }
    updateIOText();
}

void QNodeWidget::on_pushButton_5_pressed()
{
    QNodeCollector.remove(mID);
    this->deleteLater();
}

QVector<qconnectorblob*> QNodeWidget::getConnectors(){
    QVector<qconnectorblob*> allConnections = mInConnectors;
    for(int i = 0; i < mOutConnectors.size(); i++) allConnections.append(mOutConnectors[i]);
    return allConnections;
}

void QNodeWidget::on_label_destroyed()
{

}

void QNodeWidget::on_lineEdit_textChanged(const QString &arg1)
{
    mName = arg1;
}
