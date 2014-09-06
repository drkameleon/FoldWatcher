// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : Messages.h
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

#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <QMessageBox>
#include <QString>

#define MSG(x, y) QMessageBox::information(this, x, y)
#define WARN(x, y) QMessageBox::warning(this, x, y)
#define ERROR(x, y) QMessageBox::critical(this, x, y)

#define MSGX(x, y, z) QMessageBox::information(x, y, z)
#define WARNX(x, y, z) QMessageBox::warning(x, y, z)
#define ERRORX(x, y, z) QMessageBox::critical(x, y, z)

bool ASK(QString question);

#endif // __MESSAGES_H__

