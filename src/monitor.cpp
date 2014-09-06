// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : monitor.cpp
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

#include <QDateTime>
#include <QListWidgetItem>
#include <QTimer>

#include "fahClient.h"
#include "Messages.h"
#include "monitor.h"

monitor::monitor( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);
	
	progressor = new QTimer(this);
	connect(progressor, SIGNAL(timeout()), this, SLOT(animateProgress()));

}

void monitor::startAnimation()
{
	progressor->start(100);
}

void monitor::stopAnimation()
{
	progressor->stop();
}

void monitor::animateProgress()
{
	if (progressBar->value()<100) 
		progressBar->setValue(progressBar->value()+1);
	else 
		progressBar->setValue(0);
}

void monitor::print(fahClient *cl, int noc)
{
	//
	// Construct the "Dates and Deadlines" table...
	///////////////////////////////////////////////////////
	
	dates->clear();
	new QListWidgetItem(tr("Download Time : ")+cl->DownloadTime+"\n", dates);
	QDateTime dt = QDateTime::fromString(cl->DownloadTime, "MMMM dd hh:mm:ss");
	QDateTime pref_dt = dt.addDays(cl->Preferred.toInt());
	QString pref_str;
	
	if (dt!=pref_dt) 
		pref_str = pref_dt.toString("MMMM dd hh:mm:ss")+"\n";
	else 
		pref_str = "------\n";
		
	new QListWidgetItem(tr("Preferred Time : ")+pref_str,dates);
	new QListWidgetItem(tr("Due Time : ")+cl->DueTime, dates);
	
	//
	// Calculate performance
	//////////////////////////////////////
	int secs_passed = cl->getTPC()/noc;
	int frames_diff = cl->nDifference;
	
	if (frames_diff!=0)
	{
		
		cl->nSecsPerFrame = (float) secs_passed / frames_diff;   		// X secs for 1 frame
		cl->SecsPerFrame.setNum(cl->nSecsPerFrame, 'f', 2);				//
	
		cl->nFramesPerHour = (float) 3600 / cl->nSecsPerFrame;			// X frames for 1 hour
		cl->FramesPerHour.setNum(cl->nFramesPerHour, 'f', 2);	//
	
		cl->nFramesPerDay = (float) 24 * cl->nFramesPerHour;			// X frames for 1 day
		cl->FramesPerDay.setNum(cl->nFramesPerDay, 'f', 2);		//
		
		float points_per_frame = (float) cl->nPoints / cl->nTotal;				// X points for 1 hour
		cl->nPointsPerHour = (float) (3600*points_per_frame)/cl->nSecsPerFrame;	//
		cl->PointsPerHour.setNum(cl->nPointsPerHour, 'f', 2);			//
		
		cl->nPointsPerDay = (float) 24*cl->nPointsPerHour;				// X points for 1 day
		cl->PointsPerDay.setNum(cl->nPointsPerDay, 'f', 2);		//
	
	}
	/*QString ss;
	float ppf = (float) cl->nPoints/cl->nTotal;
	ss.setNum(ppf, 'f', 3);
	MSG("",QString::number(cl->nPoints)+"/"+ss);*/
	//
	// Construct the "Estimations" table...
	///////////////////////////////////////////////////////
	
	performance->clear();
		
	new QListWidgetItem(tr("secs/frame : ")+cl->SecsPerFrame, performance);
	new QListWidgetItem(tr("frames/h : ")+cl->FramesPerHour , performance);
	new QListWidgetItem(tr("frames/d : ")+cl->FramesPerDay, performance);
	new QListWidgetItem(tr("pts/h : ")+cl->PointsPerHour, performance);
	new QListWidgetItem(tr("pts/d : ")+cl->PointsPerDay, performance);
}


