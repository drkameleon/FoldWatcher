// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : preferences.cpp
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

#include "Messages.h"
#include "preferences.h"


preferences::preferences(int rel, QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	setupUi(this);
	reloadTime = rel;
	reloadSlider->setValue(rel);
	label->setText(QString::number(rel)+" mins");
	connect(okButton, SIGNAL(clicked()), this, SLOT(checkValue()));
    	connect(cancelButton, SIGNAL(clicked()), this, SLOT(hide()));
    	connect(reloadSlider, SIGNAL(valueChanged(int)), this, SLOT(harmonizeValues()));

}

void preferences::checkValue()
{
	reloadTime = reloadSlider->value();
	hide();

}

void preferences::harmonizeValues()
{
	label->setText(QString::number(reloadSlider->value())+" mins");

}

