#include "qteamlistmodel.h"

QTeamListModel::QTeamListModel(QList<Team> *data, QObject *parent):
    QAbstractListModel(parent),
    list(data)
{

}

int QTeamListModel::rowCount(const QModelIndex &parent) const
{
    return list->count();
}

QVariant QTeamListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
         return list->at(index.row()).getName();
    case Qt::StatusTipRole:
        return " Всего событий: " + QString::number(rowCount());
    default:

        return QVariant();
    }
}

Qt::ItemFlags QTeamListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
