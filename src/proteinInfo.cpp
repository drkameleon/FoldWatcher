// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : proteinInfo.cpp
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

#include <QListWidgetItem>

#include "fahClient.h"
#include "proteinInfo.h"


proteinInfo::proteinInfo( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);
	QObject::connect(elementList, SIGNAL( currentRowChanged(int ) ), this, SLOT( harmonizeValues() ) );
	QObject::connect(valueList, SIGNAL( currentRowChanged(int ) ), this, SLOT( harmonizeElements() ) );
}

void proteinInfo::harmonizeValues()
{
	int rowTo = elementList->currentRow();
	valueList->setCurrentRow(rowTo);
	valueList->scrollToItem(valueList->item(rowTo),QAbstractItemView::PositionAtTop);
}

void proteinInfo::harmonizeElements()
{
	int rowTo = valueList->currentRow();
	elementList->setCurrentRow(rowTo);

}

void proteinInfo::insertSeparator()
{
	new QListWidgetItem(tr(""), elementList);
		new QListWidgetItem("", valueList);		
}

void proteinInfo::print (fahClient *Cl)
{
	elementList->clear();
	valueList->clear();
	
	new QListWidgetItem(tr("Username"), elementList);
		new QListWidgetItem(Cl->Username, valueList);
	new QListWidgetItem(tr("Team"), elementList);
		new QListWidgetItem(Cl->TeamNo, valueList);		
	insertSeparator();	
	new QListWidgetItem(tr("Machine ID"), elementList);
		new QListWidgetItem(Cl->MachineID, valueList);
	new QListWidgetItem(tr("CPU"), elementList);
		new QListWidgetItem(Cl->CPU, valueList);
	new QListWidgetItem(tr("OS"), elementList);
		new QListWidgetItem(Cl->OS, valueList);		
	insertSeparator();		
	new QListWidgetItem(tr("Server IP (port)"), elementList);
		new QListWidgetItem(Cl->ServerIP + " (" + Cl->ServerPort + ")", valueList);
	new QListWidgetItem(tr("Core URL"), elementList);
		new QListWidgetItem(Cl->CoreURL, valueList);
	new QListWidgetItem(tr("Core"), elementList);
		new QListWidgetItem("FahCore_"+Cl->CoreNo+".exe", valueList);		
	insertSeparator();		
	new QListWidgetItem(tr("Project"), elementList);
		new QListWidgetItem(Cl->ProjectNo, valueList);
	new QListWidgetItem(tr("Run"), elementList);
		new QListWidgetItem(Cl->Run, valueList);
	new QListWidgetItem(tr("Clone"), elementList);
		new QListWidgetItem(Cl->Clone, valueList);		
	new QListWidgetItem(tr("Generation"), elementList);
		new QListWidgetItem(Cl->Generation, valueList);		
	insertSeparator();
	new QListWidgetItem(tr("Name"), elementList);
		new QListWidgetItem(Cl->Name, valueList);
	new QListWidgetItem(tr("Atoms"), elementList);
		new QListWidgetItem(Cl->Atoms, valueList);
	new QListWidgetItem(tr("Frames"), elementList);
		new QListWidgetItem(Cl->Total, valueList);		
	new QListWidgetItem(tr("Stored ID"), elementList);
		new QListWidgetItem(Cl->StoredID, valueList);	
	
}

