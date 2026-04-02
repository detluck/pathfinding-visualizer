#ifndef GRIDMODEL_H
#define GRIDMODEL_H
#include <QAbstractListModel>
#include <QVector>
#include <QHash>
#include <QByteArray>
#include <QModelIndex>
#include <QVariant>
#include "node.h"
#include <vector>

class GridModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        TypeRole = Qt::UserRole + 1
    };

    explicit GridModel(QObject* parent = nullptr, int width = 50, int height = 50);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void resizeModel(int width, int height);
    int width();
    int height();
    std::vector<NodeType> nodeTypes() const;
    void clearModel();
    void setNodeType(const NodeType type, const int index);
    void reconstructPath(const std::vector<int>& path);

private:
    QVector<Node> m_model;
    int m_width;
    int m_height;
};

#endif // GRIDMODEL_H
