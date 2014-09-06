// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahUnitinfo.cpp
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

#include <QFile>
#include <QString>

#include "fahUnitinfo.h"
#include "foldwatcher_consts.h"
#include "Messages.h"

fahUnitinfo::fahUnitinfo(QString location) 
{
	QString line;
 	QString theLine;
 	
 	QFile file(location);
 	
 	if (!file.exists())
 	{
 		ERRORX(0, FW_NAME, "unitinfo.txt was not found!\n\n"
    		"This means that some information on the WU is unavailable.");
    	return;
	}
    
    	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    	{
    		ERRORX(0, FW_NAME, "unitinfo.txt could not be loaded!\n\n"
    		"This means that some information on the WU is unavailable.");
    		return;	
		}
    
    	while (!file.atEnd()) 
	{
        	QString line = file.readLine();
        	
		if (line.startsWith("Download time: "))
	        	DownloadTime = line.remove(0, 15);
		
		if (line.startsWith("Due time: "))
			DueTime = line.remove(0, 10);
	}
	
	file.close();
}

