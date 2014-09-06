// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : preferences.h
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

#ifndef __PREFERENCES_H__
#define __PREFERENCES_H__

#include <QDialog>
#include "ui_preferences.h"

class preferences : public QDialog, public Ui::preferencesDialog
{
	Q_OBJECT
	public:
		preferences(int rel, QWidget * parent = 0, Qt::WFlags f = 0);
		int reloadTime;
	private slots:
		void checkValue();
		void harmonizeValues();
	
};

#endif // __PREFERENCES_H__

