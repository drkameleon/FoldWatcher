// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : teamStats.cpp
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
#include "clientList.h"
#include "fah_consts.h"
#include "fahClient.h"
#include "fahQueue.h"
#include "fahWuinfo.h"
#include "foldwatcher_consts.h"
#include "logWindow.h"
#include "mainWindow.h"
#include "Messages.h"
#include "teamStats.h"
#include "ui_mainwindow.h"


teamStats::teamStats( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
{
	setupUi(this);
	
	printPage = new QTextBrowser();
	printButton->setEnabled(false);
	pdfButton->setEnabled(false);
	
	QObject::connect(printButton, SIGNAL( clicked() ), this, SLOT( printStats() ) );
	QObject::connect(pdfButton, SIGNAL( clicked() ), this, SLOT( exportPDF() ) );
	
}

void teamStats::formatPrintPage()
{
	printPage->clear();
	printPage->append("<b><u>TEAM STATS</b></u>");
	printPage->append("powered by FoldWatcher");
	printPage->append("");
	printPage->append("");
	printPage->append("<b>Name                       : </b>" + TeamName);
	printPage->append("<b>ID                         : </b>" + TeamID);
	printPage->append("");
	printPage->append("<b>Date of last Work Unit     : </b>" + DateLastWU);
	printPage->append("<b>Active CPUs within 50 days : </b>" + ActiveCPU50);
	printPage->append("");
	printPage->append("<b>Total Score                : </b>" + TotalScore);
	printPage->append("<b>Total Work Units           : </b>" + TotalWUs);
	printPage->append("");
	printPage->append("<b>Overall Ranking            : </b>" + OverallRank);

	printPage->append("");
	printPage->append("<b>MEMBERS</b>");
	printPage->append("");
	
	for (int i=0; i < NOM; i++)
	{
		QString s = UserStats[i].URank + " : " + UserStats[i].UName + " " +  
					UserStats[i].UScore + " " + UserStats[i].UWU;
		
		printPage->append(s);
	}	
	
}

void teamStats::exportPDF()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Export Team Stats in PDF",
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

void teamStats::printStats()
{
	QPrinter printer;

	QPrintDialog *dlg = new QPrintDialog(&printer, this);
     	if (dlg->exec() != QDialog::Accepted)
        	return;

     	printPage->document()->print(&printer);

}

void teamStats::reload(QString tn)
{
	if (fetch(tn))
	{
		parse(tn);
		print();
		
		printButton->setEnabled(true);
		pdfButton->setEnabled(true);
	}
}

void teamStats::print()
{
	QTableWidgetItem *newItem;
	
	memberList->setRowCount(NOM);
	
	generalInfo->clear();
	
	//generalInfo->append("<b>Name                       : </b>" + TeamName);
	generalInfo->append("<b>ID                         : </b>" + TeamID);
	generalInfo->append("");
	generalInfo->append("<b>Date of last Work Unit     : </b>" + DateLastWU);
	generalInfo->append("<b>Active CPUs within 50 days : </b>" + ActiveCPU50);
	generalInfo->append("");
	generalInfo->append("<b>Total Score                : </b>" + TotalScore);
	generalInfo->append("<b>Total Work Units           : </b>" + TotalWUs);
	generalInfo->append("");
	generalInfo->append("<b>Overall Ranking            : </b>" + OverallRank);
	
	for (int i=0; i < NOM; i++)
	{
		newItem = new QTableWidgetItem(UserStats[i].URank);
     		memberList->setItem(i, 0, newItem);
     	
     		newItem = new QTableWidgetItem(UserStats[i].UName);
     		memberList->setItem(i, 1, newItem);
     	
     		newItem = new QTableWidgetItem(UserStats[i].UScore);
     		memberList->setItem(i, 2, newItem);
     		
     		newItem = new QTableWidgetItem(UserStats[i].UWU);
     		memberList->setItem(i, 3, newItem);
	}

}

bool teamStats::UpdateInProgress()
{
	QFile file(FW_TEAMSTATS);
    
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

bool teamStats::brokenConnection()
{
	QFile file(FW_TEAMSTATS);

    if (file.size()==0) return true;
    else return false;
}

bool teamStats::fetch(QString tn)
{
	QProcess *proc = new QProcess(this);

	QString wget;
	
	wget = "wget ""http://fah-web.stanford.edu/cgi-bin/main.py?qtype=teampage&teamnum="""+tn+" -O ";
	wget = wget + FW_TEAMSTATS;

	proc->start(wget);
	
	proc->waitForFinished();
	
	if ((!UpdateInProgress())&&(!brokenConnection()))
	{
		MSG(FW_NAME,
        	tr("Your Team Stats have been successfully downloaded!\n\n"
        	   "You may now open the 'Team Stats' window to view the results."));
        	return true;
    	} 
    	else if (UpdateInProgress())
    	{
    		WARN(FW_NAME,
           		tr("Team Stats could not be fetched! Server update is in progress..."));
        	return false;
    	}
    	else if (brokenConnection())
    	{
    		WARN(FW_NAME,
           		tr("Team Stats could not be fetched! This computer doesn't seem to have a working internet connection!"));
        	return false;
   		}
    	proc->kill();
    	return true;
}

void teamStats::parse(QString tn)
{
	QString line;
 	QString nextLine;
 	
 	int ind1, ind2;
 	
 	int count = 0;
 	
 	NOM = 0;
 	
 	QFile file(FW_TEAMSTATS);
    
    	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
		return;
   
	//TeamName = "Doctor's Nest";
    TeamID   = tn;

    	while (!file.atEnd()) 
	{
        	line = file.readLine();
        	QString backup = line;
        
        	if (line.contains("Date of last work unit"))
        	{
          		QString nextLine = file.readLine();
          		ind1 = nextLine.indexOf("<td align") + 21;
          		ind2 = nextLine.indexOf("</td>");
          		DateLastWU = nextLine.mid(ind1, ind2 - ind1);    
      		}	
      		else if (line.contains("Active CPUs within 50 days"))
      		{
      			QString nextLine = file.readLine();
          		ind1 = nextLine.indexOf("<td align") + 21;
          		ind2 = nextLine.indexOf("</td>");
          		ActiveCPU50 = nextLine.mid(ind1, ind2 - ind1); 
     		}
     		else if (line.contains("Grand Score"))
      		{
      			QString nextLine = file.readLine();
      			nextLine = file.readLine();
          		TotalScore = nextLine.simplified();
     		}	
     		else if (line.contains("Work Unit Count"))
      		{
      			QString nextLine = file.readLine();
      			nextLine = file.readLine();
          		TotalWUs = nextLine.simplified();	
        	}	
         	else if (line.contains("Team Ranking (incl. aggregate)"))
      		{
      			QString nextLine = file.readLine();
          		ind1 = nextLine.indexOf("<td") + 21;
          		ind2 = nextLine.indexOf("</td>");
          		nextLine = nextLine.mid(ind1, ind2 - ind1);
          		OverallRank = nextLine.simplified();	
          	
        	}
     		else if (line.contains("<TD> 1 </TD>"))
     		{
     			count = 0;
     			NOM = 1;
     			nextLine = backup.simplified();
    		
     			while (nextLine.contains("<TD> "+QString::number(NOM)+" </TD>"))
     			{
    				UserStats[count].URank = QString::number(NOM);
     			    
     				nextLine = file.readLine();
     				ind1 = nextLine.indexOf("> ") + 2;
          			ind2 = nextLine.indexOf(" <");
          			UserStats[count].UName = nextLine.mid(ind1, ind2 - ind1);
          			
          			nextLine = file.readLine();
     				ind1 = nextLine.indexOf("> ") + 2;
          			ind2 = nextLine.indexOf(" <");
          			UserStats[count].UScore = nextLine.mid(ind1, ind2 - ind1);
    				
    				nextLine = file.readLine();
     				ind1 = nextLine.indexOf("> ") + 2;
          			ind2 = nextLine.indexOf(" <");
          			UserStats[count].UWU = nextLine.mid(ind1, ind2 - ind1);
          			
          			for (int i = 0; i < 6; i++)
          			{
         				nextLine = file.readLine();
        			}
         				
          			NOM = NOM + 1;
          			count = count + 1;
          		
         		}
         		NOM -= 1;
         		
    		}	
     		
	}

	file.close();
}

