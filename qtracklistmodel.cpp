#include "qtracklistmodel.h"

QTrackListModel::QTrackListModel(QObject *parent): QAbstractListModel(parent){
}

int QTrackListModel::rowCount(const QModelIndex &parent) const
{
    return list.count();
}

QVariant QTrackListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:{
        Track temp = list.at(index.row());
        return temp.getName();
    }
    case Qt::StatusTipRole:
        return " Всего трасс: " + QString::number(rowCount());
    default:

        return QVariant();
    }
}

Qt::ItemFlags QTrackListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void QTrackListModel::itemInsert(Track track)
{
    list << track;
}
