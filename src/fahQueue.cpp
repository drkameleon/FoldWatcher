// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahQueue.cpp
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

#include "fah_consts.h"
#include "fahQueue.h"
#include "foldwatcher_consts.h"
#include "logWindow.h"
#include "mainWindow.h"
#include "Messages.h"


fahQueue::fahQueue(QString location) 
{
	path = location;

}

void fahQueue::reload()
{
	
	QString STATUS_type [5] = {FAH_EMPTY_STR, FAH_FOLDING_STR, FAH_FINISHED_STR, "", FAH_FETCHING_STR};
	QString CPU_type [17] = {
							FAH_CPU_UNKNOWN, FAH_CPU_X86, FAH_CPU_PPC, FAH_CPU_MIPS,
							FAH_CPU_MIPS64, FAH_CPU_ALPHA, FAH_CPU_RISC, FAH_CPU_68K,
							FAH_CPU_SPARC, FAH_CPU_SPARC64, FAH_CPU_POWER, FAH_CPU_IA64,
							FAH_CPU_ARM, FAH_CPU_CELL, FAH_CPU_S390, FAH_CPU_SH4, FAH_CPU_AMD64
							};
	QString OS_type [35] =  {
							FAH_OS_UNKNOWN, FAH_OS_WIN32, FAH_OS_MACOS, FAH_OS_MACOSX,
							FAH_OS_LINUX, FAH_OS_BSDI, FAH_OS_NETBSD, FAH_OS_FREEBSD,
							FAH_OS_OPENBSD, FAH_OS_NEXTSTEP, FAH_OS_BEOS, FAH_OS_IRIX,
							FAH_OS_IRIX64, FAH_OS_SUNOS, FAH_OS_SOLARIS, FAH_OS_PS3,
							FAH_OS_QNX, FAH_OS_TRU64, FAH_OS_WIN64, FAH_OS_OS2, 
							FAH_OS_UNIXWARE, FAH_OS_HPUX, FAH_OS_MACH, FAH_OS_AIX,
							FAH_OS_AUX, FAH_OS_AMIGAOS, FAH_OS_NETWARE, FAH_OS_MVS,
							FAH_OS_ULTRIX, FAH_OS_DGUX, FAH_OS_SINIX, FAH_OS_DYNIX,
							FAH_OS_OS390, FAH_OS_RISCOS, FAH_OS_OS9
							};	

	QFile file(path);
	if (!file.exists()) 
	{
		ERRORX(0, FW_NAME, "queue.dat was not found!\n\n"
    		"This means that no further information on the WU is available.");
    	return;
   	}
   	
	if (!file.open(QIODevice::ReadOnly))
	{
		ERRORX(0, FW_NAME, "queue.dat could not be loaded!\n\n"
    		"This means that no further information on the WU is available.");
    	return;
	}
	file.read((char *)&queue, sizeof(queueformat));

	Version  = QString::number(queue.version);
	
	nCurrent = queue.current;
	Current  = QString::number(queue.current);
	
	nStatus = queue.entry[queue.current].stat; 
 	Status = STATUS_type[queue.entry[queue.current].stat];
 	
 	int CUR = queue.current;
 	int cnt;

 	for (cnt=0; cnt<128; cnt++)
		CoreURL.append(queue.entry[CUR].url[cnt]);
	
	CoreNo.setNum(queue.entry[CUR].core,16);
	WuinfoSize = QString::number(queue.entry[CUR].dsiz);
	
	ProjectNo = QString::number(le2(queue.entry[CUR].wuid.f.proj)); 
	Run = QString::number(le2(queue.entry[CUR].wuid.f.run));  	
 	Clone = QString::number(le2(queue.entry[CUR].wuid.f.clone)); 
 	Generation = QString::number(le2(queue.entry[CUR].wuid.f.gen));
 	
 	IssueTime = QString::number(le4(queue.entry[CUR].wuid.f.issue[0]));
 	MachineID = QString::number(le4(queue.entry[CUR].mid));
 	ServerIP = QString::number(queue.entry[CUR].svr2[3]) + "."
 			 + QString::number(queue.entry[CUR].svr2[2]) + "."
 			 + QString::number(queue.entry[CUR].svr2[1]) + "."
 			 + QString::number(queue.entry[CUR].svr2[0]);
 	ServerPort = QString::number(queue.entry[CUR].port);

 	for (cnt=0; cnt<64; cnt++)
		WUType.append(queue.entry[CUR].type[cnt]);
	
	for (cnt=0; cnt<64; cnt++)
		Username.append(queue.entry[CUR].uname[cnt]);

 	for (cnt=0; cnt<64; cnt++)
		TeamNo.append(queue.entry[CUR].teamn[cnt]);
	
	QString us [8];
	QString usk="";
	for (cnt = 0; cnt<8; cnt++)
	{
		us[cnt].setNum(queue.entry[CUR].uid[cnt],16);
		usk.append(us[cnt]);
	}
	usk.toUpper();
	StoredID = usk;
	
 	CPU = CPU_type[queue.entry[CUR].cpu_type];
 	OS = OS_type[queue.entry[CUR].os_type];
 	
 	quint32 secs, mins, hours, days;
 	secs = queue.entry[CUR].expire;
 	mins = secs/60; hours = mins/60; days = hours/24;
 	Expiry = QString::number(days) + " days";
 	
 	Performance = QString::number(queue.pfract);
	
	file.close();	
}

