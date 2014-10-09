#ifndef QNODEWIDGET_H
#define QNODEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>

#include "qhandle.h"
#include "qconnectorblob.h"
#include "qnodeview.h"

class qconnectorblob;
class QNodeView;

namespace Ui {
class QNodeWidget;
}

class QNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QNodeWidget(QWidget *parent = 0, QNodeView *view = 0);
    ~QNodeWidget();

    QPoint offset;
    static unsigned int mIDcounter;
    unsigned int mID;

    void moveEvent(QMoveEvent *event);
    void addQConnection(qconnectorblob *newConn);

    void updateIOText();

    QNodeView *mParentView;

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

private:
    QVector<qconnectorblob*> mInConnectors;
    QVector<qconnectorblob*> mOutConnectors;

    Ui::QNodeWidget *ui;
};

#endif // QNODEWIDGET_H
