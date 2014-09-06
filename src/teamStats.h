// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : teamStats.h
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

#ifndef __TEAMSTATS_H__
#define __TEAMSTATS_H__

#include <QWidget>

#include "ui_teamstats.h"

struct statsformat
{
	QString URank;
 	QString UName;
 	QString UScore;
 	QString UWU;
	
};

class teamStats : public QWidget, public Ui::teamStats
{
	Q_OBJECT
	public:
		teamStats(QWidget * parent = 0, Qt::WFlags f = 0);
		void parse(QString tn);
		void reload(QString tn);
		bool fetch(QString tn);
		void print();
		void formatPrintPage();
		
		bool UpdateInProgress();
		bool brokenConnection();
			
		QString TeamName;
		QString TeamID;
		QString DateLastWU;
 		QString ActiveCPU50;
 		QString TotalScore;
 		QString TotalWUs;
 		QString OverallRank;
 		
 		QTextBrowser *printPage;
 		
 		statsformat UserStats[1001];
		int NOM;				// Number Of team Members
	private slots:
		void printStats();
		void exportPDF();
	
};

#endif // __TEAMSTATS_H__

