
include(../../interfaces/interfaces.pri)

PLUGIN_NAME 	= notify

QT              += widgets dbus
TEMPLATE         = lib
CONFIG          += plugin c++11 link_pkgconfig
PKGCONFIG += dtkbase dtkwidget
TARGET          = $$qtLibraryTarget($$PLUGIN_NAME)
DESTDIR          = $$_PRO_FILE_PWD_/../
DISTFILES       += $$PLUGIN_NAME.json notify-monitor

HEADERS += \
    notifyplugin.h \
    notifymanager.h \
    notifyviewer.h \
    notifydata.h

SOURCES += \
    notifyplugin.cpp \
    notifymanager.cpp \
    notifyviewer.cpp \
    notifydata.cpp

target.path = $${PREFIX}/lib/dde-control-center/plugins/

utils.path = $${PREFIX}/lib/dde-control-center/plugins/bin/
utils.files = notify-monitor

INSTALLS += target utils

RESOURCES += \
    images.qrc
