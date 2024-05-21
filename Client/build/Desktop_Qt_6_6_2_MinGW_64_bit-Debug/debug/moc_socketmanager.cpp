/****************************************************************************
** Meta object code from reading C++ file 'socketmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../socketmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSSocketManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSocketManagerENDCLASS = QtMocHelpers::stringData(
    "SocketManager",
    "userAuthenticated",
    "",
    "UserInfo",
    "user",
    "scheduleForWeekReceived",
    "ScheduleForWeek",
    "message",
    "disconectionReceived",
    "userAuthenticationFailed",
    "userRegistration",
    "userRegistrationFailed",
    "userListReceived",
    "UserList",
    "users",
    "registrationAnswer",
    "answer",
    "deleteUserAnswer",
    "slotReadyRead",
    "connectSocket",
    "sendScheduleRequest",
    "sendUserListRequest",
    "registerUser",
    "studentId",
    "name",
    "autorizationUser",
    "logout",
    "deleteUser",
    "numberStudentId",
    "saveScheduleDay",
    "ScheduleForDay&",
    "scheduleForDay",
    "updateScheduleDay"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSocketManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       5,    1,  131,    2, 0x06,    3 /* Public */,
       8,    0,  134,    2, 0x06,    5 /* Public */,
       9,    0,  135,    2, 0x06,    6 /* Public */,
      10,    0,  136,    2, 0x06,    7 /* Public */,
      11,    0,  137,    2, 0x06,    8 /* Public */,
      12,    1,  138,    2, 0x06,    9 /* Public */,
      15,    1,  141,    2, 0x06,   11 /* Public */,
      17,    1,  144,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    0,  147,    2, 0x0a,   15 /* Public */,
      19,    0,  148,    2, 0x0a,   16 /* Public */,
      20,    0,  149,    2, 0x0a,   17 /* Public */,
      21,    0,  150,    2, 0x0a,   18 /* Public */,
      22,    2,  151,    2, 0x0a,   19 /* Public */,
      25,    1,  156,    2, 0x0a,   22 /* Public */,
      26,    0,  159,    2, 0x0a,   24 /* Public */,
      27,    1,  160,    2, 0x0a,   25 /* Public */,
      29,    1,  163,    2, 0x0a,   27 /* Public */,
      32,    1,  166,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::ULongLong,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,   28,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

Q_CONSTINIT const QMetaObject SocketManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSocketManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSocketManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSocketManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SocketManager, std::true_type>,
        // method 'userAuthenticated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const UserInfo &, std::false_type>,
        // method 'scheduleForWeekReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const ScheduleForWeek &, std::false_type>,
        // method 'disconectionReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userAuthenticationFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userRegistration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userRegistrationFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userListReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const UserList &, std::false_type>,
        // method 'registrationAnswer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'deleteUserAnswer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectSocket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendScheduleRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendUserListRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'autorizationUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint64, std::false_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint64, std::false_type>,
        // method 'saveScheduleDay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ScheduleForDay &, std::false_type>,
        // method 'updateScheduleDay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ScheduleForDay &, std::false_type>
    >,
    nullptr
} };

void SocketManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SocketManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->userAuthenticated((*reinterpret_cast< std::add_pointer_t<UserInfo>>(_a[1]))); break;
        case 1: _t->scheduleForWeekReceived((*reinterpret_cast< std::add_pointer_t<ScheduleForWeek>>(_a[1]))); break;
        case 2: _t->disconectionReceived(); break;
        case 3: _t->userAuthenticationFailed(); break;
        case 4: _t->userRegistration(); break;
        case 5: _t->userRegistrationFailed(); break;
        case 6: _t->userListReceived((*reinterpret_cast< std::add_pointer_t<UserList>>(_a[1]))); break;
        case 7: _t->registrationAnswer((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->deleteUserAnswer((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->slotReadyRead(); break;
        case 10: _t->connectSocket(); break;
        case 11: _t->sendScheduleRequest(); break;
        case 12: _t->sendUserListRequest(); break;
        case 13: _t->registerUser((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 14: _t->autorizationUser((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1]))); break;
        case 15: _t->logout(); break;
        case 16: _t->deleteUser((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1]))); break;
        case 17: _t->saveScheduleDay((*reinterpret_cast< std::add_pointer_t<ScheduleForDay&>>(_a[1]))); break;
        case 18: _t->updateScheduleDay((*reinterpret_cast< std::add_pointer_t<ScheduleForDay&>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SocketManager::*)(const UserInfo & );
            if (_t _q_method = &SocketManager::userAuthenticated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)(const ScheduleForWeek & );
            if (_t _q_method = &SocketManager::scheduleForWeekReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)();
            if (_t _q_method = &SocketManager::disconectionReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)();
            if (_t _q_method = &SocketManager::userAuthenticationFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)();
            if (_t _q_method = &SocketManager::userRegistration; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)();
            if (_t _q_method = &SocketManager::userRegistrationFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)(const UserList & );
            if (_t _q_method = &SocketManager::userListReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)(bool );
            if (_t _q_method = &SocketManager::registrationAnswer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SocketManager::*)(bool );
            if (_t _q_method = &SocketManager::deleteUserAnswer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *SocketManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSocketManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void SocketManager::userAuthenticated(const UserInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketManager::scheduleForWeekReceived(const ScheduleForWeek & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SocketManager::disconectionReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SocketManager::userAuthenticationFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SocketManager::userRegistration()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SocketManager::userRegistrationFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SocketManager::userListReceived(const UserList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SocketManager::registrationAnswer(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SocketManager::deleteUserAnswer(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
