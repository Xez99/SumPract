#ifndef CREATIONMENU_H
#define CREATIONMENU_H

#include <QDialog>

namespace Ui {
class CreationMenu;
}

class CreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CreationMenu(QWidget *parent = 0);
    ~CreationMenu();


private:
    Ui::CreationMenu *ui;
};

#endif // CREATIONMENU_H
