#ifndef CREATIONMENU_H
#define CREATIONMENU_H

#include <QDialog>
#include "qteamtreemodel.h"
#include "qteamlistmodel.h"


namespace Ui {
class CreationMenu;
}

class CreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CreationMenu(QTeamTreeModel *model, int index = -1, QWidget *parent = 0);
    ~CreationMenu();


private slots:
    void on_saveRbutton_clicked();

    void on_saveTbutton_clicked();

    void on_cancelRButton_clicked();

    void on_cancelTButton_clicked();

private:
    QTeamTreeModel *model;
    int index;
    Ui::CreationMenu *ui;

};

#endif // CREATIONMENU_H
