// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : Messages.cpp
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

#include <QIcon>
#include <QMessageBox>

#include "foldwatcher_consts.h"
#include "Messages.h"

bool ASK(QString question)
{
	QMessageBox msgBox;
	
	msgBox.setWindowTitle(FW_NAME);
	msgBox.setText(question);
 	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
 	msgBox.setWindowIcon(QIcon(FW_LOGO));
 	msgBox.setIcon(QMessageBox::Question);
 	
 	switch (msgBox.exec()) 
 	{
 		case QMessageBox::Yes:
    		return true;
     		break;
 		case QMessageBox::No:
  			return false;
     		break;
 		default:
     		// should never be reached
     		break;
 	}
 	return true;
}

