QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calibratethread.cpp \
    calibratewindow.cpp \
    crosshair.cpp \
    homewindow.cpp \
    main.cpp \
    mainview.cpp \
    myapplication.cpp \
    navigationbar.cpp \
    topbar.cpp

HEADERS += \
    calibratethread.h \
    calibratewindow.h \
    crosshair.h \
    homewindow.h \
    mainview.h \
    myapplication.h \
    navigationbar.h \
    style.h \
    topbar.h

TRANSLATIONS += \
    zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
