#include "qnodewidget.h"
#include "ui_qnodewidget.h"

QNodeWidget::QNodeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QNodeWidget)
{
    ui->setupUi(this);
}

void QNodeWidget::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
}

void QNodeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        this->move(mapToParent(event->pos() - offset));
    }
}

QNodeWidget::~QNodeWidget()
{
    delete ui;
}
