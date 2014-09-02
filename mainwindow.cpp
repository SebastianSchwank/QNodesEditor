#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mNodeView = new QNodeView(ui->tabWidget);
    ui->NodeGraphicsView->addWidget(mNodeView);

    QNodeWidget *_widget = new QNodeWidget(mNodeView);
    QGraphicsScene scene;
    QGraphicsProxyWidget *proxy = scene.addWidget(_widget);

     mNodeView->setScene(&scene);
     mNodeView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
