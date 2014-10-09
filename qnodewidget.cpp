#include "qnodewidget.h"
#include "ui_qnodewidget.h"


unsigned int QNodeWidget::mIDcounter = 0;

QNodeWidget::QNodeWidget(QWidget *parent, QNodeView *view) :
    QWidget(parent),
    ui(new Ui::QNodeWidget)
{
    mParentView = view;
    ui->setupUi(this);
    QHandle *_tmpHandlePtr = new QHandle(this,this);
    ui->verticalLayout_3->addWidget(_tmpHandlePtr);
    ui->verticalLayout->update();

    mID = mIDcounter++;
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
    this->deleteLater();
}
