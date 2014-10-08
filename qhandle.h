#ifndef QHANDLE_H
#define QHANDLE_H

#include <QWidget>

#include "qnodewidget.h"

namespace Ui {
class QHandle;
}

class QNodeWidget;

class QHandle : public QWidget
{
    Q_OBJECT

public:
    explicit QHandle(QWidget *parent, QNodeWidget *Node = 0);
    ~QHandle();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::QHandle *ui;

    QNodeWidget *mNode;
};

#endif // QHANDLE_H
