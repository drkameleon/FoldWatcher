// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : AnalogClock.cpp
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

#include "AnalogClock.h"

AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent)
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     	timer->start(1000);

     	setWindowTitle(tr("Analog Clock"));
     	resize(200, 200);
     	setMinimumSize(250,0);
}

void AnalogClock::paintEvent(QPaintEvent *)
{
	static const QPoint hourHand[3] = {
        	QPoint(7, 8),
        	QPoint(-7, 8),
        	QPoint(0, -40)
		};
     	static const QPoint minuteHand[3] = {
         	QPoint(7, 8),
         	QPoint(-7, 8),
	        QPoint(0, -70)
     		};
     
	QColor hourColor(160, 14, 14);
     	QColor minuteColor(70, 45, 255, 191);
     	QColor secondColor(0, 0, 0);

	int side = qMin(width(), height());
     	QTime time = QTime::currentTime();

     	QPainter painter(this);
     	painter.setRenderHint(QPainter::Antialiasing);
     	painter.translate(width() / 2, height() / 2);
     	painter.scale(side / 200.0, side / 200.0);

     	painter.setPen(Qt::NoPen);
     	painter.setBrush(hourColor);

     	painter.save();
     	painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
     	painter.drawConvexPolygon(hourHand, 3);
     	painter.restore();

     	painter.setPen(hourColor);

     	for (int i = 0; i < 12; ++i) 
	{
        	painter.drawLine(88, 0, 96, 0);
         	painter.rotate(30.0);
	}
     
     	painter.setPen(Qt::NoPen);
     	painter.setBrush(minuteColor);

     	painter.save();
     	painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
     	painter.drawConvexPolygon(minuteHand, 3);
     	painter.restore();

     	painter.setPen(minuteColor);

     	for (int j = 0; j < 60; ++j) 
	{
        	if ((j % 5) != 0)
			painter.drawLine(92, 0, 96, 0);

        	painter.rotate(6.0);
     	}
}

