#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "qnodewidget.h"
#include "qnodeview.h"
#include "qxmlwriter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionTextNode_triggered();

    void on_actionTextNode_changed();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_clicked();

private:
    QGraphicsScene *mScene;
    Ui::MainWindow *ui;
    QNodeView      *mNodeView;

};

#endif // MAINWINDOW_H
