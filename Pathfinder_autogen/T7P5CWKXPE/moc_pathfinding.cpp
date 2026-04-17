/****************************************************************************
** Meta object code from reading C++ file 'pathfinding.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cpp/core/pathfinding.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathfinding.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11PathfindingE_t {};
} // unnamed namespace

template <> constexpr inline auto Pathfinding::qt_create_metaobjectdata<qt_meta_tag_ZN11PathfindingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Pathfinding",
        "clickTypeChanged",
        "",
        "availableWeightsChanged",
        "currentWeightChanged",
        "finished",
        "toast",
        "message",
        "level",
        "setClickType",
        "Pathfinding::ClickType",
        "type",
        "startAlgorithm",
        "stopAlgorithm",
        "resumeAlgorithm",
        "setSpeed",
        "speed",
        "setAvailableWeights",
        "QVariantList",
        "list",
        "setCurrentWeight",
        "weight",
        "onStep",
        "setAlgorithm",
        "index",
        "handleClick",
        "addWeight",
        "ClickType",
        "availableWeights",
        "currentWeight",
        "Start",
        "Pause",
        "Resume",
        "Stop",
        "Clear",
        "StartNode",
        "TargetNode",
        "Deleate",
        "Wall",
        "WeightNode",
        "Count"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clickTypeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'availableWeightsChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentWeightChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'toast'
        QtMocHelpers::SignalData<void(QString, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::Int, 8 },
        }}),
        // Slot 'setClickType'
        QtMocHelpers::SlotData<void(Pathfinding::ClickType)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'startAlgorithm'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopAlgorithm'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resumeAlgorithm'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(const int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'setAvailableWeights'
        QtMocHelpers::SlotData<void(const QVariantList)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Slot 'setCurrentWeight'
        QtMocHelpers::SlotData<void(const int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 },
        }}),
        // Slot 'onStep'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'setAlgorithm'
        QtMocHelpers::MethodData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void(const int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void()>(25, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'addWeight'
        QtMocHelpers::MethodData<void(const int)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 21 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'type'
        QtMocHelpers::PropertyData<enum ClickType>(11, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 0),
        // property 'availableWeights'
        QtMocHelpers::PropertyData<QVariantList>(28, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'currentWeight'
        QtMocHelpers::PropertyData<int>(29, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ClickType'
        QtMocHelpers::EnumData<enum ClickType>(27, 27, QMC::EnumIsScoped).add({
            {   30, ClickType::Start },
            {   31, ClickType::Pause },
            {   32, ClickType::Resume },
            {   33, ClickType::Stop },
            {   34, ClickType::Clear },
            {   35, ClickType::StartNode },
            {   36, ClickType::TargetNode },
            {   37, ClickType::Deleate },
            {   38, ClickType::Wall },
            {   39, ClickType::WeightNode },
            {   40, ClickType::Count },
        }),
    };
    return QtMocHelpers::metaObjectData<Pathfinding, qt_meta_tag_ZN11PathfindingE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Pathfinding::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PathfindingE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PathfindingE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11PathfindingE_t>.metaTypes,
    nullptr
} };

void Pathfinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Pathfinding *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clickTypeChanged(); break;
        case 1: _t->availableWeightsChanged(); break;
        case 2: _t->currentWeightChanged(); break;
        case 3: _t->finished(); break;
        case 4: _t->toast((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->setClickType((*reinterpret_cast<std::add_pointer_t<Pathfinding::ClickType>>(_a[1]))); break;
        case 6: _t->startAlgorithm(); break;
        case 7: _t->stopAlgorithm(); break;
        case 8: _t->resumeAlgorithm(); break;
        case 9: _t->setSpeed((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setAvailableWeights((*reinterpret_cast<std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 11: _t->setCurrentWeight((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->onStep(); break;
        case 13: _t->setAlgorithm((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->handleClick((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->handleClick(); break;
        case 16: _t->addWeight((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::clickTypeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::availableWeightsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::currentWeightChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::finished, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)(QString , int )>(_a, &Pathfinding::toast, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<enum ClickType*>(_v) = _t->clickType(); break;
        case 1: *reinterpret_cast<QVariantList*>(_v) = _t->availableWeights(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->currentWeight(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClickType(*reinterpret_cast<enum ClickType*>(_v)); break;
        case 1: _t->setAvailableWeights(*reinterpret_cast<QVariantList*>(_v)); break;
        case 2: _t->setCurrentWeight(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Pathfinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pathfinding::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PathfindingE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pathfinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Pathfinding::clickTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pathfinding::availableWeightsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Pathfinding::currentWeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Pathfinding::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Pathfinding::toast(QString _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
