CONFIG += console \
 qt \
 release \
 stl \
 warn_on
DESTDIR = bin
FORMS = ui/aboutdialog.ui \
 ui/clientlist.ui \
 ui/logwindow.ui \
 ui/mainwindow.ui \
 ui/monitor.ui \
 ui/personalstats.ui \
 ui/preferences.ui \
 ui/proteininfo.ui \
 ui/teamstats.ui
HEADERS += src/AnalogClock.h \
 src/Messages.h \
 src/aboutDialog.h \
 src/clientList.h \
 src/fahClient.h \
 src/fahQueue.h \
 src/fahUnitinfo.h \
 src/fahWuinfo.h \
 src/fahWulist.h \
 src/fah_consts.h \
 src/foldwatcher_consts.h \
 src/logWindow.h \
 src/mainWindow.h \
 src/monitor.h \
 src/personalStats.h \
 src/preferences.h \
 src/proteinInfo.h \
 src/teamStats.h
MOC_DIR = build
OBJECTS_DIR = build
QT = core gui network xml
RESOURCES += ui/foldwatcher.qrc
SOURCES = src/AnalogClock.cpp \
 src/Messages.cpp \
 src/aboutDialog.cpp \
 src/clientList.cpp \
 src/fahClient.cpp \
 src/fahQueue.cpp \
 src/fahUnitinfo.cpp \
 src/fahWuinfo.cpp \
 src/fahWulist.cpp \
 src/logWindow.cpp \
 src/main.cpp \
 src/mainWindow.cpp \
 src/monitor.cpp \
 src/personalStats.cpp \
 src/preferences.cpp \
 src/proteinInfo.cpp \
 src/teamStats.cpp
TEMPLATE = app
TRANSLATIONS += translations/greek.ts
UI_DIR = build
