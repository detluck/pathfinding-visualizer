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
    Q_PROPERTY(int width READ width NOTIFY dimensionsChanged)
    Q_PROPERTY(int height READ height NOTIFY dimensionsChanged)
public:

    enum Roles{
        TypeRole = Qt::UserRole + 1,
        WeightRole
    };

    explicit GridModel(QObject* parent = nullptr, int width = 0, int height = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    std::vector<NodeType> nodeTypes() const;

    std::vector<Node> getNodes() const;

    void clearModel();

    void setNodeType(const NodeType type, const int index, const int weight = 0);
    
    void reconstructPath(const std::vector<int>& path);
public slots:
    Q_INVOKABLE void resizeModel(int width, int height);
    int width();
    int height();

signals:
    void dimensionsChanged();

private:
    QVector<Node> m_model;
    int m_width;
    int m_height;
};

#endif // GRIDMODEL_H
