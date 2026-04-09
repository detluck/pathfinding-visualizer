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
        "finished",
        "setClickType",
        "Pathfinding::ClickType",
        "type",
        "startAlgorithm",
        "stopAlgorithm",
        "resumeAlgorithm",
        "setSpeed",
        "speed",
        "onStep",
        "setAlgorithm",
        "index",
        "setStartIndex",
        "setEndIndex",
        "setWallIndex",
        "handleClick",
        "ClickType",
        "Start",
        "Pause",
        "Resume",
        "Stop",
        "Clear",
        "StartNode",
        "TargetNode",
        "Deleate",
        "Wall",
        "Count"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clickTypeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setClickType'
        QtMocHelpers::SlotData<void(Pathfinding::ClickType)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'startAlgorithm'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopAlgorithm'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resumeAlgorithm'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(const int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Slot 'onStep'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'setAlgorithm'
        QtMocHelpers::MethodData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'setStartIndex'
        QtMocHelpers::MethodData<void(const int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'setEndIndex'
        QtMocHelpers::MethodData<void(const int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'setWallIndex'
        QtMocHelpers::MethodData<void(const int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void(const int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void()>(18, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'type'
        QtMocHelpers::PropertyData<enum ClickType>(6, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ClickType'
        QtMocHelpers::EnumData<enum ClickType>(19, 19, QMC::EnumIsScoped).add({
            {   20, ClickType::Start },
            {   21, ClickType::Pause },
            {   22, ClickType::Resume },
            {   23, ClickType::Stop },
            {   24, ClickType::Clear },
            {   25, ClickType::StartNode },
            {   26, ClickType::TargetNode },
            {   27, ClickType::Deleate },
            {   28, ClickType::Wall },
            {   29, ClickType::Count },
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
        case 1: _t->finished(); break;
        case 2: _t->setClickType((*reinterpret_cast<std::add_pointer_t<Pathfinding::ClickType>>(_a[1]))); break;
        case 3: _t->startAlgorithm(); break;
        case 4: _t->stopAlgorithm(); break;
        case 5: _t->resumeAlgorithm(); break;
        case 6: _t->setSpeed((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->onStep(); break;
        case 8: _t->setAlgorithm((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setStartIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setEndIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setWallIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->handleClick((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->handleClick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::clickTypeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::finished, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<enum ClickType*>(_v) = _t->clickType(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClickType(*reinterpret_cast<enum ClickType*>(_v)); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Pathfinding::clickTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pathfinding::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
