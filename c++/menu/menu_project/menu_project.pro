QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    elimina.cpp \
    inserisci.cpp \
    main.cpp \
    mainwindow.cpp \
    ricerca.cpp \
    table.cpp \
    visualizza.cpp \
    worker.cpp

HEADERS += \
    elimina.h \
    inserisci.h \
    mainwindow.h \
    ricerca.h \
    table.h \
    visualizza.h \
    worker.h

FORMS += \
    elimina.ui \
    inserisci.ui \
    mainwindow.ui \
    ricerca.ui \
    table.ui \
    visualizza.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
