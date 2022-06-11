QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmoney.cpp \
    administrator.cpp \
    adminwindow.cpp \
    changepassword.cpp \
    client.cpp \
    clientwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    package.cpp \
    packageinfowindow.cpp \
    packagelistwindow.cpp \
    registerwindow.cpp \
    sendpackagewindow.cpp \
    signforpackagewindow.cpp \
    user.cpp \
    userinfowindow.cpp \
    userlistwindow.cpp

HEADERS += \
    addmoney.h \
    administrator.h \
    adminwindow.h \
    changepassword.h \
    client.h \
    clientwindow.h \
    loginwindow.h \
    package.h \
    packageinfowindow.h \
    packagelistwindow.h \
    registerwindow.h \
    sendpackagewindow.h \
    signforpackagewindow.h \
    user.h \
    userinfowindow.h \
    userlistwindow.h

FORMS += \
    addmoney.ui \
    adminwindow.ui \
    changepassword.ui \
    clientwindow.ui \
    loginwindow.ui \
    packageinfowindow.ui \
    packagelistwindow.ui \
    registerwindow.ui \
    sendpackagewindow.ui \
    signforpackagewindow.ui \
    userinfowindow.ui \
    userlistwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
