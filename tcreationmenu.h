#ifndef TCREATIONMENU_H
#define TCREATIONMENU_H

#include <QDialog>
#include "qtracklistmodel.h"
#include "qpersonlistmodel.h"
#include "qteamtreemodel.h"

namespace Ui {
class TCreationMenu;
}

class TCreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit TCreationMenu(QTrackListModel *model, QTeamTreeModel *teamModel, int index = -1, QWidget *parent = 0);
    explicit TCreationMenu(QTrackListModel *model, QTeamTreeModel *teamModel, const QModelIndex &index, QWidget *parent = 0);
    ~TCreationMenu();

private slots:


    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    QTrackListModel *model;
    QPersonListModel *perModel;
    int index;
    Ui::TCreationMenu *ui;


};

#endif // TCREATIONMENU_H
