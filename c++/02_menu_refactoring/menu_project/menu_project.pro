QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classes.cpp \
    inserisci.cpp \
    main.cpp \
    mainwindow.cpp \
    modifica.cpp \
    ricerca.cpp \
    stats.cpp \
    visualizza.cpp \
    worker.cpp

HEADERS += \
    classes.h \
    inserisci.h \
    mainwindow.h \
    modifica.h \
    ricerca.h \
    stats.h \
    visualizza.h \
    worker.h

FORMS += \
    inserisci.ui \
    mainwindow.ui \
    modifica.ui \
    ricerca.ui \
    stats.ui \
    visualizza.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
