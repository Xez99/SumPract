#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QDebug"
#include "QStringListModel"
#include "ui_mainwindow.h"

#include "creationmenu.h"
#include "tcreationmenu.h"
#include "ccreationmenu.h"
#include "qteamtreemodel.h"
#include "qtracklistmodel.h"
#include "qcompetitionlistmodel.h"
#include "team.h"
#include "track.h"

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

    void on_addCButton_clicked();

    void on_CompetitionListView_clicked(const QModelIndex &index);

    void on_editCButton_clicked();

    void on_deleteCButton_clicked();

    void on_OpenBase_triggered();

    void on_Save_triggered();

    void on_SaveAs_triggered();

    void on_NewBase_triggered();

    void on_TeamTreeView_clicked(const QModelIndex &index);

private:
    QTrackListModel *trackModel;
    QCompetitionListModel *competModel;
    QTeamTreeModel *teamModel;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
