/****************************************************************************
** Meta object code from reading C++ file 'pathfinding.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/core/pathfinding.h"
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
        "finished",
        "",
        "startAlgorithm",
        "stopAlgorithm",
        "resumeAlgorithm",
        "setSpeed",
        "speed",
        "onStep",
        "setAlgorithm",
        "index",
        "setClickType",
        "ClickType",
        "type",
        "setStartIndex",
        "setEndIndex",
        "setWallIndex",
        "handleClick",
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
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startAlgorithm'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopAlgorithm'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resumeAlgorithm'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(const int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'onStep'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'setAlgorithm'
        QtMocHelpers::MethodData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'setClickType'
        QtMocHelpers::MethodData<void(enum ClickType)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Method 'setStartIndex'
        QtMocHelpers::MethodData<void(const int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'setEndIndex'
        QtMocHelpers::MethodData<void(const int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'setWallIndex'
        QtMocHelpers::MethodData<void(const int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void(const int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void()>(17, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ClickType'
        QtMocHelpers::EnumData<enum ClickType>(12, 12, QMC::EnumIsScoped).add({
            {   18, ClickType::Start },
            {   19, ClickType::Pause },
            {   20, ClickType::Resume },
            {   21, ClickType::Stop },
            {   22, ClickType::Clear },
            {   23, ClickType::StartNode },
            {   24, ClickType::TargetNode },
            {   25, ClickType::Deleate },
            {   26, ClickType::Wall },
            {   27, ClickType::Count },
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
        case 0: _t->finished(); break;
        case 1: _t->startAlgorithm(); break;
        case 2: _t->stopAlgorithm(); break;
        case 3: _t->resumeAlgorithm(); break;
        case 4: _t->setSpeed((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onStep(); break;
        case 6: _t->setAlgorithm((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setClickType((*reinterpret_cast<std::add_pointer_t<enum ClickType>>(_a[1]))); break;
        case 8: _t->setStartIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setEndIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setWallIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->handleClick((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->handleClick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Pathfinding::*)()>(_a, &Pathfinding::finished, 0))
            return;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Pathfinding::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
