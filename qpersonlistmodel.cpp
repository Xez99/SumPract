#include "qpersonlistmodel.h"

QPersonListModel::QPersonListModel(QList<Team> *data, QObject *parent):
    QAbstractListModel(parent)
{
    for(auto it = data->begin(); it != data->end(); it++ ){
        for(auto itt = (*it).Racers.begin(); itt != (*it).Racers.end(); itt++ ){
            list << &(*itt);
        }
    }
}

int QPersonListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return list.count();
}

QVariant QPersonListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
         return list.at(index.row())->getFullName();
    default:

        return QVariant();
    }
}

Qt::ItemFlags QPersonListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int QPersonListModel::indexOf(Person *person)
{
    int cnt = -1;
    for(auto it = list.begin(); it != list.end(); it++, cnt++ ){
        if(person == (*it))
            break;
    }
    if(cnt >= list.size())
        return -1;
    return cnt+1;
}
