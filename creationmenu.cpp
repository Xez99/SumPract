#include "creationmenu.h"
#include "ui_creationmenu.h"

CreationMenu::CreationMenu(QTeamTreeModel *model, int pindex, int index, QWidget *parent) :
    QDialog(parent),
    model(model),
    pindex(pindex),
    index(index),
    ui(new Ui::CreationMenu)
{
    ui->setupUi(this);
    ui->label_rReqField->hide();
    ui->label_tReqField->hide();

    QTeamListModel *teamModel = new QTeamListModel(&(model->list));
    ui->comboBox->setModel(teamModel);
}

CreationMenu::CreationMenu(QTeamTreeModel *model, const QModelIndex &index, QWidget *parent):
    QDialog(parent),
    model(model),
    pindex(index.parent().row()),
    index(index.row()),
    ui(new Ui::CreationMenu)
{
    ui->setupUi(this);
    setWindowTitle("Редактирование");

    QTeamListModel *teamModel = new QTeamListModel(&(model->list));
    ui->comboBox->setModel(teamModel);

    ui->label_rReqField->hide();
    ui->label_tReqField->hide();
    if(pindex == -1){
        ui->tabWidget->removeTab(0);
        ui->lineEdit_tName->setText(model->list.at(this->index).getName());
    }
    else{
        ui->tabWidget->removeTab(1);
        ui->lineEdit_name->setText(model->list.at(pindex).Racers.at(this->index).getName());
        ui->lineEdit_sName->setText(model->list.at(pindex).Racers.at(this->index).getSecondName());
        ui->lineEdit_fName->setText(model->list.at(pindex).Racers.at(this->index).getFarherName());
        ui->comboBox->setCurrentIndex(pindex);
        ui->dateEdit->setDate(model->list.at(pindex).Racers.at(this->index).getBirthDate());
        ui->spinBox_Points->setValue(model->list.at(pindex).Racers.at(this->index).getPoints());
    }
}

CreationMenu::~CreationMenu()
{
    delete ui;
}

void CreationMenu::on_saveRbutton_clicked()
{
    bool flag = false;

    if(ui->comboBox->currentIndex() == -1){
        ui->label_noTeam->setText("<html><head/><body><p><span style=\" color:#ff3c4d;\">*</span></p></body></html>");
        flag = true;
    }
    else
        ui->label_noTeam->setText("");

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
        if(pindex == ui->comboBox->currentIndex()){
            model->list[pindex].Racers[index].setName(ui->lineEdit_name->text().simplified());
            model->list[pindex].Racers[index].setSecondName(ui->lineEdit_sName->text().simplified());
            model->list[pindex].Racers[index].setFatherName(ui->lineEdit_fName->text().simplified());
            model->list[pindex].Racers[index].setBirthDate(ui->dateEdit->date());
            model->list[pindex].Racers[index].setPoints(ui->spinBox_Points->value());
        }
        else{
            if(index != -1 && pindex != -1)
                model->list[pindex].removeRacer(index);
            Person np;
            np.setTeam(&(model->list[ui->comboBox->currentIndex()]));
            np.setName(ui->lineEdit_name->text().simplified());
            np.setSecondName(ui->lineEdit_sName->text().simplified());
            np.setFatherName(ui->lineEdit_fName->text().simplified());
            np.setBirthDate(ui->dateEdit->date());
            np.setPoints(ui->spinBox_Points->value());
            model->racerInsert(np.getTeam(), &np);
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

        if(index == -1){
            Team nt;
            nt.setName(ui->lineEdit_tName->text().simplified());
            model->list << nt;
        }
        else
            model->list[index].setName(ui->lineEdit_tName->text().simplified());

        close();
    }
}

void CreationMenu::on_cancelRButton_clicked()
{
    close();
}

void CreationMenu::on_cancelTButton_clicked()
{
    close();
}
