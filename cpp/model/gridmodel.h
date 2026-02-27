#ifndef GRIDMODEL_H
#define GRIDMODEL_H
#include <QAbstractListModel>
#include <QVector>
#include <QHash>
#include <QByteArray>
#include <QModelIndex>
#include <QVariant>
#include "node.h"

class GridModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        TypeRole = Qt::UserRole + 1,
        DistanceRole,
        VisitedRole,
        IsWallRole,
        IsPathRole
    };

    GridModel(int width, int height);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QVector<Node> m_model;
    int m_width;
    int m_height;
};

#endif // GRIDMODEL_H
