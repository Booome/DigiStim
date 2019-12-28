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
    GUI/calibratethread.cpp \
    GUI/calibratewindow.cpp \
    GUI/crosshair.cpp \
    GUI/homewindow.cpp \
    GUI/mainview.cpp \
    GUI/mwidget.cpp \
    GUI/myapplication.cpp \
    GUI/navigationbar.cpp \
    GUI/topbar.cpp \
    PulsePal/PulsePal.cpp \
    PulsePal/ofSerial.cpp \
    main.cpp

INCLUDEPATH += \
    GUI

HEADERS += \
    GUI/calibratethread.h \
    GUI/calibratewindow.h \
    GUI/crosshair.h \
    GUI/homewindow.h \
    GUI/mainview.h \
    GUI/mwidget.h \
    GUI/myapplication.h \
    GUI/navigationbar.h \
    GUI/style.h \
    GUI/topbar.h \
    PulsePal/PulsePal.h \
    PulsePal/ofConstants.h \
    PulsePal/ofSerial.h

TRANSLATIONS += \
    GUI/zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    GUI/res.qrc

DISTFILES += \
    GUI/back.png \
    GUI/home.png \
    GUI/icon.png \
    GUI/reset.png \
    GUI/setting.png \
    GUI/start.png \
    GUI/zh_CN.qm \
    GUI/zh_CN.ts
