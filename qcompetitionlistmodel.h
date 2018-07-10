#ifndef QCOMPETITIONLISTMODEL_H
#define QCOMPETITIONLISTMODEL_H

#include "competition.h"
#include "QAbstractListModel"

class QCompetitionListModel: public QAbstractListModel
{
public:
    explicit QCompetitionListModel (QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    void itemInsert(Competition competition);

    QList<Competition> list;
};

#endif // QCOMPETITIONLISTMODEL_H
