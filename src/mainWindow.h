#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QMainWindow>
#include <QMdiArea>
#include <QTimer>
#include <QFile>
#include <QSystemTrayIcon>
#include "ui_mainwindow.h"
#include "logWindow.h"
#include "clientList.h"
#include "AnalogClock.h"
#include "teamStats.h"
#include "personalStats.h"
#include "proteinInfo.h"
#include "monitor.h"


class mainWindow : public QMainWindow, public Ui::mainWindow
{
Q_OBJECT
public:
	mainWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
	
	void createDocks();
	void makeConnections();
	void showStartupMessage();
	void loadConfig();
	void verifyFinstall();
	void reloadFAHLOG(int clno);
	bool verifiedDir (QString dir);
	
	logWindow *log;
	proteinInfo *info;
	logWindow *unitinfo_log;
	logWindow *fahlog_log;
	logWindow *currentxyz_log;
	
	QFile *FAHLog;
	
	
	clientList *clients;
	teamStats *TeamStats;
	personalStats *PersonalStats;
	AnalogClock *analogClock;
	monitor *Monitor;
	QTimer *Reloader;
	QTimer PPDer;
	int reloadTime;
	
private slots:
	
	void show_aboutDialog();
	void show_preferences();
	void startFolding();
	void stopFolding();
	void loadHomepage();
	void contactAuthor();
	void addClient();
	void removeClient();
	void loadSourceForge();
	void loadFoldingWebsite();
	void loadFoldingForum();
	void saveConfig();
	void reloadClients();
	void reloadPersonalStats();
	void reloadTeamStats();
	void showInfo();
	void showMolecule();
	void checkExit();

private:
	void saveLayout();
	void loadLayout();
	void createTrayIcon();
	quint32 es32(quint32 i);
	QMdiArea *mdiArea;
	QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
	
};
#endif




