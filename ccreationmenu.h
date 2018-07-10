#ifndef CCREATIONMENU_H
#define CCREATIONMENU_H

#include <QDialog>
#include "competition.h"
#include "qcompetitionlistmodel.h"

namespace Ui {
class CCreationMenu;
}

class CCreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CCreationMenu(QCompetitionListModel *model, int index = -1, QWidget *parent = 0);
    explicit CCreationMenu(QCompetitionListModel *model, const QModelIndex &index , QWidget *parent = 0);
    ~CCreationMenu();

private slots:
    void on_saveButton_clicked();

    void on_closeButton_clicked();

private:
    QCompetitionListModel *model;
    int index;
    Ui::CCreationMenu *ui;
};

#endif // CCREATIONMENU_H
