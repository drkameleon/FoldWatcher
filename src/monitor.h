// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : monitor.h
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

#ifndef __MONITOR_H__
#define __MONITOR_H__

#include <QWidget>
#include <QTimer>

#include "fahClient.h"
#include "ui_monitor.h"

class monitor : public QWidget, public Ui::monitor
{
	Q_OBJECT
	public:
		monitor(QWidget * parent = 0, Qt::WFlags f = 0);
		void print(fahClient *cl, int noc);
		void startAnimation();
		void stopAnimation();
		QTimer *progressor;
	private slots:
		void animateProgress();
	
	
};


#endif // __MONITOR_H__

