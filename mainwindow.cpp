#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creationmenu.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Clicked");
    //qDebug() << "Delited";

    CreationMenu cm;// = new CreationMenu;
    cm.show();
    cm.exec();

}
