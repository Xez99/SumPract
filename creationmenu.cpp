#include "creationmenu.h"
#include "ui_creationmenu.h"
#include "QDebug"

CreationMenu::CreationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationMenu)
{
    ui->setupUi(this);
    ui->label_noFName->hide();
    ui->label_noName->hide();
    ui->label_noSName->hide();
    ui->label_noTeam->hide();
    ui->label_noTeamName->hide();
    ui->label_rReqField->hide();
    ui->label_tReqField->hide();
}

CreationMenu::~CreationMenu()
{
    qDebug() << "Creation menu closed normaly";
    delete ui;
}


void CreationMenu::on_saveRbutton_clicked()
{
    close();
}
