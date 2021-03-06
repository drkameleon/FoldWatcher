#############################################################################
# Makefile for building: bin/foldwatcher
# Generated by qmake (2.01a) (Qt 4.3.4) on: Mon May 19 04:55:59 2008
# Project:  foldwatcher.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile foldwatcher.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SHARED -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -fpermissive -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtXml -I/usr/include/qt4 -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -Wl,--no-undefined
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtXml -lQtGui -lQtNetwork -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/AnalogClock.cpp \
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
		src/teamStats.cpp build/moc_AnalogClock.cpp \
		build/moc_aboutDialog.cpp \
		build/moc_clientList.cpp \
		build/moc_logWindow.cpp \
		build/moc_mainWindow.cpp \
		build/moc_monitor.cpp \
		build/moc_personalStats.cpp \
		build/moc_preferences.cpp \
		build/moc_proteinInfo.cpp \
		build/moc_teamStats.cpp \
		qrc_foldwatcher.cpp
OBJECTS       = build/AnalogClock.o \
		build/Messages.o \
		build/aboutDialog.o \
		build/clientList.o \
		build/fahClient.o \
		build/fahQueue.o \
		build/fahUnitinfo.o \
		build/fahWuinfo.o \
		build/fahWulist.o \
		build/logWindow.o \
		build/main.o \
		build/mainWindow.o \
		build/monitor.o \
		build/personalStats.o \
		build/preferences.o \
		build/proteinInfo.o \
		build/teamStats.o \
		build/moc_AnalogClock.o \
		build/moc_aboutDialog.o \
		build/moc_clientList.o \
		build/moc_logWindow.o \
		build/moc_mainWindow.o \
		build/moc_monitor.o \
		build/moc_personalStats.o \
		build/moc_preferences.o \
		build/moc_proteinInfo.o \
		build/moc_teamStats.o \
		build/qrc_foldwatcher.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		foldwatcher.pro
QMAKE_TARGET  = foldwatcher
DESTDIR       = bin/
TARGET        = bin/foldwatcher

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_aboutdialog.h build/ui_clientlist.h build/ui_logwindow.h build/ui_mainwindow.h build/ui_monitor.h build/ui_personalstats.h build/ui_preferences.h build/ui_proteininfo.h build/ui_teamstats.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: foldwatcher.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf
	$(QMAKE) -unix -o Makefile foldwatcher.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile foldwatcher.pro

dist: 
	@$(CHK_DIR_EXISTS) build/foldwatcher1.0.0 || $(MKDIR) build/foldwatcher1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/foldwatcher1.0.0/ && $(COPY_FILE) --parents src/AnalogClock.h src/Messages.h src/aboutDialog.h src/clientList.h src/fahClient.h src/fahQueue.h src/fahUnitinfo.h src/fahWuinfo.h src/fahWulist.h src/fah_consts.h src/foldwatcher_consts.h src/logWindow.h src/mainWindow.h src/monitor.h src/personalStats.h src/preferences.h src/proteinInfo.h src/teamStats.h build/foldwatcher1.0.0/ && $(COPY_FILE) --parents ui/foldwatcher.qrc build/foldwatcher1.0.0/ && $(COPY_FILE) --parents src/AnalogClock.cpp src/Messages.cpp src/aboutDialog.cpp src/clientList.cpp src/fahClient.cpp src/fahQueue.cpp src/fahUnitinfo.cpp src/fahWuinfo.cpp src/fahWulist.cpp src/logWindow.cpp src/main.cpp src/mainWindow.cpp src/monitor.cpp src/personalStats.cpp src/preferences.cpp src/proteinInfo.cpp src/teamStats.cpp build/foldwatcher1.0.0/ && $(COPY_FILE) --parents ui/aboutdialog.ui ui/clientlist.ui ui/logwindow.ui ui/mainwindow.ui ui/monitor.ui ui/personalstats.ui ui/preferences.ui ui/proteininfo.ui ui/teamstats.ui build/foldwatcher1.0.0/ && $(COPY_FILE) --parents translations/greek.ts build/foldwatcher1.0.0/ && (cd `dirname build/foldwatcher1.0.0` && $(TAR) foldwatcher1.0.0.tar foldwatcher1.0.0 && $(COMPRESS) foldwatcher1.0.0.tar) && $(MOVE) `dirname build/foldwatcher1.0.0`/foldwatcher1.0.0.tar.gz . && $(DEL_FILE) -r build/foldwatcher1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_AnalogClock.cpp build/moc_aboutDialog.cpp build/moc_clientList.cpp build/moc_logWindow.cpp build/moc_mainWindow.cpp build/moc_monitor.cpp build/moc_personalStats.cpp build/moc_preferences.cpp build/moc_proteinInfo.cpp build/moc_teamStats.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_AnalogClock.cpp build/moc_aboutDialog.cpp build/moc_clientList.cpp build/moc_logWindow.cpp build/moc_mainWindow.cpp build/moc_monitor.cpp build/moc_personalStats.cpp build/moc_preferences.cpp build/moc_proteinInfo.cpp build/moc_teamStats.cpp
build/moc_AnalogClock.cpp: src/AnalogClock.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/AnalogClock.h -o build/moc_AnalogClock.cpp

build/moc_aboutDialog.cpp: build/ui_aboutdialog.h \
		src/aboutDialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/aboutDialog.h -o build/moc_aboutDialog.cpp

build/moc_clientList.cpp: src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/clientList.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/clientList.h -o build/moc_clientList.cpp

build/moc_logWindow.cpp: build/ui_logwindow.h \
		src/logWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/logWindow.h -o build/moc_logWindow.cpp

build/moc_mainWindow.cpp: build/ui_mainwindow.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/mainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/mainWindow.h -o build/moc_mainWindow.cpp

build/moc_monitor.cpp: src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_monitor.h \
		src/monitor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/monitor.h -o build/moc_monitor.cpp

build/moc_personalStats.cpp: build/ui_personalstats.h \
		src/personalStats.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/personalStats.h -o build/moc_personalStats.cpp

build/moc_preferences.cpp: build/ui_preferences.h \
		src/preferences.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/preferences.h -o build/moc_preferences.cpp

build/moc_proteinInfo.cpp: src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_proteininfo.h \
		src/proteinInfo.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/proteinInfo.h -o build/moc_proteinInfo.cpp

build/moc_teamStats.cpp: build/ui_teamstats.h \
		src/teamStats.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/teamStats.h -o build/moc_teamStats.cpp

compiler_rcc_make_all: qrc_foldwatcher.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_foldwatcher.cpp
qrc_foldwatcher.cpp: ui/foldwatcher.qrc \
		ui/logo/greenCube.png \
		ui/logo/aboutLogo.png \
		ui/icons/network-receive.png \
		ui/icons/stock_calendar-and-tasks.png \
		ui/icons/gtk-goto-top.png \
		ui/icons/gtk-save-as.png \
		ui/icons/software-update-urgent.png \
		ui/icons/mail_forward.png \
		ui/icons/preferences-other.png \
		ui/icons/stock_bottom.png \
		ui/icons/stock_dialog-info.png \
		ui/icons/tab_new.png \
		ui/icons/stock_book_blue.png \
		ui/icons/gpm-ups-080-charging.png \
		ui/icons/gpm-keyboard-000.png \
		ui/icons/redhat-games.png \
		ui/icons/stock_properties.png \
		ui/icons/window-new.png \
		ui/icons/redhat-sound_video.png \
		ui/icons/stock_flip-horizontally.png \
		ui/icons/xfce4-settings.png \
		ui/icons/remove.png \
		ui/icons/stock_help-add-bookmark.png \
		ui/icons/stock_mail-compose.png \
		ui/icons/gnome-other.png \
		ui/icons/filesaveas.png \
		ui/icons/applications-engineering.png \
		ui/icons/stock_text_justify.png \
		ui/icons/go-home.png \
		ui/icons/nm-device-wired.png \
		ui/icons/stock_presentation-box.png \
		ui/icons/gtk-book.png \
		ui/icons/package_system.png \
		ui/icons/stock_default-folder.png \
		ui/icons/gtk-find.png \
		ui/icons/stock_help-agent.png \
		ui/icons/edit-undo.png \
		ui/icons/gpm-primary-060.png \
		ui/icons/stock_text_unindent.png \
		ui/icons/redhat-home.png \
		ui/icons/edit-cut.png \
		ui/icons/gnome-fs-loading-icon.png \
		ui/icons/gpm-primary-060-charging.png \
		ui/icons/security-medium.png \
		ui/icons/text_strike.png \
		ui/icons/gnome-searchtool.png \
		ui/icons/mail-mark-junk.png \
		ui/icons/mail-replied.png \
		ui/icons/stock_flip-vertically.png \
		ui/icons/gpm-primary-missing.png \
		ui/icons/stock_home.png \
		ui/icons/dialog-warning.png \
		ui/icons/stock_text-strikethrough.png \
		ui/icons/gpm-ups-060-charging.png \
		ui/icons/stock_mail-reply.png \
		ui/icons/list-add.png \
		ui/icons/gpm-ups-missing.png \
		ui/icons/package_development.png \
		ui/icons/stock_exit.png \
		ui/icons/stock_volume-min.png \
		ui/icons/gtk-sort-descending.png \
		ui/icons/fileopen.png \
		ui/icons/stock_text_indent.png \
		ui/icons/gnome-lockscreen.png \
		ui/icons/xfce-internet.png \
		ui/icons/gnome-joystick.png \
		ui/icons/preferences-system.png \
		ui/icons/application-exit.png \
		ui/icons/stock_new-dir.png \
		ui/icons/edittrash.png \
		ui/icons/folder-visiting.png \
		ui/icons/stock_mail-send-receive.png \
		ui/icons/xfce-trash_full.png \
		ui/icons/finish.png \
		ui/icons/stock_print-preview.png \
		ui/icons/go-first.png \
		ui/icons/gpm-primary-charged.png \
		ui/icons/media-playlist-repeat.png \
		ui/icons/stock_appointment-reminder.png \
		ui/icons/stock_volume-0.png \
		ui/icons/gpm-ups-100.png \
		ui/icons/gpm-phone-100.png \
		ui/icons/gtk-save.png \
		ui/icons/evolution-calendar.png \
		ui/icons/webdev-ok.png \
		ui/icons/package_settings.png \
		ui/icons/gpm-primary-080-charging.png \
		ui/icons/stock_format-page.png \
		ui/icons/webdev-config.png \
		ui/icons/evolution-tasks.png \
		ui/icons/stock_file-properties.png \
		ui/icons/stock_last.png \
		ui/icons/edit-paste.png \
		ui/icons/xfce-office.png \
		ui/icons/stock_bell.png \
		ui/icons/folder-open.png \
		ui/icons/gpm-brightness-kbd-invalid.png \
		ui/icons/gtk-home.png \
		ui/icons/document-save.png \
		ui/icons/gpm-keyboard-100.png \
		ui/icons/editdelete.png \
		ui/icons/stock_timer_stopped.png \
		ui/icons/messagebox_critical.png \
		ui/icons/gtk-edit.png \
		ui/icons/redhat-programming.png \
		ui/icons/error.png \
		ui/icons/lock.png \
		ui/icons/gpm-ups-000.png \
		ui/icons/reload_page.png \
		ui/icons/gtk-strikethrough.png \
		ui/icons/gnome-fs-trash-full.png \
		ui/icons/gnome-util.png \
		ui/icons/gtk-properties.png \
		ui/icons/gpm-ups-080.png \
		ui/icons/gtk-apply.png \
		ui/icons/stock_undelete.png \
		ui/icons/gtk-directory.png \
		ui/icons/stock_save-as.png \
		ui/icons/gtk-spell-check.png \
		ui/icons/applications-utilities.png \
		ui/icons/gnome-applications.png \
		ui/icons/gtk-italic.png \
		ui/icons/network-offline.png \
		ui/icons/redo.png \
		ui/icons/stock_new-24h-appointment-24.png \
		ui/icons/gnome-stock-text-indent.png \
		ui/icons/kfm_home.png \
		ui/icons/filenew.png \
		ui/icons/gnome-netstatus-error.png \
		ui/icons/list_client_ok.png \
		ui/icons/stock_timezone.png \
		ui/icons/stock_help-document.png \
		ui/icons/task-due.png \
		ui/icons/gnome-netstatus-idle.png \
		ui/icons/go-previous.png \
		ui/icons/forward.png \
		ui/icons/mail_new.png \
		ui/icons/webdev-cancel.png \
		ui/icons/connect_no.png \
		ui/icons/audio-volume-low.png \
		ui/icons/list_client_stopped.png \
		ui/icons/window_new.png \
		ui/icons/reload3.png \
		ui/icons/security-low.png \
		ui/icons/stock_people.png \
		ui/icons/gtk-go-forward-rtl.png \
		ui/icons/gpm-primary-040.png \
		ui/icons/redhat-system_settings.png \
		ui/icons/stock_book_yellow.png \
		ui/icons/stock_new-address-book.png \
		ui/icons/gnome-settings.png \
		ui/icons/application-pdf.png \
		ui/icons/stock_search-and-replace.png \
		ui/icons/dialog-information.png \
		ui/icons/user-trash-full.png \
		ui/icons/xfce-utils.png \
		ui/icons/evolution-addressbook.png \
		ui/icons/gpm-keyboard-060.png \
		ui/icons/media-playlist-shuffle.png \
		ui/icons/reload.png \
		ui/icons/stock_mail-replied.png \
		ui/icons/gtk-bold.png \
		ui/icons/gnome-netstatus-disconn.png \
		ui/icons/stock_drag-mode.png \
		ui/icons/stock_left.png \
		ui/icons/stock_save.png \
		ui/icons/edit-copy.png \
		ui/icons/gtk-cancel.png \
		ui/icons/info.png \
		ui/icons/document-print-preview.png \
		ui/icons/stock_notebook.png \
		ui/icons/format-text-strikethrough.png \
		ui/icons/folder-new.png \
		ui/icons/start.png \
		ui/icons/stock_dialog-warning.png \
		ui/icons/stock_book_red.png \
		ui/icons/stock_fullscreen.png \
		ui/icons/xfce-graphics.png \
		ui/icons/gtk-yes.png \
		ui/icons/stock_lock-ok.png \
		ui/icons/centrejust.png \
		ui/icons/stock_dialog-question.png \
		ui/icons/gtk-close.png \
		ui/icons/applications-internet.png \
		ui/icons/gtk-justify-left.png \
		ui/icons/dialog-error.png \
		ui/icons/gpm-brightness-kbd.png \
		ui/icons/editpaste.png \
		ui/icons/gpm-brightness-kbd-disabled.png \
		ui/icons/dialog-password.png \
		ui/icons/redhat-preferences.png \
		ui/icons/stock_new-bcard.png \
		ui/icons/list_client_inaccessible.png \
		ui/icons/edit-redo.png \
		ui/icons/filefind.png \
		ui/icons/stock_text_italic.png \
		ui/icons/next.png \
		ui/icons/up.png \
		ui/icons/date.png \
		ui/icons/stock_book_green.png \
		ui/icons/gtk-add.png \
		ui/icons/gtk-remove.png \
		ui/icons/preferences-desktop-peripherals.png \
		ui/icons/appointment-soon.png \
		ui/icons/stock_color.png \
		ui/icons/mail_replyall.png \
		ui/icons/edit-find.png \
		ui/icons/stock_calc-cancel.png \
		ui/icons/stock_new-meeting.png \
		ui/icons/gtk-print-preview.png \
		ui/icons/gtk-cdrom.png \
		ui/icons/add.png \
		ui/icons/stock_landline-phone.png \
		ui/icons/redhat-internet.png \
		ui/icons/battery-caution.png \
		ui/icons/stock_web-support.png \
		ui/icons/gtk-ok.png \
		ui/icons/stock_stop.png \
		ui/icons/battery-low.png \
		ui/icons/stock_timer.png \
		ui/icons/format-justify-fill.png \
		ui/icons/stock_keyring.png \
		ui/icons/gpm-ups-charged.png \
		ui/icons/gtk-dialog-info.png \
		ui/icons/gpm-ups-020.png \
		ui/icons/applications-accessories.png \
		ui/icons/stock_open.png \
		ui/icons/gnome-dev-wavelan-encrypted.png \
		ui/icons/folder_open.png \
		ui/icons/stock_shuffle.png \
		ui/icons/applications-office.png \
		ui/icons/stock_styles.png \
		ui/icons/fileprint.png \
		ui/icons/stock_first.png \
		ui/icons/stock_mail-forward.png \
		ui/icons/applications-games.png \
		ui/icons/stock_dialog-error.png \
		ui/icons/mail-signed-verified.png \
		ui/icons/document-open.png \
		ui/icons/stock_paste.png \
		ui/icons/appointment-missed.png \
		ui/icons/trashcan_full.png \
		ui/icons/format-text-underline.png \
		ui/icons/stock_person.png \
		ui/icons/stock_undo.png \
		ui/icons/system-search.png \
		ui/icons/gtk-cut.png \
		ui/icons/down.png \
		ui/icons/task-past-due.png \
		ui/icons/gtk-paste.png \
		ui/icons/gtk-print.png \
		ui/icons/xfce-system.png \
		ui/icons/list-remove.png \
		ui/icons/document-new.png \
		ui/icons/stock_book_open.png \
		ui/icons/system-lock-screen.png \
		ui/icons/stock_volume-max.png \
		ui/icons/text_bold.png \
		ui/icons/format-justify-center.png \
		ui/icons/edit-find-replace.png \
		ui/icons/important.png \
		ui/icons/applications-development.png \
		ui/icons/gpm-ups-100-charging.png \
		ui/icons/contact-new.png \
		ui/icons/list_client_asynch.png \
		ui/icons/bottom.png \
		ui/icons/stock_notes.png \
		ui/icons/gpm-mouse-100.png \
		ui/icons/gpm-phone-060.png \
		ui/icons/preferences-system-network.png \
		ui/icons/gpm-primary-020.png \
		ui/icons/audio-volume-medium.png \
		ui/icons/package_utilities.png \
		ui/icons/gtk-disconnect.png \
		ui/icons/gtk-goto-first-ltr.png \
		ui/icons/filequickprint.png \
		ui/icons/nm-adhoc.png \
		ui/icons/package_games.png \
		ui/icons/gtk-dialog-question.png \
		ui/icons/gpm-inhibit-invalid.png \
		ui/icons/stock_copy.png \
		ui/icons/network-idle.png \
		ui/icons/printer-error.png \
		ui/icons/gtk-go-back-rtl.png \
		ui/icons/format-justify-right.png \
		ui/icons/stock_text_underlined.png \
		ui/icons/stock_mail-reply-to-all.png \
		ui/icons/stock_autopilot.png \
		ui/icons/gpm-mouse-030.png \
		ui/icons/gtk-goto-bottom.png \
		ui/icons/mail_spam.png \
		ui/icons/xfce-games.png \
		ui/icons/stock_folder-copy.png \
		ui/icons/stock_help-book.png \
		ui/icons/gtk_fullscreen.png \
		ui/icons/applications-other.png \
		ui/icons/gtk-open.png \
		ui/icons/address-book-new.png \
		ui/icons/preferences-desktop-personal.png \
		ui/icons/webdev-arrow-down.png \
		ui/icons/bookmark_add.png \
		ui/icons/redhat-office.png \
		ui/icons/stock_extended-help.png \
		ui/icons/stock_mail-unread.png \
		ui/icons/stock_internet.png \
		ui/icons/stock_new-text.png \
		ui/icons/mail-reply-sender.png \
		ui/icons/text_italic.png \
		ui/icons/stock_lock-open.png \
		ui/icons/stock_web-calendar.png \
		ui/icons/mail.png \
		ui/icons/top.png \
		ui/icons/gpm-ups-040-charging.png \
		ui/icons/gnome-graphics.png \
		ui/icons/audio-volume-muted.png \
		ui/icons/bookmarks_list_add.png \
		ui/icons/connect_established.png \
		ui/icons/stock_file-properites.png \
		ui/icons/stock_volume-mute.png \
		ui/icons/list_client_inactive.png \
		ui/icons/stock_top.png \
		ui/icons/mail-send-receive.png \
		ui/icons/stock_text_center.png \
		ui/icons/go-bottom.png \
		ui/icons/gnome-stock-text-unindent.png \
		ui/icons/stock_about.png \
		ui/icons/gnome-fs-directory-accept.png \
		ui/icons/back.png \
		ui/icons/stock_trash_full.png \
		ui/icons/gpm-primary-100.png \
		ui/icons/bookmark-new.png \
		ui/icons/stock_text_right.png \
		ui/icons/gpm-brightness-lcd-disabled.png \
		ui/icons/nm-device-wireless.png \
		ui/icons/redhat-system_tools.png \
		ui/icons/format-indent-more.png \
		ui/icons/search.png \
		ui/icons/package_network.png \
		ui/icons/stock_redo.png \
		ui/icons/gtk-find-and-replace.png \
		ui/icons/gtk-dialog-warning.png \
		ui/icons/gnome-netstatus-rx.png \
		ui/icons/editcut.png \
		ui/icons/window_fullscreen.png \
		ui/icons/find.png \
		ui/icons/gpm-primary-020-charging.png \
		ui/icons/gpm-mouse-000.png \
		ui/icons/applications-system.png \
		ui/icons/gtk-justify-right.png \
		ui/icons/gtk-justify-center.png \
		ui/icons/gpm-ups-040.png \
		ui/icons/gpm-ups-020-charging.png \
		ui/icons/gtk-sort-ascending.png \
		ui/icons/stock_refresh.png \
		ui/icons/view-refresh.png \
		ui/icons/stock_print.png \
		ui/icons/gnome-multimedia.png \
		ui/icons/gtk-goto-last-ltr.png \
		ui/icons/connect_creating.png \
		ui/icons/stock_send-fax.png \
		ui/icons/gtk-dialog-error.png \
		ui/icons/image-missing.png \
		ui/icons/gtk-preferences.png \
		ui/icons/image-loading.png \
		ui/icons/process-stop.png \
		ui/icons/edit-select-all.png \
		ui/icons/gtk-goto-first-rtl.png \
		ui/icons/xfce-devel.png \
		ui/icons/gtk-new.png \
		ui/icons/stock_volume-med.png \
		ui/icons/redhat-accessories.png \
		ui/icons/stock_search.png \
		ui/icons/gtk-undo-ltr.png \
		ui/icons/stock_not.png \
		ui/icons/security-high.png \
		ui/icons/stock_repeat.png \
		ui/icons/gpm-primary-040-charging.png \
		ui/icons/mail-read.png \
		ui/icons/format-indent-less.png \
		ui/icons/system-help.png \
		ui/icons/gpm-primary-100-charging.png \
		ui/icons/stock_new-tab.png \
		ui/icons/go-down.png \
		ui/icons/gpm-ups-000-charging.png \
		ui/icons/gnome-stock-trash-full.png \
		ui/icons/stock_attach.png \
		ui/icons/gtk-dialog-authentication.png \
		ui/icons/stock_cut.png \
		ui/icons/stock_check-filled.png \
		ui/icons/format-text-italic.png \
		ui/icons/kcontrol.png \
		ui/icons/stock_help-book-open.png \
		ui/icons/stock_active.png \
		ui/icons/applications-multimedia.png \
		ui/icons/network-error.png \
		ui/icons/gohome.png \
		ui/icons/mail-message-new.png \
		ui/icons/mail-unread.png \
		ui/icons/gtk-unindent.png \
		ui/icons/document-print.png \
		ui/icons/gpm-phone-000.png \
		ui/icons/package_graphics.png \
		ui/icons/stock_add-bookmark.png \
		ui/icons/stock_lock.png \
		ui/icons/gpm-primary-000.png \
		ui/icons/dialog-question.png \
		ui/icons/reload_all_tabs.png \
		ui/icons/stop.png \
		ui/icons/rightjust.png \
		ui/icons/format-text-bold.png \
		ui/icons/gtk-go-forward-ltr.png \
		ui/icons/applications-graphics.png \
		ui/icons/stock_text_bold.png \
		ui/icons/network-wireless-encrypted.png \
		ui/icons/format-justify-left.png \
		ui/icons/gtk-refresh.png \
		ui/icons/gnome-netstatus-txrx.png \
		ui/icons/gpm-brightness-lcd-invalid.png \
		ui/icons/gpm-primary-080.png \
		ui/icons/stock_folder-properties.png \
		ui/icons/system-shutdown.png \
		ui/icons/stock_up.png \
		ui/icons/redhat-graphics.png \
		ui/icons/go-top.png \
		ui/icons/printer-printing.png \
		ui/icons/undo.png \
		ui/icons/evolution-contacts.png \
		ui/icons/gtk-go-down.png \
		ui/icons/gtk-copy.png \
		ui/icons/bookmark.png \
		ui/icons/previous.png \
		ui/icons/gnome-fs-directory-visiting.png \
		ui/icons/document-save-as.png \
		ui/icons/filesave.png \
		ui/icons/stock_mark.png \
		ui/icons/network-transmit-receive.png \
		ui/icons/go-last.png \
		ui/icons/gtk-no.png \
		ui/icons/text_under.png \
		ui/icons/gpm-primary-000-charging.png \
		ui/icons/gtk-missing-image.png \
		ui/icons/edit-delete.png \
		ui/icons/stock_task.png \
		ui/icons/stock_folder-move.png \
		ui/icons/xfce-multimedia.png \
		ui/icons/xfce-system-settings.png \
		ui/icons/stock_lock-broken.png \
		ui/icons/messagebox_info.png \
		ui/icons/kfind.png \
		ui/icons/gpm-mouse-060.png \
		ui/icons/stock_calc-accept.png \
		ui/icons/stock_select-all.png \
		ui/icons/stock_summary.png \
		ui/icons/gpm-keyboard-030.png \
		ui/icons/gtk-goto-last-rtl.png \
		ui/icons/document-properties.png \
		ui/icons/package_multimedia.png \
		ui/icons/stock_volume.png \
		ui/icons/gtk-redo-ltr.png \
		ui/icons/mail-signed.png \
		ui/icons/stock_connect.png \
		ui/icons/folder_new.png \
		ui/icons/gnome-netstatus-tx.png \
		ui/icons/gnome-globe.png \
		ui/icons/package_office.png \
		ui/icons/xfce-system-lock.png \
		ui/icons/gpm-brightness-lcd.png \
		ui/icons/appointment.png \
		ui/icons/gtk-stop.png \
		ui/icons/audio-volume-high.png \
		ui/icons/mail-forward.png \
		ui/icons/stock_appointment-reminder-excl.png \
		ui/icons/gnome-devel.png \
		ui/icons/gtk-indent.png \
		ui/icons/gpm-phone-030.png \
		ui/icons/gtk-justify-fill.png \
		ui/icons/go-next.png \
		ui/icons/gtk-go-up.png \
		ui/icons/gnome-control-center.png \
		ui/icons/editcopy.png \
		ui/icons/mail-reply-all.png \
		ui/icons/go-up.png \
		ui/icons/preferences-desktop.png \
		ui/icons/stock_news.png \
		ui/icons/stock_down.png \
		ui/icons/gtk-go-back-ltr.png \
		ui/icons/stock_3d-favourites.png \
		ui/icons/messagebox_warning.png \
		ui/icons/tab-new.png \
		ui/icons/stock_right.png \
		ui/icons/gtk-underline.png \
		ui/icons/gpm-inhibit.png \
		ui/icons/gnome-system.png \
		ui/icons/input_devices_settings.png \
		ui/icons/view_fullscreen.png \
		ui/icons/mail-attachment.png \
		ui/icons/stock_edit.png \
		ui/icons/network-transmit.png \
		ui/icons/applications-science.png \
		ui/icons/gpm-ups-060.png \
		ui/icons/software-update-available.png \
		ui/icons/leftjust.png \
		ui/icons/stock_presentation-styles.png \
		ui/icons/appointment-new.png \
		ui/icons/stock_disconnect.png \
		ui/icons/stock_text_left.png \
		ui/icons/stock_autocompletion.png \
		ui/icons/folder-drag-accept.png \
		ui/icons/nm-no-connection.png \
		ui/icons/stock_mail-open.png \
		ui/dna/DNA_off.png \
		ui/dna/DNA_on.png
	/usr/bin/rcc -name foldwatcher ui/foldwatcher.qrc -o qrc_foldwatcher.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_aboutdialog.h build/ui_clientlist.h build/ui_logwindow.h build/ui_mainwindow.h build/ui_monitor.h build/ui_personalstats.h build/ui_preferences.h build/ui_proteininfo.h build/ui_teamstats.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_aboutdialog.h build/ui_clientlist.h build/ui_logwindow.h build/ui_mainwindow.h build/ui_monitor.h build/ui_personalstats.h build/ui_preferences.h build/ui_proteininfo.h build/ui_teamstats.h
build/ui_aboutdialog.h: ui/aboutdialog.ui
	/usr/bin/uic-qt4 ui/aboutdialog.ui -o build/ui_aboutdialog.h

build/ui_clientlist.h: ui/clientlist.ui
	/usr/bin/uic-qt4 ui/clientlist.ui -o build/ui_clientlist.h

build/ui_logwindow.h: ui/logwindow.ui
	/usr/bin/uic-qt4 ui/logwindow.ui -o build/ui_logwindow.h

build/ui_mainwindow.h: ui/mainwindow.ui
	/usr/bin/uic-qt4 ui/mainwindow.ui -o build/ui_mainwindow.h

build/ui_monitor.h: ui/monitor.ui
	/usr/bin/uic-qt4 ui/monitor.ui -o build/ui_monitor.h

build/ui_personalstats.h: ui/personalstats.ui
	/usr/bin/uic-qt4 ui/personalstats.ui -o build/ui_personalstats.h

build/ui_preferences.h: ui/preferences.ui
	/usr/bin/uic-qt4 ui/preferences.ui -o build/ui_preferences.h

build/ui_proteininfo.h: ui/proteininfo.ui
	/usr/bin/uic-qt4 ui/proteininfo.ui -o build/ui_proteininfo.h

build/ui_teamstats.h: ui/teamstats.ui
	/usr/bin/uic-qt4 ui/teamstats.ui -o build/ui_teamstats.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/AnalogClock.o: src/AnalogClock.cpp src/AnalogClock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/AnalogClock.o src/AnalogClock.cpp

build/Messages.o: src/Messages.cpp src/foldwatcher_consts.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Messages.o src/Messages.cpp

build/aboutDialog.o: src/aboutDialog.cpp src/aboutDialog.h \
		build/ui_aboutdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/aboutDialog.o src/aboutDialog.cpp

build/clientList.o: src/clientList.cpp src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/fah_consts.h \
		src/foldwatcher_consts.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/clientList.o src/clientList.cpp

build/fahClient.o: src/fahClient.cpp src/fah_consts.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		src/foldwatcher_consts.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fahClient.o src/fahClient.cpp

build/fahQueue.o: src/fahQueue.cpp src/fah_consts.h \
		src/fahQueue.h \
		src/foldwatcher_consts.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fahQueue.o src/fahQueue.cpp

build/fahUnitinfo.o: src/fahUnitinfo.cpp src/fahUnitinfo.h \
		src/foldwatcher_consts.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fahUnitinfo.o src/fahUnitinfo.cpp

build/fahWuinfo.o: src/fahWuinfo.cpp src/fahQueue.h \
		src/fahWuinfo.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahUnitinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fahWuinfo.o src/fahWuinfo.cpp

build/fahWulist.o: src/fahWulist.cpp src/fahWulist.h \
		src/foldwatcher_consts.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/fahWulist.o src/fahWulist.cpp

build/logWindow.o: src/logWindow.cpp src/logWindow.h \
		build/ui_logwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/logWindow.o src/logWindow.cpp

build/main.o: src/main.cpp src/mainWindow.h \
		build/ui_mainwindow.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/mainWindow.o: src/mainWindow.cpp src/aboutDialog.h \
		build/ui_aboutdialog.h \
		src/AnalogClock.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/fah_consts.h \
		src/foldwatcher_consts.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/Messages.h \
		src/preferences.h \
		build/ui_preferences.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/mainWindow.o src/mainWindow.cpp

build/monitor.o: src/monitor.cpp src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		src/Messages.h \
		src/monitor.h \
		build/ui_monitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/monitor.o src/monitor.cpp

build/personalStats.o: src/personalStats.cpp src/aboutDialog.h \
		build/ui_aboutdialog.h \
		src/AnalogClock.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/fah_consts.h \
		src/foldwatcher_consts.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/personalStats.o src/personalStats.cpp

build/preferences.o: src/preferences.cpp src/Messages.h \
		src/preferences.h \
		build/ui_preferences.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/preferences.o src/preferences.cpp

build/proteinInfo.o: src/proteinInfo.cpp src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/proteinInfo.o src/proteinInfo.cpp

build/teamStats.o: src/teamStats.cpp src/aboutDialog.h \
		build/ui_aboutdialog.h \
		src/clientList.h \
		src/fahClient.h \
		src/fahQueue.h \
		src/fahUnitinfo.h \
		src/fahWuinfo.h \
		src/fahWulist.h \
		build/ui_clientlist.h \
		src/fah_consts.h \
		src/foldwatcher_consts.h \
		src/logWindow.h \
		build/ui_logwindow.h \
		src/mainWindow.h \
		build/ui_mainwindow.h \
		src/AnalogClock.h \
		src/teamStats.h \
		build/ui_teamstats.h \
		src/personalStats.h \
		build/ui_personalstats.h \
		src/proteinInfo.h \
		build/ui_proteininfo.h \
		src/monitor.h \
		build/ui_monitor.h \
		src/Messages.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/teamStats.o src/teamStats.cpp

build/moc_AnalogClock.o: build/moc_AnalogClock.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_AnalogClock.o build/moc_AnalogClock.cpp

build/moc_aboutDialog.o: build/moc_aboutDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_aboutDialog.o build/moc_aboutDialog.cpp

build/moc_clientList.o: build/moc_clientList.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_clientList.o build/moc_clientList.cpp

build/moc_logWindow.o: build/moc_logWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_logWindow.o build/moc_logWindow.cpp

build/moc_mainWindow.o: build/moc_mainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_mainWindow.o build/moc_mainWindow.cpp

build/moc_monitor.o: build/moc_monitor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_monitor.o build/moc_monitor.cpp

build/moc_personalStats.o: build/moc_personalStats.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_personalStats.o build/moc_personalStats.cpp

build/moc_preferences.o: build/moc_preferences.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_preferences.o build/moc_preferences.cpp

build/moc_proteinInfo.o: build/moc_proteinInfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_proteinInfo.o build/moc_proteinInfo.cpp

build/moc_teamStats.o: build/moc_teamStats.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_teamStats.o build/moc_teamStats.cpp

build/qrc_foldwatcher.o: qrc_foldwatcher.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_foldwatcher.o qrc_foldwatcher.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

