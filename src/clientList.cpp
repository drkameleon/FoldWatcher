// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : clientList.cpp
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

#include <QtGui>

#include "clientList.h"
#include "fah_consts.h"
#include "fahClient.h"
#include "fahWulist.h"
#include "foldwatcher_consts.h"
#include "mainWindow.h"
#include "Messages.h"

class ItemDelegate: public QItemDelegate
{
	public:
    		ItemDelegate(QObject* parent = 0): QItemDelegate(parent)
    		{
    		}
    
    	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    	{
        	QStyleOptionProgressBar opt;
	        QRect rct(option.rect.x(), option.rect.y()+10, option.rect.width(), option.rect.height()-20);
        	opt.rect = rct;
        
        	opt.minimum = 0;
        	opt.maximum = 100;
        	opt.progress = index.model()->data(index,Qt::DisplayRole).toInt();
        
        	if (opt.progress == -1) return;
        
       		opt.text = QString("%1%").arg(opt.progress);
        	opt.textVisible = true;
        	QApplication::style()->drawControl(QStyle::CE_ProgressBar, &opt, painter, 0);
    	}
};


clientList::clientList( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);

	NOC = 0;
	NOU = 0;
	NOW = 0;
}

int clientList::newUser(QString nm)
{
	if (NOU == 0) return FW_NEW_USER;
	
	for (int u = 0; u < NOU; u++)
		if (User[u].name == nm) return u;
		
	return FW_NEW_USER;
}

void clientList::resetHeaders()
{
	QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("clientList", "ID", 0, QApplication::UnicodeUTF8));
    table->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("clientList", "Name", 0, QApplication::UnicodeUTF8));
    table->setHorizontalHeaderItem(1, __colItem1);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("clientList", "Code", 0, QApplication::UnicodeUTF8));
    table->setHorizontalHeaderItem(2, __colItem2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("clientList", "Points", 0, QApplication::UnicodeUTF8));
    table->setHorizontalHeaderItem(3, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("clientList", "Progress", 0, QApplication::UnicodeUTF8));
    table->setHorizontalHeaderItem(4, __colItem4);
}

void clientList::reload()
{
	table->clear();
	int NOC_backup = NOC;

	
	if (NOC_backup>0)
		for (int noc = 0; noc<NOC_backup; noc++)
			refreshClient(noc);
	table->resizeColumnsToContents();
	int Sum = table->columnWidth(0)+
			  table->columnWidth(1)+
			  table->columnWidth(2)+
			  table->columnWidth(3);
		
	table->setColumnWidth(4,750-(Sum+20));
	resetHeaders();
	show();
}

void clientList::remove(int clno)
{
	table->clear();
	for (int i=clno; i<NOC-1; i++)
	{
		Client[i] = Client[i+1];
	}
	NOC-=1;
	if (NOC==0) 
	{
		table->clear();
		table->setRowCount(0);
	}
	else
		for (int i=0; i<NOC; i++)
			refreshClient(i);
			
	table->resizeColumnsToContents();
	int Sum = table->columnWidth(0)+
			  table->columnWidth(1)+
			  table->columnWidth(2)+
			  table->columnWidth(3);
		
	table->setColumnWidth(4,750-(Sum+20));
	resetHeaders();
}

void clientList::add(QString id, QString location)
{
	
	Client[NOC] = new fahClient(id, location);
		
	table->setRowCount(NOC+1);
	table->setItemDelegateForColumn(4, new ItemDelegate(table));
    
	table->setRowHeight(NOC, 64);
	
	QTableWidgetItem *qi = new QTableWidgetItem(id);
	qi->setIcon(Client[NOC]->Icon);
	table->setItem(NOC, 0, qi);
	
	qi = new QTableWidgetItem(Client[NOC]->Name);
	table->setItem(NOC, 1, qi);
	
	qi = new QTableWidgetItem(Client[NOC]->Code);
	table->setItem(NOC, 2, qi);
	
	qi = new QTableWidgetItem(Client[NOC]->Points);
	table->setItem(NOC, 3, qi);
	
	qi = new QTableWidgetItem(Client[NOC]->Percent);
	table->setItem(NOC, 4, qi);
	
	show();

    connect(Client[NOC]->Manager, SIGNAL(timeout()), this, SLOT(updateTPC()));
    
    Client[NOC]->Manager->start(1000);
    
    refreshClient(NOC);
    
	NOC += 1;
	NOW += 1;
	
	table->resizeColumnsToContents();
	int Sum = table->columnWidth(0)+
			  table->columnWidth(1)+
			  table->columnWidth(2)+
			  table->columnWidth(3);
		
	table->setColumnWidth(4,750-(Sum+20));
	resetHeaders();
}

void clientList::updateTPC()
{
	for (int j=0; j<NOC; j++)
	{
		int tpc = Client[j]->getTPC();
		Client[j]->setTPC(tpc+1) ;
	}
	
}

void clientList::refreshClient(int cl)
{
	Client[cl]->reload();
	
	table->setRowCount(cl+1);
	table->setItemDelegateForColumn(4, new ItemDelegate(table));
    
    	table->setRowHeight(cl, 64);
	
	QTableWidgetItem *qi = new QTableWidgetItem(Client[cl]->ID);
	qi->setIcon(Client[cl]->Icon);
	table->setItem(cl, 0, qi);
	
	qi = new QTableWidgetItem(Client[cl]->Name);
	table->setItem(cl, 1, qi);
	
	qi = new QTableWidgetItem(Client[cl]->Code);
	table->setItem(cl, 2, qi);
	
	qi = new QTableWidgetItem(Client[cl]->Points);
	table->setItem(cl, 3, qi);
	
	qi = new QTableWidgetItem(Client[cl]->Percent);
	table->setItem(cl, 4, qi);
	
	table->resizeColumnsToContents();
	int Sum = table->columnWidth(0)+
			  table->columnWidth(1)+
			  table->columnWidth(2)+
			  table->columnWidth(3);
		
	table->setColumnWidth(4,750-(Sum+20));
	resetHeaders();
	show();
	

}

