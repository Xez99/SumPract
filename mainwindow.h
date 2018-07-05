#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "creationmenu.h"
#include "team.h"
#include "track.h"
#include "qtracklistmodel.h"
#include "QMessageBox"
#include "QDebug"
#include "QStringListModel"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addRbutton_clicked();

    void on_deliteRbutton_clicked();

    void on_editRbutton_clicked();

    void on_addTbutton_clicked();

    void on_editTbutton_clicked();

    void on_deleteTbutton_clicked();

    void on_TrackListView_clicked(const QModelIndex &index);

private:
    QTrackListModel *model;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
