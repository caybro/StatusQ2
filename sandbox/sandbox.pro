TARGET = statusq2-sandbox

QT += quick
CONFIG += resources_big

DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_LFLAGS += $$(LDFLAGS)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp

RESOURCES += sandbox.qrc ../imports/statusq.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$OUT_PWD/../imports/
QML_IMPORT_PATH += $$PWD/../imports/
