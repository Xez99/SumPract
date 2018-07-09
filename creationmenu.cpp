#include "creationmenu.h"
#include "ui_creationmenu.h"
#include "QDebug"

CreationMenu::CreationMenu(QTeamTreeModel *model, int index, QWidget *parent) :
    QDialog(parent),
    model(model),
    index(index),
    ui(new Ui::CreationMenu)
{
    ui->setupUi(this);
    QTeamListModel *teamModel = new QTeamListModel(&(model->list));
    ui->comboBox->setModel(teamModel);
    //ui->comboBox->setModel(model);
    //ui->tabWidget->removeTab(0);
    ui->label_rReqField->hide();
    ui->label_tReqField->hide();
}

CreationMenu::~CreationMenu()
{
    delete ui;
}


void CreationMenu::on_saveRbutton_clicked()
{
    bool flag = false;

    /*if(ui->comboBox->currentIndex() == -1){
        ui->label_noTeam->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        flag = true;
    }
    else
        ui->label_noTeam->setText("");*/

    if(ui->lineEdit_name->text().simplified().isEmpty()){
        ui->label_noName->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        flag = true;
    }
    else
        ui->label_noName->setText("");

    if(ui->lineEdit_sName->text().simplified().isEmpty()){
        ui->label_noSName->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        flag = true;
    }
    else
        ui->label_noSName->setText("");

    if(flag)
        ui->label_rReqField->show();
    else{
        if(index == -1){
            Person np;
            np.setTeam(&(model->list[ui->comboBox->currentIndex()]));
            np.setName(ui->lineEdit_name->text());
            np.setSecondName(ui->lineEdit_sName->text());
            np.setFatherName(ui->lineEdit_fName->text());
            np.setBirthDate(ui->dateEdit->date());
            np.setPoints(ui->spinBox_Points->value());
            model->racerInsert( np.getTeam() , &np);
        }
        close();
    }
}

void CreationMenu::on_saveTbutton_clicked()
{
    if(ui->lineEdit_tName->text().simplified().isEmpty()){
        ui->label_noTeamName->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        ui->label_tReqField->show();
    }
    else{
        ui->label_noTeamName->setText("");
        ui->label_tReqField->hide();
        Team nt;
        nt.setName(ui->lineEdit_tName->text().simplified());
        if(index == -1){
            model->list << nt;
        }
        close();
    }
    //close();
}

void CreationMenu::on_cancelRButton_clicked()
{
    close();
}

void CreationMenu::on_cancelTButton_clicked()
{
    close();
}
