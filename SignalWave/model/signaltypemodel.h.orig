#ifndef SIGNALTYPEMODEL_H
#define SIGNALTYPEMODEL_H

#include <QAbstractListModel>

class SignalTypeModel  : public QAbstractListModel
{
    Q_OBJECT

    typedef QPair<QVariant, int> DataPair;
    QList< DataPair > m_content;

public:
    explicit SignalTypeModel(QObject *parent = 0);
    virtual QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    virtual int rowCount( const QModelIndex & parent = QModelIndex() ) const;
};

#endif // SIGNALTYPEMODEL_H
