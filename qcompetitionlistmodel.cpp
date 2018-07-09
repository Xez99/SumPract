#include "qcompetitionlistmodel.h"

QCompetitionListModel::QCompetitionListModel(QObject *parent): QAbstractListModel(parent){

}

int QCompetitionListModel::rowCount(const QModelIndex &parent) const
{
    return list.count();
}

QVariant QCompetitionListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
         return list.at(index.row()).getDate().toString(" dd.MM.yy  | ")
                 + list.at(index.row()).getTime().toString("  HH:mm   | ")+ list.at(index.row()).getName();
    case Qt::StatusTipRole:
        return " Всего событий: " + QString::number(rowCount());
    default:

        return QVariant();
    }
}

Qt::ItemFlags QCompetitionListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void QCompetitionListModel::itemInsert(Competition competition)
{
    list << competition;
}
