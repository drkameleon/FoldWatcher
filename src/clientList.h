// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : clientList.h
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

#ifndef __CLIENTLIST_H__
#define __CLIENTLIST_H__

#include <QWidget>

#include "fahClient.h"
#include "ui_clientlist.h"

struct userformat
{
	QString name;
	int index;
	QTableWidgetItem *uItem;
};

class clientList : public QWidget, public Ui::clientList
{
	Q_OBJECT
	public:
		clientList(QWidget * parent = 0, Qt::WFlags f = 0);
		void reload();
		void add(QString id, QString location);
		void remove(int clno);
		int newUser(QString nm);
		void refreshClient(int cl);
		void resetHeaders();
	
		int NOC;			// Number Of Clients
		int NOU;			// Number of different Users/Contributors
		int nu;				// NOU "mirror"
		int NOW;			// Number of different Work Units
	
		userformat User[10];
		QTableWidgetItem *WU[30];
		fahClient *Client[20];
		QStringList output;
	
	private slots:
		void updateTPC();
		
};
#endif // __CLIENTLIST_H__

