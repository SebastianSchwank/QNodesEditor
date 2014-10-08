#include "qhandle.h"
#include "ui_qhandle.h"

QHandle::QHandle(QWidget *parent, QNodeWidget *Node) :
    QWidget(parent),
    ui(new Ui::QHandle)
{
    mNode = Node;
    ui->setupUi(this);
}

void QHandle::mousePressEvent(QMouseEvent *event)
{
    mNode->offset = event->pos();
}

void QHandle::mouseMoveEvent(QMouseEvent *event)
{

    if(event->buttons() & Qt::LeftButton)
    {
        mNode->move(mNode->mapToParent(event->pos() - mNode->offset));
    }
}

QHandle::~QHandle()
{
    delete ui;
}
