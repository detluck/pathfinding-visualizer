#include "gridmodel.h"
#include <QDebug>

GridModel::GridModel(int width, int height) {
    m_width = width;
    m_height = height;
    m_model.resize(width * height);
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
    qDebug() << "Role" << role;
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
    m_model.resize(width*height);
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
    for(Node& node: m_model)
    {
        node.type = NodeType::Empty;
    }
}



