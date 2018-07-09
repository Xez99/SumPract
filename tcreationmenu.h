#ifndef TCREATIONMENU_H
#define TCREATIONMENU_H

#include <QDialog>
#include "qtracklistmodel.h"

namespace Ui {
class TCreationMenu;
}

class TCreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit TCreationMenu(QTrackListModel *model, int index = -1, QWidget *parent = 0);
    explicit TCreationMenu(QTrackListModel *model, const QModelIndex &index, QWidget *parent = 0);
    ~TCreationMenu();

private slots:


    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    //const QModelIndex index;
    int index;
    Ui::TCreationMenu *ui;
    QTrackListModel *model;

};

#endif // TCREATIONMENU_H
