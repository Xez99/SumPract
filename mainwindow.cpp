#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QTrackListModel();

    ui->TrackListView->setModel(model);
    Track test;
    test.setName("Hui sosi guboi");
    test.setDescription("ya eby sobak");
    model->list << test;
    //ui->trackDescription->insertPlainText(model->list.at(ui->TrackListView->currentIndex().row()).getDescription());

    //ui->statusBar->showMessage(" Всего трасс: " + QString::number(model->rowCount()));

    //connect(ui->addTbutton, SIGNAL(clicked()), this, SLOT(on_addTbutton_clicked()));
    //connect(ui->editTbutton, SIGNAL(clicked()), this, SLOT(on_editTbutton_clicked()));
    //connect(ui->deleteTbutton, SIGNAL(clicked()), this, SLOT(on_deleteTbutton_clicked()));

}

MainWindow::~MainWindow()
{
    qDebug() << "Main Window closed normaly";
    delete ui;
}

void MainWindow::on_addRbutton_clicked()
{
    // Вставить try-catch для получения данных
    setDisabled(true);
    ui->label->setText("Clicked");
    CreationMenu cm;
    cm.show();
    cm.exec();
    setDisabled(false);

}

void MainWindow::on_deliteRbutton_clicked()
{
    QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Вы уверены, что хотите удалить?", QMessageBox::Yes | QMessageBox::No);

    if(decision == QMessageBox::Yes){

        //Удалить текущий элемент

    }else{

    }
}

void MainWindow::on_editRbutton_clicked()
{

}

void MainWindow::on_addTbutton_clicked()
{
    ui->editTbutton->setEnabled(false);
    ui->deleteTbutton->setEnabled(false);

    Track a;
    a.setName("Arab");
    a.setDescription("Allahu akbar");
    model->itemInsert(a);
    ui->TrackListView->reset();
}

void MainWindow::on_editTbutton_clicked()
{

    if(ui->tab->isTopLevel())
        qDebug() << "tab current";
}

void MainWindow::on_deleteTbutton_clicked()
{
    QMessageBox::StandardButton decision = QMessageBox::question(this, "Title", "Вы уверены, что хотите удалить данные о трассе?", QMessageBox::Yes | QMessageBox::No);

    if(decision == QMessageBox::Yes){

        ui->editTbutton->setEnabled(false);
        ui->deleteTbutton->setEnabled(false);

        if(ui->TrackListView->currentIndex().row() != -1){
            model->list.removeAt(ui->TrackListView->currentIndex().row());
            ui->TrackListView->reset();
            qDebug() << model->list.count();
        }

    }

}

void MainWindow::on_TrackListView_clicked(const QModelIndex &index)
{
    ui->editTbutton->setEnabled(true);
    ui->deleteTbutton->setEnabled(true);

    Track current = model->list.at(index.row());

    QString QScurrent = "<b>Название: \n</b> "+ current.getName() + "<br><br><b>Описание:</b> " + current.getDescription();
    /*if(current.getGoldP())
        QScurrent = QScurrent + "<br><br><b>Первое место: </b>" + current.getGoldP()->getSecondName() + ' ' +
                current.getGoldP()->getName() + ' ' + current.getGoldP()->getFarherName() + " \"";// + current.getGoldP()->getTeam()->getName() + "\"";

*/
    ui->trackDescription->setText(QScurrent);
}

