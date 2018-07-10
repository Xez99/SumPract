#include "tcreationmenu.h"
#include "ui_tcreationmenu.h"

TCreationMenu::TCreationMenu(QTrackListModel *model, QTeamTreeModel *teamModel, int index, QWidget *parent) :
    QDialog(parent),
    model(model),
    index(index),
    ui(new Ui::TCreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Добавление трассы");
    ui->label_reqName->hide();

    perModel = new QPersonListModel(&(teamModel->list));
    ui->comboBox_g->setModel(perModel);
    ui->comboBox_s->setModel(perModel);
    ui->comboBox_b->setModel(perModel);
}

TCreationMenu::TCreationMenu(QTrackListModel *model, QTeamTreeModel *teamModel, const QModelIndex &index, QWidget *parent) :
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

    perModel = new QPersonListModel(&(teamModel)->list);

    ui->comboBox_g->setModel(perModel);
    ui->comboBox_s->setModel(perModel);
    ui->comboBox_b->setModel(perModel);

    ui->comboBox_g->setCurrentIndex(perModel->indexOf(model->list.at(index.row()).getGoldP()));
    ui->comboBox_s->setCurrentIndex(perModel->indexOf(model->list.at(index.row()).getSilvP()));
    ui->comboBox_b->setCurrentIndex(perModel->indexOf(model->list.at(index.row()).getBronP()));
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
        if(index == -1){
            Track nt;
            nt.setName(ui->lineEdit->text().simplified());
            nt.setDescription(descr);
            nt.setGoldP(perModel->list.at(ui->comboBox_g->currentIndex()));
            nt.setSilvP(perModel->list.at(ui->comboBox_s->currentIndex()));
            nt.setBronP(perModel->list.at(ui->comboBox_b->currentIndex()));
            model->itemInsert(nt);
        }
        else{
            model->list[index].setName(ui->lineEdit->text().simplified());
            model->list[index].setDescription(descr);
            model->list[index].setGoldP(perModel->list.at(ui->comboBox_g->currentIndex()));
            model->list[index].setSilvP(perModel->list.at(ui->comboBox_s->currentIndex()));
            model->list[index].setBronP(perModel->list.at(ui->comboBox_b->currentIndex()));
        }


        close();
    }

}
