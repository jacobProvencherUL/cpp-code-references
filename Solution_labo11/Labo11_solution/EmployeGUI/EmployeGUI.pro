TEMPLATE = app
TARGET = EmployeGUI
QT += core \
    gui
HEADERS += supprimercommisinterface.h \
    chargerdonneeinterface.h \
    enregistrerdonneeinterface.h \
    ajoutpatroninterface.h \
    ajouthoraireinterface.h \
    ajoutcommisinterface.h \
    employegui.h
SOURCES += supprimercommisinterface.cpp \
    chargerdonneeinterface.cpp \
    enregistrerdonneeinterface.cpp \
    ajoutpatroninterface.cpp \
    ajouthoraireinterface.cpp \
    ajoutcommisinterface.cpp \
    main.cpp \
    employegui.cpp
FORMS += supprimercommisinterface.ui \
    chargerdonneeinterface.ui \
    enregistrerdonneeinterface.ui \
    ajoutpatroninterface.ui \
    ajouthoraireinterface.ui \
    ajoutcommisinterface.ui \
    employegui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
