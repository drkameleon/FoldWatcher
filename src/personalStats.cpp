// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : personalStats.cpp
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

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QtGui>
#include <QProcess>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QProgressDialog>
#include <QTimer>
#include <QFile>
#include <QTextBrowser>
#include <QDockWidget>
#include <QByteArray>
#include <QTextCodec>

#include "aboutDialog.h"
#include "AnalogClock.h"
#include "clientList.h"
#include "mainWindow.h"
#include "fah_consts.h"
#include "fahClient.h"
#include "fahQueue.h"
#include "fahWuinfo.h"
#include "foldwatcher_consts.h"
#include "logWindow.h"
#include "Messages.h"
#include "personalStats.h"
#include "teamStats.h"
#include "ui_mainwindow.h"

personalStats::personalStats( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);
	
	printPage = new QTextBrowser();
	printButton->setEnabled(false);
	pdfButton->setEnabled(false);
	
	QObject::connect(printButton, SIGNAL( clicked() ), this, SLOT( printStats() ) );
	QObject::connect(pdfButton, SIGNAL( clicked() ), this, SLOT( exportPDF() ) );
	
}

void personalStats::formatPrintPage()
{
	printPage->clear();
	printPage->append("<b><u>PERSONAL STATS</b></u>");
	printPage->append("powered by FoldWatcher");
	printPage->append("");
	printPage->append("");
	printPage->append("<b>Name.......................: </b>" + TeamName);
	printPage->append("");
	printPage->append("<b>Date of last Update........: </b>" + DateLastUpdate);
	printPage->append("<b>Date of last Work Unit.....: </b>" + DateLastWU);
	printPage->append("");
	printPage->append("<b>Active CPUs within 50 days.: </b>" + ActiveCPU50);
	printPage->append("<b>Active CPUs within 7 days..: </b>" + ActiveCPU7);
	printPage->append("");
	printPage->append("<b>Total Score................: </b>" + TotalScore);
	printPage->append("<b>Total Work Units...........: </b>" + TotalWUs);
	printPage->append("");
	printPage->append("<b>Overall Ranking............: </b>" + OverallRank);	

}

void personalStats::printStats()
{
	QPrinter printer;

     	QPrintDialog *dlg = new QPrintDialog(&printer, this);
     	if (dlg->exec() != QDialog::Accepted)
        	return;

     	printPage->document()->print(&printer);
}

void personalStats::exportPDF()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Export Personal Stats in PDF",
                                                     QString(), "*.pdf");
     	if (!fileName.isEmpty()) 
     	{
        	if (QFileInfo(fileName).suffix().isEmpty())
        		fileName.append(".pdf");
         
         	QPrinter printer(QPrinter::HighResolution);
         
         	printer.setOutputFormat(QPrinter::PdfFormat);
	        printer.setOutputFileName(fileName);
         
         	formatPrintPage();
         
         	printPage->document()->print(&printer);
     	}
}

bool personalStats::UpdateInProgress()
{
	QFile file(FW_PERSONALSTATS);

    	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    		return true;
    
    	while (!file.atEnd()) 
    	{
        	QString line = file.readLine();
        	if (line.contains("Stats update in progress")) 
        	{
        		file.close();
        		return true;
       		}
    	}
    
   	file.close();
   	return false;
}

bool personalStats::brokenConnection()
{
	QFile file(FW_PERSONALSTATS);

    if (file.size()==0) return true;
    else return false;
}

void personalStats::reload(QString tn, QString un)
{
	if (fetch(tn, un))
	{
		parse(tn, un);
		print(tn, un);
		
		printButton->setEnabled(true);
		pdfButton->setEnabled(true);
	}
}

bool personalStats::fetch(QString tn, QString un)
{
	QProcess *proc = new QProcess(this);
	
	QString wget;
	
	wget = "wget ""http://fah-web.stanford.edu/cgi-bin/main.py?qtype=userpage&teamnum="+tn+"&username="+un+""" -O ";
	wget = wget + FW_PERSONALSTATS;

	proc->start(wget);
	
	proc->waitForFinished();
	
	if ((!UpdateInProgress())&&(!brokenConnection()))
	{
		MSG(FW_NAME,
        	   tr("Your Personal Stats have been successfully downloaded!\n\n"
        	   "You may now open the 'Personal Stats' window to view the results."));
        	return true;
    	} 
    	else if (UpdateInProgress())
    	{
    		WARN(FW_NAME,
           		tr("Personal Stats could not be fetched! Server update is in progress..."));
        	return false;
    	}
    	else if (brokenConnection())
    	{
    		WARN(FW_NAME,
           		tr("Personal Stats could not be fetched! This computer doesn't seem to have a working internet connection!"));
        	return false;
   		}
    	proc->kill();
    	return true;
}

void personalStats::parse(QString tn, QString un)
{
	QString line;
 	QString nextLine;
 	int cnt = 0;
 	
 	QFile file(FW_PERSONALSTATS);
  
    	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    
    	//TeamName = "Doctor's Nest";
    
    	bool found = false;
    	while (!file.atEnd()) 
	{
        	QString line = file.readLine();
	        cnt += 1;
        	int ind1, ind2;
        
        	if (line.contains(un)&&(!found))
        	{
        		found = true;
        	  	QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("right>") + 33;
        	  	ind2 = nextLine.indexOf("<B");
        	  	DateLastUpdate = nextLine.mid(ind1, ind2 - ind1);
        	  	DateLastUpdate = DateLastUpdate.simplified();
      		}
      		else if (line.contains("Date of last work unit"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<font") + 14;
        	  	ind2 = nextLine.indexOf("</font>");
        	  	DateLastWU = nextLine.mid(ind1, ind2 - ind1);
     		}
     		else if (line.contains("Total score"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<font") + 14;
        	  	ind2 = nextLine.indexOf("</font>");
        	  	TotalScore = nextLine.mid(ind1, ind2 - ind1);
     		}
     		else if (line.contains("Overall rank (if points are combined)"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<font") + 14;
        	  	ind2 = nextLine.indexOf("</font>");
        	  	OverallRank = nextLine.mid(ind1, ind2 - ind1);		
     		}
     		else if (line.contains("Active processors (within 50 days)"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<font") + 14;
        	  	ind2 = nextLine.indexOf("</font>");
        	  	ActiveCPU50 = nextLine.mid(ind1, ind2 - ind1);
     		}
     		else if (line.contains("Active processors (within 7 days)"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<font") + 14;
        	  	ind2 = nextLine.indexOf("</font>");
        	  	ActiveCPU7 = nextLine.mid(ind1, ind2 - ind1);		
     		}
     		else if (line.contains("<td> Team </td>"))
      		{
      			QString nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf(tn) + 8;
        	  	ind2 = nextLine.indexOf("</a>");
        	  	TeamName = nextLine.mid(ind1, ind2 - ind1);	
     		}
     		else if (line.contains("<TD> WU</TD>"))
      		{
      			QString nextLine = file.readLine();
      			nextLine = file.readLine();
        	  	ind1 = nextLine.indexOf("<b>") + 4;
        	  	ind2 = nextLine.indexOf("</b>");
        	  	TotalWUs = nextLine.mid(ind1, ind2 - ind1);	
     		}
	}
		
	file.close();
}	
	
void personalStats::print(QString tn, QString un)
{
	generalInfo->clear();
	
	generalInfo->append("<b>Name.......................: </b>" + un);
	generalInfo->append("");
	generalInfo->append("<b>Date of last Update........: </b>" + DateLastUpdate);
	generalInfo->append("<b>Date of last Work Unit.....: </b>" + DateLastWU);
	generalInfo->append("");
	generalInfo->append("<b>Active CPUs within 50 days.: </b>" + ActiveCPU50);
	generalInfo->append("<b>Active CPUs within 7 days..: </b>" + ActiveCPU7);
	generalInfo->append("");
	generalInfo->append("<b>Total Score................: </b>" + TotalScore);
	generalInfo->append("<b>Total Work Units...........: </b>" + TotalWUs);
	generalInfo->append("");
	generalInfo->append("<b>Overall Ranking............: </b>" + OverallRank);	
}


