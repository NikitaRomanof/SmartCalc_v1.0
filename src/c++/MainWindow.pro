QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 app_bundle
#CONFIG += link_prl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choice.cpp \
    credit.cpp \
    credit_calc.c \
    deposit.cpp \
    deposit_calc.c \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    parce.c \
    polish.c \
    stack.c

HEADERS += \
    calc.h \
    choice.h \
    common/calc.h \
    credit.h \
    deposit.h \
    graph.h \
    mainwindow.h

FORMS += \
    choice.ui \
    credit.ui \
    deposit.ui \
    graph.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#unix: LIBS += -L$$PWD/common/ -lcalc

#INCLUDEPATH += $$PWD/common
#DEPENDPATH += $$PWD/common
