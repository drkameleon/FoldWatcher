// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahClient.cpp
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

#include <QMessageBox>
#include <QObject>

#include "fah_consts.h"
#include "fahClient.h"
#include "fahQueue.h"
#include "foldwatcher_consts.h"
#include "Messages.h"

fahClient::fahClient(QString id, QString location) 
{
	
	Path = location;
	ID = id;
	
	q = new fahQueue(location+FAH_QUEUE);
	q->reload();
	
	w = new fahWuinfo(location+FAH_WUINFO1+q->Current+FAH_WUINFO2);
	w->reload();
	
	wl = new fahWulist(FW_WUSLIST, q->ProjectNo);
	
	ui = new fahUnitinfo(location+FAH_UNITINFO);
		
	getInfo();
	
	TimePerCent = 0;

	Manager = new QTimer();
    
}

void fahClient::setTPC(int val)
{
	TimePerCent = val;
}

int fahClient::getTPC()
{
	return TimePerCent;
}


void fahClient::reload ()
{
	q->reload();
	if (q->nStatus==FAH_FOLDING)
	{
		if (q->Current!=Current)			// Tries to capture WU change - thus queue.dat current index's change
		{
			w = new fahWuinfo(Path+FAH_WUINFO1+q->Current+FAH_WUINFO2);
			wl = new fahWulist(FW_WUSLIST, q->ProjectNo);
			ui = new fahUnitinfo(Path+FAH_UNITINFO);
			TimePerCent = 0;
	
			Manager = new QTimer();
			
		}
		w->reload();
		getInfo();
	} else Icon = QIcon(QString::fromUtf8(FW_EMPTY_ICON));  
}

void fahClient::getInfo()
{
	// From queue.dat
	///////////////////	
	
	 Version		= q->Version;
	 Current 		= q->Current;
	 nCurrent 		= q->nCurrent;
 	 Status			= q->Status;
 	 nStatus		= q->nStatus;
	 CoreURL		= q->CoreURL.toAscii();
	 CoreNo			= q->CoreNo;
	 WuinfoSize		= q->WuinfoSize;
	
	 ProjectNo		= q->ProjectNo;
	 Run            	= q->Run;
	 Clone			= q->Clone;
 	 Generation		= q->Generation;
 	
 	 IssueTime		= q->IssueTime;
 	 MachineID		= q->MachineID;
 	 	
 	 ServerIP		= q->ServerIP;
 	 ServerPort		= q->ServerPort;
 	 
	 WUType			= q->WUType;
	 Username		= q->Username.toAscii();
	 TeamNo			= q->TeamNo.toAscii();
 
	 StoredID		= q->StoredID.replace("ff","");

 	 CPU			= q->CPU; 
 	 OS				= q->OS;

 	 Expiry			= q->Expiry;
 	 Performance		= q->Performance;
	
	// From work/wuinfo_0X.dat
	////////////////////////////
	
	// WU's progress
	 Completed_old  	= Completed;
	 nCompleted_old 	= nCompleted;
	 Completed		= w->Completed; 
	 nCompleted		= w->nCompleted;
	 
	 nDifference    	= nCompleted-nCompleted_old;
	 Difference     	= QString::number(nDifference);
	 
	 Total			= w->Total; 
	 nTotal			= w->nTotal;
	
	 Percent		= w->Percent;
	 nPercent		= w->nPercent;
	
	// From wus_list.dat
	//////////////////////
	
	 Name			= wl->Name;
	 Atoms			= wl->Atoms;
	 Preferred		= wl->Preferred;
	 Preferred.replace(".00","");
	 Deadline		= wl->Deadline;
	 Points			= wl->Points;
	 Points.replace(".00","");
	 nPoints        = wl->nPoints;
	 Code			= wl->Code;
	 Description		= wl->Description;
	 
	// From unitinfo.txt
	//////////////////////
	
	DownloadTime		= ui->DownloadTime;
	DownloadTime = DownloadTime.simplified();
	DueTime			= ui->DueTime;
	
	// Derived from above
	//////////////////////
	
	switch(nStatus)
	{
    		case FAH_EMPTY: 
    	   		Icon = QIcon(QString::fromUtf8(FW_EMPTY_ICON));  
         		break;
        	case FAH_FOLDING: 
         		Icon = QIcon(QString::fromUtf8(FW_FOLDING_ICON)); 
         		break;
        	case FAH_FINISHED: 
        		Icon = QIcon(QString::fromUtf8(FW_FINISHED_ICON)); 
         		break;
        	case FAH_FETCHING:
        		Icon = QIcon(QString::fromUtf8(FW_FETCHING_ICON)); 
        		break;
        	default:      
        		break;          
    	}

	
}

