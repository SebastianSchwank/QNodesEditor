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

QNodeWidget::~QNodeWidget()
{
    delete ui;
}

void QNodeWidget::on_pushButton_pressed()
{
    qconnectorblob *newblob = new qconnectorblob(this,false,this);
    mInConnectors.push_back(newblob);
    ui->verticalLayout->insertWidget(1,newblob);
}

void QNodeWidget::on_pushButton_2_pressed()
{
    qconnectorblob *newblob = new qconnectorblob(this,true,this);
    mOutConnectors.push_back(newblob);
    ui->verticalLayout_2->insertWidget(1,newblob);
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
}

void QNodeWidget::on_pushButton_5_pressed()
{
    this->deleteLater();
}
