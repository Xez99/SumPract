 #include "tcreationmenu.h"
#include "ui_tcreationmenu.h"
#include "QDebug"

TCreationMenu::TCreationMenu(QTrackListModel *model, int index, QWidget *parent) :
    QDialog(parent),
    model(model),
    index(index),
    ui(new Ui::TCreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Создание трассы");
    ui->label_reqName->hide();
}

TCreationMenu::TCreationMenu(QTrackListModel *model, const QModelIndex &index, QWidget *parent) :
    QDialog(parent),
    model(model),
    index(index.row()),
    ui(new Ui::TCreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Редактирование трассы");
    ui->label_reqName->hide();
    ui->lineEdit->setText(model->list.at(index.row()).getName());
    ui->textEdit->setText(model->list.at(index.row()).getDescription());

    //Вставить призеров

}



TCreationMenu::~TCreationMenu()
{
    delete ui;
}



void TCreationMenu::on_cancelButton_clicked()
{
    close();
}

void TCreationMenu::on_saveButton_clicked()
{
    if(ui->lineEdit->text().simplified().isEmpty()){
        ui->label_noName->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        ui->label_reqName->show();
    }
    else{
        ui->label_noName->setText("");
        ui->label_reqName->hide();

        QString descr = ui->textEdit->toPlainText().simplified();//.simplified();//.replace("\n", "<br>");
        //qDebug() << descr;
        if(index == -1){
            Track nt;
            nt.setName(ui->lineEdit->text().simplified());
            nt.setDescription(descr);//ui->textEdit->toPlainText());
            model->itemInsert(nt);
        }
        else{
            model->list[index].setName(ui->lineEdit->text().simplified());
            model->list[index].setDescription(descr);//ui->textEdit->toPlainText());
        }


        close();
    }

}
