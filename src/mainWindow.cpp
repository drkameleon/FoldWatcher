// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : mainWindow.cpp
// Last Update : 19/05/2008
//
// -----------------------------------------------------------------
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2008 by Dr.K@meleon
// ========================================================

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QtGui>
#include <QProcess>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QProgressDialog>
#include <QTimer>
#include <QFile>
#include <QTextBrowser>
#include <QDockWidget>
#include <QByteArray>
#include <QTextCodec>

#include "aboutDialog.h"
#include "AnalogClock.h"
#include "clientList.h"
#include "fah_consts.h"
#include "fahClient.h"
#include "fahQueue.h"
#include "fahWuinfo.h"
#include "foldwatcher_consts.h" 
#include "logWindow.h"
#include "mainWindow.h"
#include "Messages.h"
#include "monitor.h"
#include "personalStats.h"
#include "preferences.h"
#include "proteinInfo.h"
#include "teamStats.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
	setupUi(this);
	reloadTime = 1;
	
    createDocks();    
	makeConnections();
	
	showMaximized();
	loadConfig();
	verifyFinstall();
	
	createTrayIcon();
	trayIcon->show();
	Monitor->setEnabled(false);
	
}

void mainWindow::verifyFinstall()
{
	QString ll = "-- Looking for 'finstall' script... ";
	QFile file (FAH_FINSTALL);
	if (!file.exists()) 
	{
		actionStart->setEnabled(false);
		actionStop->setEnabled(false);
		WARN(FW_NAME,"/etc/init.d/folding script not found! \n"
		"Either no F@H client is installed or clients where not installed using the 'finstall' script.\n\n"
	    	"You may solve this by using the exexuting again the 'install' script and "
	    	"choose 'yes' when prompted to install Folding@Home. Otherwise the 'start/stop' options will remain disabled.");
	    ll = ll + "<b>[NOT FOUND]</b>";
	} else ll = ll + "[OK]";
	
	log->mainLogger->append(ll);
}

void mainWindow::loadConfig()
{
	QString ll = "-- Looking for configuration file... ";
	QString ll2 = "-- Loading clients...";
		QFile config (FW_CONFIG);
	if (config.exists())
	{
		if (!config.open(QIODevice::ReadOnly | QIODevice::Text)) 
		{
			WARN(FW_NAME,"Configuration file (foldwatcher.cfg) could not be loaded!\n\n"
	 			"You may add new clients and push the 'save' button to get them loaded each time the program starts up.\n\n"
	 			"After you have added as many clients as you wish, you may then choose a client "
	 			"by clicking on it in the 'Clients' window, to view further information"
	 			"for the WU currently being processed.");
	 		ll = ll + "<b>[NOT FOUND]</b>";
	 		log->mainLogger->append(ll);
			return;
		}
    	ll = ll + "[OK]";
	 	log->mainLogger->append(ll);
	 	log->mainLogger->append(ll2);
    	while (!config.atEnd()) {
        	QString line = config.readLine();
        	if (line.startsWith("%"))
        	{
        		QString theLine = line;
        		theLine.remove(0,1);
        		QStringList lista = theLine.split(", ");
        		clients->add(lista.at(0).simplified(), lista.at(1).simplified());
        		log->mainLogger->append("------ added Client( ID: "+lista.at(0).simplified()+"  Path: "+lista.at(1).simplified()+" )");
        		actionRemoveClient->setEnabled(true);
        		actionPersonalStats->setEnabled(true);
    			actionTeamStats->setEnabled(true);
    			actionMoleculeViewer->setEnabled(true);
    			actionSaveConfig->setEnabled(true);
    			actionPreferences->setEnabled(true);
			}
		}
	} else
	{
		MSG(FW_NAME,"Configuration file (foldwatcher.cfg) was not found!\n\n"
	 			"You may add new clients and push the 'save' button to get them loaded each time the program starts up.\n\n"
	 			"After you have added as many clients as you wish, you may then choose a client "
	 			"by clicking on it in the 'Clients' window, to view further information "
	 			"for the WU currently being processed.");
	 	actionRemoveClient->setEnabled(false);
	 	actionStart->setEnabled(false);
	 	actionStop->setEnabled(false);
	 	actionPersonalStats->setEnabled(false);
    	actionTeamStats->setEnabled(false);
    	actionMoleculeViewer->setEnabled(false);
    	actionSaveConfig->setEnabled(false);
    	actionPreferences->setEnabled(false);
    	ll = ll + "<b>[NOT FOUND]</b>";
	 	log->mainLogger->append(ll);
 	}
	config.close();
	
}

void mainWindow::reloadFAHLOG(int clno)
{
	
	FAHLog = new QFile(clients->Client[clno]->Path+FAH_FAHLOG);
	fahlog_log->mainLogger->clear();
	if (!FAHLog->open(QIODevice::ReadOnly | QIODevice::Text)) return;
    while (!FAHLog->atEnd()) 
	{
    	QString line = FAHLog->readLine();
    	fahlog_log->mainLogger->append(line.simplified());
	}
	FAHLog->close();
}

void mainWindow::createTrayIcon()
{
     QAction *minimizeAction = new QAction(tr("Mi&nimize"), this);
     connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

     QAction *maximizeAction = new QAction(tr("Ma&ximize"), this);
     connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

     QAction *restoreAction = new QAction(tr("&Restore"), this);
     connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

     trayIconMenu = new QMenu(this);
     trayIconMenu->addAction(minimizeAction);
     trayIconMenu->addAction(maximizeAction);
     trayIconMenu->addAction(restoreAction);
     trayIconMenu->addSeparator();
     trayIconMenu->addAction(actionExit);

     trayIcon = new QSystemTrayIcon(this);
     trayIcon->setToolTip(QString(FW_NAME));
     trayIcon->setContextMenu(trayIconMenu);
     trayIcon->setIcon(QIcon(":/logo/logo/greenCube.png"));
}

void mainWindow::makeConnections()
{
	QObject::connect(actionAbout, SIGNAL( triggered() ), this, SLOT( show_aboutDialog() ) );
	QObject::connect(actionPreferences, SIGNAL( triggered() ), this, SLOT( show_preferences() ) );
	QObject::connect(actionStart, SIGNAL( triggered() ), this, SLOT( startFolding() ) );
	QObject::connect(actionStop, SIGNAL( triggered() ), this, SLOT( stopFolding() ) );
	QObject::connect(actionHomepage, SIGNAL( triggered() ), this, SLOT( loadHomepage() ) );
	QObject::connect(actionSourceForge, SIGNAL( triggered() ), this, SLOT( loadSourceForge() ) );
	QObject::connect(actionFoldingWebsite, SIGNAL( triggered() ), this, SLOT( loadFoldingWebsite() ) );
	QObject::connect(actionFoldingForum, SIGNAL( triggered() ), this, SLOT( loadFoldingForum() ) );
	QObject::connect(actionContact, SIGNAL( triggered() ), this, SLOT( contactAuthor() ) );
	QObject::connect(actionAddClient, SIGNAL( triggered() ), this, SLOT( addClient() ) );
	QObject::connect(actionRemoveClient, SIGNAL( triggered() ), this, SLOT( removeClient() ) );
	QObject::connect(actionSaveConfig, SIGNAL( triggered() ), this, SLOT( saveConfig() ) );
	QObject::connect(actionPersonalStats, SIGNAL( triggered() ), this, SLOT( reloadPersonalStats() ) );
	QObject::connect(actionTeamStats, SIGNAL( triggered() ), this, SLOT( reloadTeamStats() ) );
	QObject::connect(actionMoleculeViewer, SIGNAL( triggered() ), this, SLOT( showMolecule() ) );
	QObject::connect(actionExit, SIGNAL(triggered()), this, SLOT(checkExit()));

	
	QObject::connect(clients->table, SIGNAL( cellClicked( int, int) ), this, SLOT( showInfo()));
	
	Reloader = new QTimer(this);
    	connect(Reloader, SIGNAL(timeout()), this, SLOT(reloadClients()));
    	Reloader->start(60000);
}

void mainWindow::checkExit()
{
	if (ASK("Are you sure you want to exit?")) 
		qApp->quit();
}

void mainWindow::showMolecule()
{
	QString ll  = "-- Looking for RasMol molecule viewer... ";
	QString ll2 = "-- Looking for xyz2pdb converter... ";
	QString ll3 = "-- Loading Molecule Viewer... ";
	QProcess *proc = new QProcess(this);
	QProcess *rasmol = new QProcess(this);
	QFile rasmolFile("/usr/bin/rasmol");
	int index = clients->table->currentRow();
	
	if (index==-1)
	{
		WARN(FW_NAME, "You didn't select any client, to perform this action!\n\n"
					"Please go first to the 'Clients' window and select one by clicking on it.");
		return; 
	}
	
	if (rasmolFile.exists())
	{
		ll = ll + "[OK]";
		log->mainLogger->append(ll);
		QString pa = clients->Client[index]->Path + "work/current.xyz";
		QFile xyz2pdb(FW_XYZ2PDB);
		if (!xyz2pdb.exists())
		{
			ll2 = ll2 + "<b>[NOT FOUND]</b>";
			log->mainLogger->append(ll2);
			WARN("Tools / Molecule Viewer","XYZ-to-PDB conversion utility not found! (xyz2pdb)\n"
   				"FoldWatcher is now going to use the JMol Molecule Viewer through the internet");
   			QString page = "http://jmol.sourceforge.net/fah/?project=" + clients->Client[index]->ProjectNo;
   										
   			proc->start("firefox", QStringList() << page);
   			ll3 = ll3 + "[OK]";
   			log->mainLogger->append(ll3);							
			return;
		} else
		{
			ll2 = ll2 + "[OK]";
			log->mainLogger->append(ll2);
			proc->start(FW_XYZ2PDB, QStringList() <<  "-xyzfile" << pa << "-o" << "current.pdb" );
    		rasmol->start(FW_RASMOL, QStringList() << "current.pdb");
    		ll3 = ll3 + "[OK]";
   			log->mainLogger->append(ll3);
   		}
   	} else 
   	{
   		ll = ll + "<b>[NOT FOUND]</b>";
   		log->mainLogger->append(ll);
   		WARN("Tools / Molecule Viewer","RasMol Molecule Viewer is NOT installed. You can install it by typing 'sudo apt-get install rasmol'.\n"
   				"FoldWatcher is now going to use the JMol Molecule Viewer through the internet");
   		
   		QString page = "http://jmol.sourceforge.net/fah/?project=" + clients->Client[index]->ProjectNo;
   										
   		proc->start("firefox", QStringList() << page);
   		ll3 = ll3 + "[OK]";
   		log->mainLogger->append(ll3);
  		
  	}
}

void mainWindow::showInfo()
{
	int index = clients->table->currentRow();
	
	if (!Monitor->isEnabled()) 
	{
		if (clients->Client[index]->nStatus == FAH_FOLDING)
		{			
			Monitor->setEnabled(true);
			Monitor->startAnimation();
		}
	}
	
	info->print(clients->Client[index]);
	Monitor->print(clients->Client[index], clients->NOC);
	reloadFAHLOG(index);
}

void mainWindow::reloadTeamStats()
{
	int index = clients->table->currentRow();
	
	if (index==-1)
	{
		WARN(FW_NAME, "You didn't select any client, to perform this action!\n\n"
					"Please go first to the 'Clients' window and select one by clicking on it.");
		return; 
	}
	
	TeamStats->reload(clients->Client[index]->TeamNo);
}

void mainWindow::reloadPersonalStats()
{
	int index = clients->table->currentRow();
	
	if (index==-1)
	{
		WARN(FW_NAME, "You didn't select any client, to perform this action!\n\n"
					"Please go first to the 'Clients' window and select one by clicking on it.");
		return; 
	}
	
	PersonalStats->reload(clients->Client[index]->TeamNo, clients->Client[index]->Username);
}

void mainWindow::reloadClients()
{
	bool SomethingChanged = true;
	/*for (int k=0; k<clients->NOC; k++)
	{
		clients->Client[k]->w->reload();
		if (clients->Client[k]->w->nCompleted !=clients->Client[k]->nCompleted)
		{
			SomethingChanged = true;
		}
	}
*/
	if (SomethingChanged)
	{
		int index = clients->table->currentRow();
		
		clients->reload();
		
		
		if (index!=-1) 
		{
			Monitor->print(clients->Client[index], clients->NOC);
			info->print(clients->Client[index]);
			reloadFAHLOG(index);
		}
		
		QDateTime now = QDateTime::currentDateTime();
		log->mainLogger->append("-- Clients automatically reloaded. [ "+now.toString()+" ]");
		
		
	}
}

void mainWindow::saveConfig()
{
	
	QFile file(FW_CONFIG);
    
    	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    
	QTextStream out(&file);
    
    	out << "##" << FW_NAME << " - Coded by " << FW_AUTHOR << "\n";
    	out << "##--------------------------------\n";
    	out << "##Configuration file\n\n";
    
    	out << "Number of Clients :" << QString::number(clients->NOC) << "\n";
    	for (int h = 0; h < clients->NOC; h++)
    		out << "%"<< clients->Client[h]->ID << ", " << clients->Client[h]->Path << "\n";
    
    	file.close();
    	saveLayout();
    	log->mainLogger->append("-- Saving configuration... [OK]");
}

void mainWindow::saveLayout()
{
	QFile file("foldwatcher.lot");
     	if (!file.open(QFile::WriteOnly)) return;
     
     	QByteArray geo_data = saveGeometry();
     	QByteArray layout_data = saveState();

     	bool ok = file.putChar((uchar)geo_data.size());
     	if (ok)
         	ok = file.write(geo_data) == geo_data.size();
     	if (ok)
         	ok = file.write(layout_data) == layout_data.size();


     	if (!ok) return;
     		file.close();
 }

void mainWindow::loadLayout()
{

     	QFile file("foldwatcher.lot");
     	if (!file.open(QFile::ReadOnly)) return;

     	uchar geo_size;
     	QByteArray geo_data;
     	QByteArray layout_data;

     	bool ok = file.getChar((char*)&geo_size);
     	if (ok) 
	{
        	geo_data = file.read(geo_size);
         	ok = geo_data.size() == geo_size;
     	}
     	if (ok) 
	{
        	layout_data = file.readAll();
        	ok = layout_data.size() > 0;
     	}

     	if (ok)
        	ok = restoreGeometry(geo_data);
     	if (ok)
        	ok = restoreState(layout_data);

     	if (!ok) return;
     	file.close();
}

void mainWindow::showStartupMessage()
{
	QStringList ql1 = QStringList() << FW_STARTUPMSG1;
	QStringList ql2 = QStringList() << FW_STARTUPMSG2;
	QStringList ql3 = QStringList() << FW_STARTUPMSG3;
	QStringList ql4 = QStringList() << FW_STARTUPMSG4;
	QString startup1 = ql1.join("");
	QString startup2 = ql2.join("");
	QString startup3 = ql3.join("");
	QString startup4 = ql4.join("");
	log->mainLogger->append(startup1);
	log->mainLogger->append(startup2);
	log->mainLogger->append(startup3);
	log->mainLogger->append(startup4);
	log->mainLogger->append("");
}

void mainWindow::createDocks()
{

	Monitor = new monitor();
	setCentralWidget(Monitor);
	
	setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
 	setCorner(Qt::BottomLeftCorner, Qt::BottomDockWidgetArea);
 	setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
 	setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
	
	
	setDockOptions(QMainWindow::ForceTabbedDocks|QMainWindow::VerticalTabs);
	
	/////////
	/// Create and dock the Log window
	///////////////////////////
	
	log = new logWindow();
	showStartupMessage();
	
	QDockWidget *log_dock = new QDockWidget(tr("FoldWatcher Log"), this);
    	log_dock->setWidget(log);
    
    	log_dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    	addDockWidget(Qt::BottomDockWidgetArea, log_dock);
    	
    	/////////
	/// Create and dock the FAHLog window
	///////////////////////////
	
	fahlog_log = new logWindow();
	
	QDockWidget *fahlog_dock = new QDockWidget(tr("FAHlog.txt"), this);
    	fahlog_dock->setWidget(fahlog_log);
    
    	fahlog_dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    	addDockWidget(Qt::BottomDockWidgetArea, fahlog_dock);
    
    	/////////
    	/// Create and dock the Clients' List window
    	///////////////////////////
    
    	clients = new clientList();
        
    	QDockWidget *clients_dock = new QDockWidget(tr("Clients"), this);
    	clients_dock->setWidget(clients);
    
    	clients_dock->setAllowedAreas(Qt::BottomDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea, clients_dock);
    
    	tabifyDockWidget(clients_dock, log_dock);
    
    	/////////
    	/// Create and dock the Information window
    	///////////////////////////
    
    	info = new proteinInfo();
    
    	QDockWidget *info_dock = new QDockWidget(tr("Protein information"), this);
    	info_dock->setWidget(info);
    
    	info_dock->setAllowedAreas(Qt::RightDockWidgetArea);
    	addDockWidget(Qt::RightDockWidgetArea, info_dock);
    
   	/////////
    	/// Create and dock the Team Stats window
    	///////////////////////////
    
    	TeamStats = new teamStats();
    	QDockWidget *team_dock = new QDockWidget(tr("Team Statistics"), this);
    	team_dock->setWidget(TeamStats);
    
    	team_dock->setAllowedAreas(Qt::RightDockWidgetArea);
    	addDockWidget(Qt::RightDockWidgetArea, team_dock);
    
    
    	/////////
    	/// Create and dock the Personal Stats window
    	///////////////////////////
    
    	PersonalStats = new personalStats();
    
    	QDockWidget *personal_dock = new QDockWidget(tr("Personal Statistics"), this);
    	personal_dock->setWidget(PersonalStats);
    
    	personal_dock->setAllowedAreas(Qt::RightDockWidgetArea);
    
    	addDockWidget(Qt::RightDockWidgetArea, personal_dock);
    
    
	/////////
	/// Create and dock the Analog Clock window
    	///////////////////////////
    
    	analogClock = new AnalogClock();
    
    	QDockWidget *clock_dock = new QDockWidget(tr("Clock"), this);
    	clock_dock->setWidget(analogClock);
    
    	clock_dock->setAllowedAreas(Qt::LeftDockWidgetArea);
    	addDockWidget(Qt::LeftDockWidgetArea, clock_dock);
    
    	////////
    	/// Tabify those docks! (at last...)
    	////////////////////////////
    
    	// Right widget area
    	tabifyDockWidget(info_dock, personal_dock);
    	tabifyDockWidget(personal_dock, team_dock);
    
    	// Bottom widget area
    	tabifyDockWidget(clients_dock, fahlog_dock);
    	tabifyDockWidget(fahlog_dock, log_dock);
    
    	/////////
    	/// Create the "View" Menu
    	///////////////////////////
    
    	QMenu *logsMenu = new QMenu(tr("Logs"));
    	QMenu *statsMenu = new QMenu(tr("Stats"));
    	QMenu *widgetsMenu = new QMenu(tr("Widgets"));
    
    	logsMenu->addAction(log_dock->toggleViewAction());
    	logsMenu->addAction(fahlog_dock->toggleViewAction());
    
    	statsMenu->addAction(personal_dock->toggleViewAction());
    	statsMenu->addAction(team_dock->toggleViewAction());
    
    	widgetsMenu->addAction(clock_dock->toggleViewAction());
    
    	menuView->addMenu(logsMenu);
    	menuView->addMenu(statsMenu);
    	menuView->addMenu(widgetsMenu);
    	menuView->addSeparator();
    	menuView->addAction(clients_dock->toggleViewAction());
    	menuView->addAction(info_dock->toggleViewAction());
    	
    	/////////
    	/// Create the Toggle-View Toolbar
    	///////////////////////////
    	
    	toolbarLogs->addAction(clients_dock->toggleViewAction());
    	toolbarLogs->addSeparator();
    	toolbarLogs->addAction(log_dock->toggleViewAction());
    	toolbarLogs->addAction(fahlog_dock->toggleViewAction());
    	toolbarLogs->addSeparator();
    	toolbarLogs->addAction(info_dock->toggleViewAction());
    	toolbarLogs->addAction(personal_dock->toggleViewAction());
    	toolbarLogs->addAction(team_dock->toggleViewAction());
    	show();
    
}

void mainWindow::show_aboutDialog()
{
    	aboutDialog about_dlg;
	about_dlg.exec();
}

void mainWindow::show_preferences()
{
    	preferences *prefs = new preferences(reloadTime);
	prefs->exec();
	reloadTime = prefs->reloadTime;
	Reloader->stop();
	Reloader->start(reloadTime*60000);
	
	if (!prefs->animatorCheckbox->isChecked())
	{
		Monitor->progressBar->setVisible(false);
		Monitor->stopAnimation();
	}
	else if (prefs->animatorCheckbox->isChecked())
	{
		Monitor->progressBar->setVisible(true);
		Monitor->startAnimation();	
	}
	log->mainLogger->append("-- Loading preferences... [OK]");
	
}

bool mainWindow::verifiedDir(QString dir)
{
	if (dir=="") return false;
	else
	{
		QFile file(dir+FAH_QUEUE);	
		if (file.exists()) return true;
		else
		{
			WARN(FW_NAME, "This not a valid Folding@Home directory!");
			return false;
		}
	}
}

void mainWindow::addClient()
{
	bool ok;
	QString dir;
		do
		{
    		dir = QFileDialog::getExistingDirectory(this, 
    							tr("Select the folder in which the client is located"),
                                                 	"/home",
                                                 	QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        } while ((!verifiedDir(dir))&&(dir!=""));
       
    	if (dir=="") return;

    	QString id = QInputDialog::getText(this, 
    					   tr("Select a symbolic name for this client"),
                                       		dir+"                              ",
                                       		QLineEdit::Normal,
                                       		QDir::home().dirName(), &ok);
                                          
    	clients->add(id, dir);
    	actionRemoveClient->setEnabled(true);
    	actionStart->setEnabled(true);
    	actionStop->setEnabled(true);
    	actionPersonalStats->setEnabled(true);
    	actionTeamStats->setEnabled(true);
    	actionMoleculeViewer->setEnabled(true);
    	actionSaveConfig->setEnabled(true);
    	actionPreferences->setEnabled(true);
		log->mainLogger->append("------ added Client ( ID: "+id+"  Path: "+dir+" )");

}

void mainWindow::removeClient()
{
	int index = clients->table->currentRow();
	if (index==-1)
	{
		WARN(FW_NAME, "You didn't select any client, to perform this action!\n\n"
					"Please go first to the 'Clients' window and select one by clicking on it.");
		return; 
	}
	
	if (ASK("Are you sure you want to delete this client?\n\n"
			"ID: "+clients->Client[index]->ID+"\n"
			"Path: "+clients->Client[index]->Path)) 
			{
				log->mainLogger->append("------ removed Client ( ID: "+clients->Client[index]->ID+"  Path: "+clients->Client[index]->Path+" )");
				clients->remove(index);
				
			}
}


void mainWindow::stopFolding()
{
	QProcess *proc = new QProcess(this);
	log->mainLogger->append("-- Stoping all Folding@Home clients...");
	proc->start("/etc/init.d/folding stop");
	
	proc->waitForFinished();
	
	MSG(tr("Folding@Home / Program / Stop"),
    	tr("All clients have been successfully stopped!"));
    log->mainLogger->append("-- Showing output from : '/etc/init.d/folding stop'");	
    	QByteArray qba = proc->readAll();
    	QTextCodec *codec = QTextCodec::codecForLocale();
    	QString result = codec->toUnicode(qba);
    	log->mainLogger->append(result);	
    log->mainLogger->append("-- All clients have been successfully stopped!");
    	actionStart->setEnabled(true);
	actionStop->setEnabled(false);             
}

void mainWindow::startFolding()
{
	QProcess *proc = new QProcess(this);
    log->mainLogger->append("-- Starting all Folding@Home clients...");
    	proc->start("/etc/init.d/folding start");
    
    	proc->waitForFinished();
    	
	MSG(tr("Folding@Home / Program / Start"),
    	tr("All clients have been successfully started!"));
    log->mainLogger->append("-- Showing output from : '/etc/init.d/folding start'");
    	QByteArray qba = proc->readAll();
    	QTextCodec *codec = QTextCodec::codecForLocale();
    	QString result = codec->toUnicode(qba);
    	log->mainLogger->append(result);
    log->mainLogger->append("-- All clients have been successfully started!");
	actionStart->setEnabled(false);
	actionStop->setEnabled(true);

	/*
    for (int l = 0; l < queue_dat->output.size(); ++l)
          info->mainLogger->append(queue_dat->output.at(l).toLocal8Bit().constData());
    
    fahWuinfo *wuinfo_dat = new fahWuinfo("/home/drkameleon/foldingathome/CPU1/work/wuinfo_05.dat");
    */
	
}

void mainWindow::contactAuthor()
{
	QProcess *proc = new QProcess(this);
	QString mail = "mailto:";
	mail.append(FW_AUTHOR_MAIL);
    	proc->start("firefox", QStringList() << mail);
}

void mainWindow::loadHomepage()
{
    	QProcess *proc = new QProcess(this);
		log->mainLogger->append("-- Loading website : "+QString(FW_HOMEPAGE)+" [OK]");
    	proc->start("firefox", QStringList() << FW_HOMEPAGE);
}

void mainWindow::loadSourceForge()
{
    	QProcess *proc = new QProcess(this);
		log->mainLogger->append("-- Loading website : "+QString(FW_SOURCEFORGE)+" [OK]");
    	proc->start("firefox", QStringList() << FW_SOURCEFORGE);
}

void mainWindow::loadFoldingWebsite()
{
    	QProcess *proc = new QProcess(this);
		log->mainLogger->append("-- Loading website : "+QString(FAH_WEBSITE)+" [OK]");
    	proc->start("firefox", QStringList() << FAH_WEBSITE);
}

void mainWindow::loadFoldingForum()
{
    	QProcess *proc = new QProcess(this);
		log->mainLogger->append("-- Loading website : "+QString(FAH_FORUM)+" [OK]");
    	proc->start("firefox", QStringList() << FAH_FORUM);
}


