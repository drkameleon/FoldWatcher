// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : main.cpp
// Last Update : 17/05/2008
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

#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include "mainWindow.h"


int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	mainWindow win;
	
	if (!QSystemTrayIcon::isSystemTrayAvailable())
	{
        	QMessageBox::critical(0, 
					QObject::tr("Systray"),
                               		QObject::tr("I couldn't detect any system tray "
                                           "on this system."));
	        return 1;
     	}
	
	win.showMaximized(); 
	
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

