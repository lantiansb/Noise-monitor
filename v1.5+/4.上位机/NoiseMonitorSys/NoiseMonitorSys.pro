QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databaseoperator.cpp \
    detectorthread.cpp \
    devicemonitor.cpp \
    main.cpp \
    myalgorithm.cpp \
    noisemonitorsys.cpp \
    qcustomplot.cpp \
    savedialog.cpp \
    updateplotthread.cpp

HEADERS += \
    databaseoperator.h \
    detectorthread.h \
    devicemonitor.h \
    myalgorithm.h \
    noisemonitorsys.h \
    qcustomplot.h \
    savedialog.h \
    updateplotthread.h

FORMS += \
    devicemonitor.ui \
    noisemonitorsys.ui \
    savedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
