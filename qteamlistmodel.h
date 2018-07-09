#ifndef QTEAMLISTMODEL_H
#define QTEAMLISTMODEL_H

#include "QAbstractListModel"
//#include "qteamtreemodel.h"
#include "QList"
#include "team.h"

class QTeamListModel: public QAbstractListModel
{
public:
    explicit QTeamListModel (QList<Team> *data, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

//private:
    QList<Team> *list;
};

#endif // QTEAMLISTMODEL_H
