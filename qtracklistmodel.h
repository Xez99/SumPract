#ifndef QTRACKLISTMODEL_H
#define QTRACKLISTMODEL_H

#include "QAbstractListModel"
#include "track.h"

class QTrackListModel: public QAbstractListModel{
    Q_OBJECT
public:
    explicit QTrackListModel (QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    void itemInsert(Track track);

    QList<Track> list;
};

#endif // QTRACKLISTMODEL_H
