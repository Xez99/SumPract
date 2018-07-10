#ifndef QPERSONLISTMODEL_H
#define QPERSONLISTMODEL_H

#include "QAbstractListModel"
#include "team.h"

class QPersonListModel: public QAbstractListModel
{
public:
    QPersonListModel (QList<Team> *data, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    int indexOf(Person *person);

    QList<Person*> list;
};

#endif // QPERSONLISTMODEL_H
