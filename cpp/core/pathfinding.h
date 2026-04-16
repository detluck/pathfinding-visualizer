#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "cpp/algorithms/ialgorithm.h"
#include <QObject>
#include "cpp/model/gridmodel.h"
#include <QTimer>
#include<QVariantList>
#include<QSettings>

class Pathfinding: public QObject
{
    Q_OBJECT
    Q_PROPERTY(ClickType type READ clickType WRITE setClickType NOTIFY clickTypeChanged)
    Q_PROPERTY(QVariantList availableWeights READ availableWeights WRITE setAvailableWeights NOTIFY availableWeightsChanged)
    Q_PROPERTY(int currentWeight READ currentWeight WRITE setCurrentWeight NOTIFY currentWeightChanged)
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
        WeightNode,
        Count
    };
    Q_ENUM(ClickType)

public:
    explicit Pathfinding(QObject *parent = nullptr);

    Q_INVOKABLE void setAlgorithm(int index);
    void setStartIndex(const int index);
    void setEndIndex(const int index);
    void setWeightNode(const int index, const int weight);
    void setWallIndex(const int index);
    Q_INVOKABLE void handleClick(const int index = -1);
    Q_INVOKABLE void addWeight(const int weight);
    void clearGrid();
    ClickType clickType();
    void deleateitem(const int index);
    bool isValid(const int index);
    GridModel* gridModel();
    QVariantList availableWeights();
    int currentWeight();

public slots:
    void setClickType(Pathfinding::ClickType type);
    void startAlgorithm();
    void stopAlgorithm();
    void resumeAlgorithm();
    void setSpeed(const int speed);
    void setAvailableWeights(const QVariantList list);
    void setCurrentWeight(const int weight);

signals:
    void clickTypeChanged();
    void availableWeightsChanged();
    void currentWeightChanged();
    void finished();

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
    QVariantList m_availableWeights;
    int m_currentWeight;
};

#endif
