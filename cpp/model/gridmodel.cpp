#include "gridmodel.h"
#include <QDebug>

GridModel::GridModel(QObject* parent, int width, int height) : QAbstractListModel(parent) {
    m_width = width;
    m_height = height;
    if(width > 0 && height > 0){
        m_model.resize(width*height);
    }
}

int GridModel::rowCount(const QModelIndex &parent) const
{
    return m_model.size();
}

QHash<int, QByteArray> GridModel::roleNames() const
{
    return {
            {TypeRole, "type"}
    };
}

QVariant GridModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "Called Index" << index.row();
    qDebug() << "Role" << role << "Type" << static_cast<int>(m_model[index.row()].type);
    if(!index.isValid()){
        return QVariant();
    }
    const Node &node = m_model[index.row()];
    if(role == TypeRole){
        qDebug() << "returning type" << static_cast<int>(node.type);
        return static_cast<int>(node.type);
    }
    return QVariant();
}

void GridModel::resizeModel(int width, int height)
{
    if(m_width == width && m_height == height) {
        return;
    }

    beginResetModel();

    m_width = width;
    m_height = height;
    m_model.clear();

    m_model.resize(width * height);

    endResetModel();
    emit dimensionsChanged();
}

int GridModel::width()
{
    return m_width;
}

int GridModel::height()
{
    return m_height;
}

std::vector<NodeType> GridModel::nodeTypes() const
{
    std::vector<NodeType> types;
    types.reserve(m_model.size());

    for(const Node& node: m_model)
    {
        types.push_back(node.type);
    }
    return types;
}

void GridModel::clearModel()
{
    for(int i = 0; i<m_model.size(); i++)
    {
        m_model[i].type = NodeType::Empty;
    }
    QModelIndex start = createIndex(0,0);
    QModelIndex end = createIndex(m_model.size() - 1, 0);
    emit dataChanged(start, end, {TypeRole});
}

void GridModel::setNodeType(const NodeType type, const int index)
{
    if(index < 0 || index > m_model.size() || m_model[index].type == type)
    {
        return;
    }
    Node& node = m_model[index];

    if(node.type == type)
        return;

    switch(type) {
    case NodeType::Visited:
        // dont override start/end
        if(node.type == NodeType::Start || node.type == NodeType::End)
            return;
        node.type = NodeType::Visited;
        break;

    case NodeType::Wall:
        // only empty cells could be walls
        if(node.type == NodeType::Empty)
            node.type = NodeType::Wall;
        break;

    case NodeType::Path:
        // dont override start/end
        if(node.type == NodeType::Start || node.type == NodeType::End)
            return;
        node.type = NodeType::Path;
        break;

    default:
        node.type = type;
        break;
    }
    qDebug() << "type now" << static_cast<int>(m_model[index].type) << "index" << index;
    QModelIndex modelIndex = createIndex(index, 0);
    emit dataChanged(modelIndex, modelIndex, {TypeRole});
    qDebug() << "type changed";

}

void GridModel::reconstructPath(const std::vector<int>& path)
{
    for( int index: path){
        setNodeType(NodeType::Path, index);
    }
}



