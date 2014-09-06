// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahClient.h
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

#ifndef __FAHCLIENT_H__
#define __FAHCLIENT_H__

#include <QIcon>
#include <QString>
#include <QStringList>
#include <QTimer>

#include "fahQueue.h"
#include "fahUnitinfo.h"
#include "fahWuinfo.h"
#include "fahWulist.h"

class fahClient
{
	public:
		fahClient(QString id, QString location);
		fahQueue  		*q;
		fahWuinfo 		*w;
		fahWulist 		*wl;
		fahUnitinfo		*ui;
		void reload();
		void getInfo();
		
		QTimer *Manager;
		
		//-----------------------------------|
		//	 			     | 
		// RUNNING CLIENT/INDEX PROPERTIES   |//
		//				     |//
		//===================================|//
		    ////////////////////////////////////
			
		// Main
		/////////
		
		QString ID;
		QString Path;
		
		// From queue.dat
		///////////////////
		
		QString Version;
		QString Current; int nCurrent;
	 	QString Status; int nStatus;
		QString CoreURL;
		QString CoreNo;
		QString WuinfoSize;
	
		QString ProjectNo;
		QString Run;
 		QString Clone;
 		QString Generation;
 	
 		QString IssueTime;
 		QString MachineID;
 		 	
 		QString ServerIP;
 		QString ServerPort;
		QString WUType;
		QString Username;
		QString TeamNo;
 	
		QString StoredID;
	
 		QString CPU; 
 		QString OS;
	
 		QString Expiry;
 		QString Performance;
		
		// From work/wuinfo_0X.dat
		////////////////////////////
	
		QString Completed; 
		int nCompleted;
		
		QString Completed_old;
		int nCompleted_old;
		
		QString Difference;
		int nDifference;
		
		QString Total; 
		int nTotal;
		
		QString Percent;
		float nPercent;
		
		// From wus_list.dat
		//////////////////////
		
		QString Name;
		QString Atoms;
		QString Preferred;
		QString Deadline;
		QString Points;
		int nPoints;
		QString Code;
		QString Description;
		
		// From unitinfo.txt
		//////////////////////
		
		QString DownloadTime;
		QString DueTime;
		
		// Derived from above
		//////////////////////
		QIcon	Icon;
		
		// Performance indicators
		////////////////////////////
		QString SecsPerFrame;
		float nSecsPerFrame;
		
		QString FramesPerHour;
		float nFramesPerHour;
		
		QString FramesPerDay;
		float nFramesPerDay;
		
		QString PointsPerHour;
		float nPointsPerHour;
		
		QString PointsPerDay;
		float nPointsPerDay;
		
		////////////////////
		///////////////////
		///////////////////
		void setTPC(int val);
		int getTPC();
		
private:
		int TimePerCent ;
		

	
};	
	
#endif // __FAHCLIENT_H__	

