/****************************************************************************
** Meta object code from reading C++ file 'pathfinding.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/core/pathfinding.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathfinding.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPathfindingENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPathfindingENDCLASS = QtMocHelpers::stringData(
    "Pathfinding",
    "clickTypeChanged",
    "",
    "appModeChanged",
    "availableWeightsChanged",
    "currentWeightChanged",
    "finished",
    "toast",
    "message",
    "level",
    "setAppMode",
    "Pathfinding::AppMode",
    "mode",
    "setClickType",
    "Pathfinding::ClickType",
    "type",
    "startAlgorithm",
    "stopAlgorithm",
    "resumeAlgorithm",
    "setSpeed",
    "speed",
    "setAvailableWeights",
    "list",
    "setCurrentWeight",
    "weight",
    "onStep",
    "buildTsp",
    "visualizeTsp",
    "QList<int>",
    "order",
    "setAlgorithm",
    "index",
    "setTspAlgorithm",
    "handleClick",
    "addWeight",
    "runTsp",
    "ClickType",
    "availableWeights",
    "currentWeight",
    "appMode",
    "AppMode",
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
    "Count",
    "TSP"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPathfindingENDCLASS_t {
    uint offsetsAndSizes[106];
    char stringdata0[12];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[24];
    char stringdata5[21];
    char stringdata6[9];
    char stringdata7[6];
    char stringdata8[8];
    char stringdata9[6];
    char stringdata10[11];
    char stringdata11[21];
    char stringdata12[5];
    char stringdata13[13];
    char stringdata14[23];
    char stringdata15[5];
    char stringdata16[15];
    char stringdata17[14];
    char stringdata18[16];
    char stringdata19[9];
    char stringdata20[6];
    char stringdata21[20];
    char stringdata22[5];
    char stringdata23[17];
    char stringdata24[7];
    char stringdata25[7];
    char stringdata26[9];
    char stringdata27[13];
    char stringdata28[11];
    char stringdata29[6];
    char stringdata30[13];
    char stringdata31[6];
    char stringdata32[16];
    char stringdata33[12];
    char stringdata34[10];
    char stringdata35[7];
    char stringdata36[10];
    char stringdata37[17];
    char stringdata38[14];
    char stringdata39[8];
    char stringdata40[8];
    char stringdata41[6];
    char stringdata42[6];
    char stringdata43[7];
    char stringdata44[5];
    char stringdata45[6];
    char stringdata46[10];
    char stringdata47[11];
    char stringdata48[8];
    char stringdata49[5];
    char stringdata50[11];
    char stringdata51[6];
    char stringdata52[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPathfindingENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPathfindingENDCLASS_t qt_meta_stringdata_CLASSPathfindingENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "Pathfinding"
        QT_MOC_LITERAL(12, 16),  // "clickTypeChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 14),  // "appModeChanged"
        QT_MOC_LITERAL(45, 23),  // "availableWeightsChanged"
        QT_MOC_LITERAL(69, 20),  // "currentWeightChanged"
        QT_MOC_LITERAL(90, 8),  // "finished"
        QT_MOC_LITERAL(99, 5),  // "toast"
        QT_MOC_LITERAL(105, 7),  // "message"
        QT_MOC_LITERAL(113, 5),  // "level"
        QT_MOC_LITERAL(119, 10),  // "setAppMode"
        QT_MOC_LITERAL(130, 20),  // "Pathfinding::AppMode"
        QT_MOC_LITERAL(151, 4),  // "mode"
        QT_MOC_LITERAL(156, 12),  // "setClickType"
        QT_MOC_LITERAL(169, 22),  // "Pathfinding::ClickType"
        QT_MOC_LITERAL(192, 4),  // "type"
        QT_MOC_LITERAL(197, 14),  // "startAlgorithm"
        QT_MOC_LITERAL(212, 13),  // "stopAlgorithm"
        QT_MOC_LITERAL(226, 15),  // "resumeAlgorithm"
        QT_MOC_LITERAL(242, 8),  // "setSpeed"
        QT_MOC_LITERAL(251, 5),  // "speed"
        QT_MOC_LITERAL(257, 19),  // "setAvailableWeights"
        QT_MOC_LITERAL(277, 4),  // "list"
        QT_MOC_LITERAL(282, 16),  // "setCurrentWeight"
        QT_MOC_LITERAL(299, 6),  // "weight"
        QT_MOC_LITERAL(306, 6),  // "onStep"
        QT_MOC_LITERAL(313, 8),  // "buildTsp"
        QT_MOC_LITERAL(322, 12),  // "visualizeTsp"
        QT_MOC_LITERAL(335, 10),  // "QList<int>"
        QT_MOC_LITERAL(346, 5),  // "order"
        QT_MOC_LITERAL(352, 12),  // "setAlgorithm"
        QT_MOC_LITERAL(365, 5),  // "index"
        QT_MOC_LITERAL(371, 15),  // "setTspAlgorithm"
        QT_MOC_LITERAL(387, 11),  // "handleClick"
        QT_MOC_LITERAL(399, 9),  // "addWeight"
        QT_MOC_LITERAL(409, 6),  // "runTsp"
        QT_MOC_LITERAL(416, 9),  // "ClickType"
        QT_MOC_LITERAL(426, 16),  // "availableWeights"
        QT_MOC_LITERAL(443, 13),  // "currentWeight"
        QT_MOC_LITERAL(457, 7),  // "appMode"
        QT_MOC_LITERAL(465, 7),  // "AppMode"
        QT_MOC_LITERAL(473, 5),  // "Start"
        QT_MOC_LITERAL(479, 5),  // "Pause"
        QT_MOC_LITERAL(485, 6),  // "Resume"
        QT_MOC_LITERAL(492, 4),  // "Stop"
        QT_MOC_LITERAL(497, 5),  // "Clear"
        QT_MOC_LITERAL(503, 9),  // "StartNode"
        QT_MOC_LITERAL(513, 10),  // "TargetNode"
        QT_MOC_LITERAL(524, 7),  // "Deleate"
        QT_MOC_LITERAL(532, 4),  // "Wall"
        QT_MOC_LITERAL(537, 10),  // "WeightNode"
        QT_MOC_LITERAL(548, 5),  // "Count"
        QT_MOC_LITERAL(554, 3)   // "TSP"
    },
    "Pathfinding",
    "clickTypeChanged",
    "",
    "appModeChanged",
    "availableWeightsChanged",
    "currentWeightChanged",
    "finished",
    "toast",
    "message",
    "level",
    "setAppMode",
    "Pathfinding::AppMode",
    "mode",
    "setClickType",
    "Pathfinding::ClickType",
    "type",
    "startAlgorithm",
    "stopAlgorithm",
    "resumeAlgorithm",
    "setSpeed",
    "speed",
    "setAvailableWeights",
    "list",
    "setCurrentWeight",
    "weight",
    "onStep",
    "buildTsp",
    "visualizeTsp",
    "QList<int>",
    "order",
    "setAlgorithm",
    "index",
    "setTspAlgorithm",
    "handleClick",
    "addWeight",
    "runTsp",
    "ClickType",
    "availableWeights",
    "currentWeight",
    "appMode",
    "AppMode",
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
    "Count",
    "TSP"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPathfindingENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       4,  199, // properties
       2,  219, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x06,    7 /* Public */,
       3,    0,  153,    2, 0x06,    8 /* Public */,
       4,    0,  154,    2, 0x06,    9 /* Public */,
       5,    0,  155,    2, 0x06,   10 /* Public */,
       6,    0,  156,    2, 0x06,   11 /* Public */,
       7,    2,  157,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,  162,    2, 0x0a,   15 /* Public */,
      13,    1,  165,    2, 0x0a,   17 /* Public */,
      16,    0,  168,    2, 0x0a,   19 /* Public */,
      17,    0,  169,    2, 0x0a,   20 /* Public */,
      18,    0,  170,    2, 0x0a,   21 /* Public */,
      19,    1,  171,    2, 0x0a,   22 /* Public */,
      21,    1,  174,    2, 0x0a,   24 /* Public */,
      23,    1,  177,    2, 0x0a,   26 /* Public */,
      25,    0,  180,    2, 0x08,   28 /* Private */,
      26,    0,  181,    2, 0x08,   29 /* Private */,
      27,    1,  182,    2, 0x08,   30 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      30,    1,  185,    2, 0x02,   32 /* Public */,
      32,    1,  188,    2, 0x02,   34 /* Public */,
      33,    1,  191,    2, 0x02,   36 /* Public */,
      33,    0,  194,    2, 0x22,   38 /* Public | MethodCloned */,
      34,    1,  195,    2, 0x02,   39 /* Public */,
      35,    0,  198,    2, 0x02,   41 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantList,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

 // properties: name, type, flags
      15, 0x80000000 | 36, 0x0001500b, uint(0), 0,
      37, QMetaType::QVariantList, 0x00015103, uint(2), 0,
      38, QMetaType::Int, 0x00015103, uint(3), 0,
      39, 0x80000000 | 40, 0x0001510b, uint(1), 0,

 // enums: name, alias, flags, count, data
      36,   36, 0x2,   11,  229,
      40,   40, 0x2,    2,  251,

 // enum data: key, value
      41, uint(Pathfinding::ClickType::Start),
      42, uint(Pathfinding::ClickType::Pause),
      43, uint(Pathfinding::ClickType::Resume),
      44, uint(Pathfinding::ClickType::Stop),
      45, uint(Pathfinding::ClickType::Clear),
      46, uint(Pathfinding::ClickType::StartNode),
      47, uint(Pathfinding::ClickType::TargetNode),
      48, uint(Pathfinding::ClickType::Deleate),
      49, uint(Pathfinding::ClickType::Wall),
      50, uint(Pathfinding::ClickType::WeightNode),
      51, uint(Pathfinding::ClickType::Count),
      52, uint(Pathfinding::AppMode::TSP),
       0, uint(Pathfinding::AppMode::Pathfinding),

       0        // eod
};

Q_CONSTINIT const QMetaObject Pathfinding::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPathfindingENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPathfindingENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPathfindingENDCLASS_t,
        // property 'type'
        QtPrivate::TypeAndForceComplete<ClickType, std::true_type>,
        // property 'availableWeights'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'currentWeight'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'appMode'
        QtPrivate::TypeAndForceComplete<AppMode, std::true_type>,
        // enum 'ClickType'
        QtPrivate::TypeAndForceComplete<Pathfinding::ClickType, std::true_type>,
        // enum 'AppMode'
        QtPrivate::TypeAndForceComplete<Pathfinding::AppMode, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Pathfinding, std::true_type>,
        // method 'clickTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'appModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'availableWeightsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentWeightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setAppMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Pathfinding::AppMode, std::false_type>,
        // method 'setClickType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Pathfinding::ClickType, std::false_type>,
        // method 'startAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'setAvailableWeights'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList, std::false_type>,
        // method 'setCurrentWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'onStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buildTsp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'visualizeTsp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<int> &, std::false_type>,
        // method 'setAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setTspAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'handleClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'runTsp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Pathfinding::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pathfinding *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clickTypeChanged(); break;
        case 1: _t->appModeChanged(); break;
        case 2: _t->availableWeightsChanged(); break;
        case 3: _t->currentWeightChanged(); break;
        case 4: _t->finished(); break;
        case 5: _t->toast((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->setAppMode((*reinterpret_cast< std::add_pointer_t<Pathfinding::AppMode>>(_a[1]))); break;
        case 7: _t->setClickType((*reinterpret_cast< std::add_pointer_t<Pathfinding::ClickType>>(_a[1]))); break;
        case 8: _t->startAlgorithm(); break;
        case 9: _t->stopAlgorithm(); break;
        case 10: _t->resumeAlgorithm(); break;
        case 11: _t->setSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setAvailableWeights((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 13: _t->setCurrentWeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->onStep(); break;
        case 15: _t->buildTsp(); break;
        case 16: _t->visualizeTsp((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 17: _t->setAlgorithm((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->setTspAlgorithm((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->handleClick((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->handleClick(); break;
        case 21: _t->addWeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->runTsp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pathfinding::*)();
            if (_t _q_method = &Pathfinding::clickTypeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pathfinding::*)();
            if (_t _q_method = &Pathfinding::appModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Pathfinding::*)();
            if (_t _q_method = &Pathfinding::availableWeightsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Pathfinding::*)();
            if (_t _q_method = &Pathfinding::currentWeightChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Pathfinding::*)();
            if (_t _q_method = &Pathfinding::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Pathfinding::*)(QString , int );
            if (_t _q_method = &Pathfinding::toast; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Pathfinding *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ClickType*>(_v) = _t->clickType(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->availableWeights(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->currentWeight(); break;
        case 3: *reinterpret_cast< AppMode*>(_v) = _t->appMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Pathfinding *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClickType(*reinterpret_cast< ClickType*>(_v)); break;
        case 1: _t->setAvailableWeights(*reinterpret_cast< QVariantList*>(_v)); break;
        case 2: _t->setCurrentWeight(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setAppMode(*reinterpret_cast< AppMode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Pathfinding::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pathfinding::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPathfindingENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pathfinding::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Pathfinding::clickTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pathfinding::appModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Pathfinding::availableWeightsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Pathfinding::currentWeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Pathfinding::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Pathfinding::toast(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
