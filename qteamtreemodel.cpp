#include "qteamtreemodel.h"

QModelIndex QTeamTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(column)

    if (!parent.isValid())
        return createIndex(row, 0, static_cast<quintptr>(0));

    return createIndex(row, 0, parent.row() + 1);
}

QModelIndex QTeamTreeModel::parent(const QModelIndex &child) const
{
    if (!child.isValid() || child.internalId() == 0)
        return QModelIndex();

    return createIndex(child.internalId() - 1, 0, static_cast<quintptr>(0));
}

int QTeamTreeModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return list.size();

    if (!parent.parent().isValid())
        return list.at(parent.row()).Racers.size();

    return 0;
}

int QTeamTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant QTeamTreeModel::data(const QModelIndex &index, int role) const
{
    QVariant ret;
    if (!index.isValid())
        return ret;

    switch (role) {
    case Qt::DisplayRole:
        if (index.parent().isValid())
            ret = list.at(index.internalId() - 1).Racers.at(index.row()).getFullName();
        else
            ret = list.at(index.row()).getName();
        break;

    default:
        break;
    }

    return ret;
}

void QTeamTreeModel::teamInsert(Team team)
{
    list << team;
}

void QTeamTreeModel::racerInsert(Team *team, Person *racer)
{
    team->addRacer(racer);
}
