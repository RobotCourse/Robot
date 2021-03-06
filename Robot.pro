#-------------------------------------------------
#
# Project created by QtCreator 2016-10-11T11:02:22
#
#-------------------------------------------------

QT       += widgets opengl xml serialport

TARGET = Robot
TEMPLATE = lib

DEFINES += ROBOT_LIBRARY

SOURCES += robot.cpp

HEADERS += robot.h\
        robot_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

PROJNAME = Robot
INSTTYPE = MOD

INCLUDEPATH += /home/mini/OpenNI-Linux-x64-2.3/Include
LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui
LIBS += -L/home/mini/OpenNI-Linux-x64-2.3/Redist -lOpenNI2
LIBS += -lurg_c

INCLUDEPATH += /home/mini/NiTE-2.0.0/Include
LIBS += /home/mini/NiTE-2.0.0/Redist/libNiTE2.so



include(RobotSDK_Main.pri)
