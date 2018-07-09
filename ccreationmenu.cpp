#include "ccreationmenu.h"
#include "ui_ccreationmenu.h"

CCreationMenu::CCreationMenu(QCompetitionListModel *model, int index, QWidget *parent) :
    QDialog(parent),
    model(model),
    index(index),
    ui(new Ui::CCreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Создание события");
    ui->label_ReqName->hide();
}

CCreationMenu::CCreationMenu(QCompetitionListModel *model, const QModelIndex &index, QWidget *parent):
    QDialog(parent),
    model(model),
    index(index.row()),
    ui(new Ui::CCreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Редактирование события");
    ui->label_ReqName->hide();
    ui->lineEdit->setText(model->list.at(this->index).getName());
    ui->dateEdit->setDate(model->list.at(this->index).getDate());
    ui->timeEdit->setTime(model->list.at(this->index).getTime());
}

CCreationMenu::~CCreationMenu()
{
    delete ui;
}

void CCreationMenu::on_closeButton_clicked()
{
    close();
}

void CCreationMenu::on_saveButton_clicked()
{
    if(ui->lineEdit->text().simplified().isEmpty()){
        ui->label_noName->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        ui->label_ReqName->show();
    }
    else{
        ui->label_noName->setText("");
        ui->label_ReqName->hide();

        if(index == -1){
            Competition nc;
            nc.setName(ui->lineEdit->text().simplified());
            nc.setDate(ui->dateEdit->date());
            nc.setTime(ui->timeEdit->time());
            //nc.setDescription(descr);//ui->textEdit->toPlainText());
            model->itemInsert(nc);
        }
        else{
            model->list[index].setName(ui->lineEdit->text().simplified());
            model->list[index].setDate(ui->dateEdit->date());
            model->list[index].setTime(ui->timeEdit->time());
            //model->list[index].setDescription(descr);//ui->textEdit->toPlainText());
        }

        close();
    }
}
