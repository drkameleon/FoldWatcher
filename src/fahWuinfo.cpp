// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahWuinfo.cpp
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

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QtGui>
#include <QProcess>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QProgressDialog>
#include <QTimer>
#include <QTextBrowser>
#include <QDockWidget>
#include <QByteArray>
#include <QTextCodec>
#include <QFile>
#include <QDataStream>

#include "fahQueue.h"
#include "fahWuinfo.h"
#include "logWindow.h"
#include "mainWindow.h"


fahWuinfo::fahWuinfo(QString location) 
{
	path = location;
}

void fahWuinfo::reload()
{
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	file.read((char *)&wuinfo, sizeof(wuformat));

	Completed = QString::number(wuinfo.csteps); nCompleted = wuinfo.csteps;
	Total = QString::number(wuinfo.tsteps); nTotal = wuinfo.tsteps;
	
	nPercent = (nCompleted * 100) / nTotal;
	
	Percent = QString::number(nPercent);
	
	file.close();
}

