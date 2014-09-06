// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : personalStats.h
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

#ifndef __PERSONALSTATS_H__
#define __PERSONALSTATS_H__

#include <QWidget>
#include "ui_personalstats.h"

class personalStats : public QWidget, public Ui::personalStats
{
	Q_OBJECT
	public:
		personalStats(QWidget * parent = 0, Qt::WFlags f = 0);
		void parse(QString tn, QString un);
		void reload(QString tn, QString un);
		bool fetch(QString tn, QString un);
		void print(QString tn, QString un);
		
		void formatPrintPage();
		
		bool UpdateInProgress();
		bool brokenConnection();
		
		QString DateLastUpdate;
 		QString DateLastWU;
 		
 		QString TotalScore;
 		QString OverallRank;
 		QString ActiveCPU50;
 		QString ActiveCPU7;
 		
 		QString TeamName;
 		QString TotalWUs;
		
		QTextBrowser *printPage;
		
	private slots:
		void printStats();
		void exportPDF();
};

#endif // __PERSONALSTATS_H__

