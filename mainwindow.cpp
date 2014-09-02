#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QNodeWidget *_widget = new QNodeWidget(ui->graphicsView_2);
    QGraphicsScene scene;
    QGraphicsProxyWidget *proxy = scene.addWidget(_widget);

     ui->graphicsView_2->setScene(&scene);
     ui->graphicsView_2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
