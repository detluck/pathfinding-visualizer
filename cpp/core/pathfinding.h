#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "cpp/algorithms/ialgorithm.h"
#include <QObject>
#include "cpp/model/gridmodel.h"

class Pathfinding: public QObject
{
    Q_OBJECT

    enum class ClickType{
        Start,
        Pause,
        Resume,
        Stop,
        Clear,
        StartNode,
        TargetNode,
        Wall,
        Deleate,
        Count
    };
    Q_ENUM(ClickType)

    Q_PROPERTY(ClickType clickType READ clickType WRITE setClickType NOTIFY clickTypeChanged FINAL)

public:
    explicit Pathfinding(QObject *parent = nullptr);

    Q_INVOKABLE void setAlgorithm(int index);

    ClickType clickType();
    void setClickType(ClickType type);
    void setStartIndex(int index);
    void setEndIndex(int index);
    void setWallIndex(int index);
    void startAlgorithm();

private slots:
    void handleClick();

signals:
    void clickTypeChanged();

private:
    GridData collectData();
    std::unique_ptr<IAlgorithm> m_algorithm;
    ClickType m_type = ClickType::Wall;
    GridModel* m_model;
    int m_start;
    int m_end;
};

#endif
