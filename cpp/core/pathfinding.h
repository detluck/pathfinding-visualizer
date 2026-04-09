#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "cpp/algorithms/ialgorithm.h"
#include <QObject>
#include "cpp/model/gridmodel.h"
#include <QTimer>

class Pathfinding: public QObject
{
    Q_OBJECT
    Q_PROPERTY(ClickType type READ clickType WRITE setClickType NOTIFY clickTypeChanged)

public:
    enum class ClickType{
        Start,
        Pause,
        Resume,
        Stop,
        Clear,
        StartNode,
        TargetNode,
        Deleate,
        Wall,
        Count
    };
    Q_ENUM(ClickType)

public:
    explicit Pathfinding(QObject *parent = nullptr);

    Q_INVOKABLE void setAlgorithm(int index);
    Q_INVOKABLE void setStartIndex(const int index);
    Q_INVOKABLE void setEndIndex(const int index);
    Q_INVOKABLE void setWallIndex(const int index);
    Q_INVOKABLE void handleClick(const int index = -1);
    void clearGrid();
    ClickType clickType();
    void deleateitem(const int index);
    bool isValid(const int index);
    GridModel* gridModel();

public slots:
    void setClickType(Pathfinding::ClickType type);
    void startAlgorithm();
    void stopAlgorithm();
    void resumeAlgorithm();
    void setSpeed(const int speed);

signals:
    void clickTypeChanged();

private slots:
    void onStep();

private:
    GridData collectData();
    std::unique_ptr<IAlgorithm> m_algorithm;
    ClickType m_type;
    GridModel* m_model;
    int m_start;
    int m_end;
    bool paused = false;
    QTimer* timer;

signals:
    void finished();
};

#endif
