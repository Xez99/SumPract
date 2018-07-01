#include "creationmenu.h"
#include "ui_creationmenu.h"
#include "QDebug"

CreationMenu::CreationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationMenu)
{
    ui->setupUi(this);
}

CreationMenu::~CreationMenu()
{
    qDebug() << "Creation menu closed normaly";
    delete ui;
}

