// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : foldwatcher_consts.h
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

#ifndef __FOLDWATCHER_CONSTS_H__
#define __FOLDWATCHER_CONSTS_H__

#include <QDir>


#define FW_NAME 		"FoldWatcher"

#define FW_AUTHOR		"Dr.K@meleon"
#define FW_AUTHOR_MAIL		"drkameleon@hotmail.com"

#define FW_PLATFORM		"Linux"

#define FW_VERSION		"0"
#define FW_SUBVERSION		"1"
#define FW_REVISION		"0"

#define FW_RELEASE		FW_VERSION << "." << FW_SUBVERSION << "." << FW_REVISION

#define FW_HOMEPAGE		"http://kameleon-nest.blogspot.com"
#define FW_SOURCEFORGE		"http://sourceforge.net/projects/foldwatcher"

/////////////

#define FW_STARTUPMSG1	"<b>"<< FW_NAME << "</b> version " << FW_RELEASE << " for " << FW_PLATFORM 
#define FW_STARTUPMSG2  "Coded by <a href=""" << FW_AUTHOR_MAIL << """>" << FW_AUTHOR << "</a>"
#define FW_STARTUPMSG3  "Project Homepage : <a href=""" << FW_HOMEPAGE << """>" << FW_HOMEPAGE << "</a>"
#define FW_STARTUPMSG4  "Program has successfully started!"

//// Icons used to indicate a client's status
#define FW_EMPTY_ICON		":/icons/icons/webdev-cancel.png"
#define FW_FOLDING_ICON		":/icons/icons/webdev-config.png"
#define FW_FINISHED_ICON	":/icons/icons/webdev-ok.png"
#define FW_FETCHING_ICON	":/icons/icons/webdev-arrow-down.png"

//// Logo icons
#define FW_LOGO				":/logo/logo/greenCube.png"

//// Constants
#define FW_NEW_USER			10	//Indicates this one is a NEW user

//// If no information was found
#define FW_NULL				"------"

//// Files
#define FW_DIR				QDir::homePath() + "/.foldwatcher"

#define FW_CONFIG			QDir::homePath() + "/.foldwatcher/foldwatcher.cfg"
#define FW_WUSLIST			QDir::homePath() + "/.foldwatcher/wus_list.dat"
#define FW_TEAMSTATS		QDir::homePath() + "/.foldwatcher/teamStats.dat"
#define FW_PERSONALSTATS	QDir::homePath() + "/.foldwatcher/personalStats.dat"

#define FW_XYZ2PDB			QDir::homePath() + "/.foldwatcher/xyz2pdb"
#define FW_RASMOL			"rasmol"
							
#endif // __FOLDWATCHER_CONSTS_H__

