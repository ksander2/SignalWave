#include "signaltypemodel.h"

SignalTypeModel::SignalTypeModel(QObject *parent) : QAbstractListModel(parent)
{
    m_content   << qMakePair( DataPair::first_type( "Sine" ), DataPair::second_type( 0 ) )
                << qMakePair( DataPair::first_type( "Square" ), DataPair::second_type( 1 ) )
                << qMakePair( DataPair::first_type( "saw" ), DataPair::second_type( 2 ) )
                << qMakePair( DataPair::first_type( "triangle" ), DataPair::second_type( 3 ) );
}

QVariant SignalTypeModel::data( const QModelIndex &index, int role ) const
{
    const DataPair& data = m_content.at( index.row() );
        QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole:
            {
                value = data.first;
            }
            break;

            case Qt::UserRole:
            {
                value = data.second;
            }
            break;

            default:
                break;
        }

        return value;
}

int SignalTypeModel::rowCount(const QModelIndex &/*parent*/) const
{
    return m_content.count();
}
