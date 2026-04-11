/****************************************************************************
** Meta object code from reading C++ file 'employegui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "employegui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EmployeGUI_t {
    QByteArrayData data[11];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmployeGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmployeGUI_t qt_meta_stringdata_EmployeGUI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EmployeGUI"
QT_MOC_LITERAL(1, 11, 17), // "dialogAjoutCommis"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "dialogAjoutHoraire"
QT_MOC_LITERAL(4, 49, 17), // "dialogAjoutPatron"
QT_MOC_LITERAL(5, 67, 21), // "dialogSupprimerCommis"
QT_MOC_LITERAL(6, 89, 22), // "dialogSupprimerHoraire"
QT_MOC_LITERAL(7, 112, 21), // "dialogSupprimerPatron"
QT_MOC_LITERAL(8, 134, 22), // "dialogEnregistrerInfor"
QT_MOC_LITERAL(9, 157, 20), // "dialogChargerFichier"
QT_MOC_LITERAL(10, 178, 19) // "selectionLigneTable"

    },
    "EmployeGUI\0dialogAjoutCommis\0\0"
    "dialogAjoutHoraire\0dialogAjoutPatron\0"
    "dialogSupprimerCommis\0dialogSupprimerHoraire\0"
    "dialogSupprimerPatron\0dialogEnregistrerInfor\0"
    "dialogChargerFichier\0selectionLigneTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmployeGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EmployeGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmployeGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialogAjoutCommis(); break;
        case 1: _t->dialogAjoutHoraire(); break;
        case 2: _t->dialogAjoutPatron(); break;
        case 3: _t->dialogSupprimerCommis(); break;
        case 4: _t->dialogSupprimerHoraire(); break;
        case 5: _t->dialogSupprimerPatron(); break;
        case 6: _t->dialogEnregistrerInfor(); break;
        case 7: _t->dialogChargerFichier(); break;
        case 8: _t->selectionLigneTable(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EmployeGUI::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_EmployeGUI.data,
    qt_meta_data_EmployeGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EmployeGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmployeGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EmployeGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
