#ifndef QTEAMTREEMODEL_H
#define QTEAMTREEMODEL_H

#include <QAbstractItemModel>
#include "team.h"

class QTeamTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void teamInsert(Team team);

    void racerInsert(Team *team, Person *racer);


    QList<Team> list;

};

#endif // QTEAMTREEMODEL_H
