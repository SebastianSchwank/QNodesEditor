#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mScene = new QGraphicsScene(this);
    mNodeView = new QNodeView(ui->tabWidget);
    ui->NodeGraphicsView->addWidget(mNodeView);

    mNodeView->setScene(mScene);
    mNodeView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTextNode_triggered()
{
    QNodeWidget *_nodeWidget = new QNodeWidget(NULL,mNodeView);

    mScene->addWidget(_nodeWidget);

    mNodeView->show();
}

void MainWindow::on_actionTextNode_changed()
{

}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    //if(index == 1) qDebug("TextTab clicked.");
}

void MainWindow::on_pushButton_clicked()
{
    //Generate XML from the Model

}
