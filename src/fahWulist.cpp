// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahWulist.cpp
// Last Update : 18/05/2008
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
#include <QStringList>
#include <QProgressDialog>
#include <QTimer>
#include <QFile>
#include <QTextBrowser>
#include <QDockWidget>
#include <QByteArray>
#include <QTextCodec>
#include <QString>

#include "fahWulist.h"
#include "foldwatcher_consts.h"
#include "Messages.h"


fahWulist::fahWulist(QString location, QString projectNo) 
{
	QString line;
 	QString theLine;
 	bool projectFound = false;
 	
 	Name = FW_NULL;
	Atoms = FW_NULL;
	Preferred = QString(FW_NULL) + " days";
	Deadline = QString(FW_NULL) + " days";
	Points = FW_NULL;
	Code = FW_NULL;
	Description = FW_NULL;
 	
 	QFile file(location);
    if (!file.exists()) ERRORX(0, FW_NAME, "wus_list.dat was not found!\n\n"
    		"This means that some information on the WU is unavailable.");
    	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    	{
    		ERRORX(0, FW_NAME, "wus_list.dat could not be loaded!\n\n"
    		"This means that some information on the WU is unavailable.");
    		return;
   		}
   
    	while (!file.atEnd()) 
	{
        	QString line = file.readLine();
        	if (line.startsWith(projectNo))
        	{
        		theLine = line;
        		projectFound = true;
        		break;	
		}
	}
	
	if (!projectFound) 
	{
		WARNX(0, FW_NAME, "Project No "+ projectNo + " was not found in the Database!\n\n"
						"This means that some information on the WU is unavailable.\n"
									"Please inform the author about the missing WU, reporting this Project Number.");
		
		
		return;
		
	}
								
	QStringList lista = theLine.split("|");
	Name = lista.at(2);
	Atoms = lista.at(3);
	Preferred = lista.at(4);
	Deadline = lista.at(5);
	Points = lista.at(6); 
	Points.replace(".00","");
	nPoints = Points.toInt();
	Code = lista.at(8);
	Description = lista.at(9);
	file.close();
	
}

