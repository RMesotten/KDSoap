QT       -= gui

include(../unittests.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    test_issue1.cpp

HEADERS +=

KDWSDL = test.wsdl

OTHER_FILES += \
    kdsoap.pri \
    test.wsdl

test.target = test
test.commands = ./$(TARGET)
test.depends = $(TARGET)
QMAKE_EXTRA_TARGETS += test
