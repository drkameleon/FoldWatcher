// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahWulist.h
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

#ifndef __FAHWULIST_H__
#define __FAHWULIST_H__

#include <QString>

class fahWulist
{
	public:
		fahWulist(QString location, QString projectNo);
		
		//////////
		// RUNNING CLIENT/INDEX PROPERTIES
		/////////////////////////////
		QString Name;
		QString Atoms;
		QString Preferred;
		QString Deadline;
		QString Points;
		int nPoints;
		QString Code;
		QString Description;
	
};

#endif // __FAHWULIST_H__

