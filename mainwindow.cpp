#include "mainwindow.h"
#include "QFile"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trackModel = new QTrackListModel;
    competModel = new QCompetitionListModel;
    teamModel = new QTeamTreeModel;

    ui->TeamTreeView->setModel(teamModel);
    ui->TrackListView->setModel(trackModel);
    ui->CompetitionListView->setModel(competModel);

    Team test;
    test.setName("Команда 1");
    Person one(&test);
    one.setSecondName("Eba");
    one.setName(" eto");
    one.setFatherName("ti?");
    Person two(&test);
    two.setSecondName("2");
    Person three(&test);
    three.setSecondName("3");
    Person four(&test);
    four.setSecondName("4");

    test.addRacer(&one);
    test.addRacer(&two);
    test.addRacer(&three);
    test.addRacer(&four);


    teamModel->list << test;
    Team test1;
    test1.setName("Команда 2");
    teamModel->list << test1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addRbutton_clicked()
{
    setDisabled(true);

    CreationMenu cm(teamModel);
    cm.show();
    cm.exec();

    ui->TeamTreeView->reset();
    setDisabled(false);

}

void MainWindow::on_deliteRbutton_clicked()
{
    setDisabled(true);
    QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Вы уверены, что хотите удалить?", QMessageBox::Yes | QMessageBox::No);

    if(decision == QMessageBox::Yes){
        if(ui->TeamTreeView->currentIndex().row() != -1){
            if(ui->TeamTreeView->currentIndex().parent().row() == -1){
                teamModel->list.removeAt(ui->TeamTreeView->currentIndex().row());
            }
            else{
                teamModel->list[ui->TeamTreeView->currentIndex().parent().row()].removeRacer(ui->TeamTreeView->currentIndex().row());
            }
        }
        ui->TeamTreeView->reset();


        //Удалить текущий элемент

    }else{

    }
    setDisabled(false);
    ui->textBrowser->setText("");
}

void MainWindow::on_editRbutton_clicked()
{
    qDebug() << ui->TeamTreeView->currentIndex().parent().row() << ui->TeamTreeView->currentIndex().row();
    //ui->TeamTreeView->currentIndex().parent();



    setDisabled(true);

    setDisabled(false);
    ui->textBrowser->setText("");
}

void MainWindow::on_addTbutton_clicked()
{
    ui->editTbutton->setEnabled(false);
    ui->deleteTbutton->setEnabled(false);  
    setDisabled(true);

    //setWindowModified(true);

    TCreationMenu tcm(trackModel);// tcm(ui->TrackListView->currentIndex());
    tcm.show();
    tcm.exec();

    setDisabled(false);
    ui->trackDescription->setText("");
    ui->TrackListView->reset();
}

void MainWindow::on_editTbutton_clicked()
{
    setDisabled(true);

    ui->editTbutton->setEnabled(false);
    ui->deleteTbutton->setEnabled(false);
    TCreationMenu teditm(trackModel, ui->TrackListView->currentIndex());
    teditm.show();
    teditm.exec();

    setDisabled(false);
    ui->trackDescription->setText("");
    ui->TrackListView->reset();
}

void MainWindow::on_deleteTbutton_clicked()
{
    setDisabled(true);
    QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Вы уверены, что хотите удалить данные о трассе?", QMessageBox::Yes | QMessageBox::No);

    ui->editTbutton->setEnabled(false);
    ui->deleteTbutton->setEnabled(false);

    if(decision == QMessageBox::Yes){
        if(ui->TrackListView->currentIndex().row() != -1){
            trackModel->list.removeAt(ui->TrackListView->currentIndex().row());
            ui->TrackListView->reset();
        }

    }
    setDisabled(false);
    ui->trackDescription->setText("");
}

void MainWindow::on_TrackListView_clicked(const QModelIndex &index)
{
    ui->editTbutton->setEnabled(true);
    ui->deleteTbutton->setEnabled(true);
    setDisabled(true);

    Track current = trackModel->list.at(index.row());

    QString QScurrent = "<b>Название: \n</b> "+ current.getName() + "<br><br><b>Описание:</b> " + current.getDescription();
    /*if(current.getGoldP())
        QScurrent = QScurrent + "<br><br><b>Первое место: </b>" + current.getGoldP()->getSecondName() + ' ' +
                current.getGoldP()->getName() + ' ' + current.getGoldP()->getFarherName() + " \"";// + current.getGoldP()->getTeam()->getName() + "\"";

*/
    setDisabled(false);
    ui->trackDescription->setText(QScurrent);
}

void MainWindow::on_CompetitionListView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index);

    ui->editCButton->setEnabled(true);
    ui->deleteCButton->setEnabled(true);
}

void MainWindow::on_addCButton_clicked()
{
    ui->editCButton->setEnabled(false);
    ui->deleteCButton->setEnabled(false);
    setDisabled(true);

    CCreationMenu ccm(competModel);
    ccm.show();
    ccm.exec();

    setDisabled(false);
    ui->CompetitionListView->reset();
}

void MainWindow::on_editCButton_clicked()
{
    ui->editCButton->setEnabled(false);
    ui->deleteCButton->setEnabled(false);
    setDisabled(true);

    CCreationMenu ceditm(competModel, ui->CompetitionListView->currentIndex());
    ceditm.show();
    ceditm.exec();

    setDisabled(false);
    ui->CompetitionListView->reset();
}

void MainWindow::on_deleteCButton_clicked()
{
    setDisabled(true);
    QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Вы уверены, что хотите удалить данные о событии?", QMessageBox::Yes | QMessageBox::No);

    ui->editCButton->setEnabled(false);
    ui->deleteCButton->setEnabled(false);

    if(decision == QMessageBox::Yes){
        if(ui->CompetitionListView->currentIndex().row() != -1)
            competModel->list.removeAt(ui->CompetitionListView->currentIndex().row());
    }
    setDisabled(false);
    ui->CompetitionListView->reset();
}

void MainWindow::on_NewBase_triggered()
{
    setWindowModified(true);
    if(isWindowModified()){
        setDisabled(true);
        QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Имеются несохраненные данные. Продолжить?", QMessageBox::Yes | QMessageBox::No);

        ui->editCButton->setEnabled(false);
        ui->deleteCButton->setEnabled(false);

        if(decision == QMessageBox::Yes){
            //Очистить базу
            }


        setDisabled(false);
    }

}

void MainWindow::on_OpenBase_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.dat");
}

void MainWindow::on_Save_triggered()
{

}

void MainWindow::on_SaveAs_triggered()
{
    QString str = QFileDialog::getSaveFileName(0, "", "", "*.dat");
}



void MainWindow::on_TeamTreeView_clicked(const QModelIndex &index)
{
    if(ui->TeamTreeView->currentIndex().parent().row() != -1){
        Person cur = teamModel->list.at(ui->TeamTreeView->currentIndex().parent().row()).Racers.at(ui->TeamTreeView->currentIndex().row());
        QString current;
        //qDebug() << cur.getTeam()->getName();
        current = "<b>Фамилия: </b>" + cur.getSecondName() + "<br><b>Имя: </b>" + cur.getName() + "<br><b>Отчество: </b>" +
                cur.getFarherName() + "<br><b>Дата рождения: </b>" + cur.getBirthDate().toString("dd.MM.yyyy") + "<br><b>Очков: </b>" +
                QString::number(cur.getPoints()) + "<br><b>Команда: \"</b>";// + cur.getTeam()->getName() + "\"";
        if(cur.getTeam())
            //current += cur.getTeam()->getName();
        ui->textBrowser->setText(current);
    }

}
