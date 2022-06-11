QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
                                QT += network

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrator.cpp \
    book.cpp \
    client.cpp \
    common.cpp \
    courier.cpp \
    fragile.cpp \
    main.cpp \
    mainwindow.cpp \
    package.cpp \
    user.cpp

HEADERS += \
    administrator.h \
    book.h \
    client.h \
    common.h \
    courier.h \
    fragile.h \
    mainwindow.h \
    package.h \
    user.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
