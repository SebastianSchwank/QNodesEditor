#ifndef QNODEWIDGET_H
#define QNODEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>

namespace Ui {
class QNodeWidget;
}

class QNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QNodeWidget(QWidget *parent = 0);
    ~QNodeWidget();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint offset;
    Ui::QNodeWidget *ui;
};

#endif // QNODEWIDGET_H
