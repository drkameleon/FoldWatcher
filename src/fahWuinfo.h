// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahWuinfo.h
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

#ifndef __FAHWUINFO_H__
#define __FAHWUINFO_H__

struct wuformat
{       quint32     core;                   /* 000 Core number */
        char        pname[80];              /* 004 Project (protein) name */
        quint32     tsteps;                 /* 084 Total steps */
        quint32     csteps;                 /* 088 Completed steps */
        char        z092[420];              /* 092 */
};


class fahWuinfo
{
	public:
		fahWuinfo(QString location);
		void reload();
		QStringList output;
		wuformat wuinfo;
		
		//////////
		// RUNNING CLIENT/INDEX PROPERTIES
		/////////////////////////////
		QString Completed; 
		int nCompleted;
		
		QString Total; 
		int nTotal;
		
		QString Percent;
		float nPercent;
		
	private:	
		QString path;
		
};	
	
#endif // __FAHWUINFO_H__

