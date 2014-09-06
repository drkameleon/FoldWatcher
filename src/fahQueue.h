// FoldWatcher
// ---------------------
// Coded by Dr.K@meleon <drkameleon@hotmail.com>
// 
// homepage : http://kameleon-nest.blogspot.com
//            http://sourceforge.net/projects/foldwatcher/
// ============================
// Filename : fahQueue.h
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

#ifndef __FAHQUEUE_H__
#define __FAHQUEUE_H__

#define le2(x)	((((x)[1]&0xFF)<<8)|((x)[0]&0xFF))
#define le4(x)	(((x)[3]<<24)|(((x)[2]&0xFF)<<16)|(((x)[1]&0xFF)<<8)|((x)[0]&0xFF))
#define be4(x)	(((x)[0]<<24)|(((x)[1]&0xFF)<<16)|(((x)[2]&0xFF)<<8)|((x)[3]&0xFF))

struct queueformat
{
	quint32 version; /**< 0000 Queue (client) version (v2.17 and above) */
	quint32 current; /**< 0004 Current index number */
	struct qs
	{
		quint32  stat;      /**< 000 Status */
		char z004[4];  		/**< 004 Pad for Windows, others as of v4.01 */
		quint32  tdata[8];	/**< 008 Time data (epoch 0000 1jan00 UTC) */
		quint32  svr1;      /**< 040 Server IP address (until v3.0) */
		quint32  ustat;     /**< 044 Upload status */
		char url[128];      /**< 048 Web address for core downloads */
		quint32  m176;      /**< 176 Misc1a */
		quint32  core;      /**< 180 Core_xx number (hex) */
		quint32  m184;      /**< 184 Misc1b */
		quint32  dsiz;      /**< 188 wudata_xx.dat file size */
		char z192[16];
		union
		{
			struct
			{
				char proj[2];     /**< 208 Project number (LE) */
				char run[2];      /**< 210 Run (LE) */
				char clone[2];    /**< 212 Clone (LE) */
				char gen[2];      /**< 214 Generation (LE) */
				char issue[2][4]; /**< 216 WU issue time (LE) */
			} f; 				  /**< Folding@home data */
			struct
			{
				char proj[2];     /**< 208 Project number (LE) */
				quint16  miscg1;  /**< 210 Miscg1 */
				char issue[2][4]; /**< 212 WU issue time (LE) */
				quint16  miscg2;  /**< 220 Miscg2 */
				quint16  miscg3;  /**< 222 Miscg3 */
			} g; 				  /**< Genome@home data */
		} wuid; 				  /**< 208 Work unit ID path information */
		char z224[36];
		char mid[4];    		/**< 260 Machine ID (LE) */
		unsigned char svr2[4];  /**< 264 Server IP address */
		quint32  port;      	/**< 268 Server port number */
		char type[64];  		/**< 272 Work unit type */
		char uname[64]; 		/**< 336 User Name */
		char teamn[64]; 		/**< 400 Team Number */
		char uid[8];    		/**< 464 Stored ID for unit (UserID + MachineID) (LE or BE, usually BE) */
		char bench[4];  		/**< 472 Benchmark (as of v3.24) (LE) */
		char m476[4];   		/**< 476 Misc3b (unused as of v3.24) (LE) */
		quint32  cpu_type;  	/**< 480 CPU type (LE or BE, sometimes 0) */
		quint32  os_type;   	/**< 484 OS type (LE or BE, sometimes 0) */
		quint32  cpu_spec;  	/**< 488 CPU species (LE or BE, sometimes 0) */
		quint32  os_spec;   	/**< 492 OS species (LE or BE, sometimes 0) */
		quint32  expire;   		/**< 496 Allowed time to return (seconds) */
		char z500[8];
		char aiflag[4]; 		/**< 508 Assignment info present flag (LE or BE) */
		char aitime[4]; 		/**< 512 Assignment timestamp (LE or BE) */
		char aidata[4]; 		/**< 516 Assignment info (LE or BE) */
		char csip[4];   		/**< 520 Collection server IP address (as of v5.00) (LE) */
		char dstart[4]; 		/**< 524 Download started time (as of v5.00) (BE) */
		char z528[16];
		char cores[4];  		/**< 544 Number of SMP cores (as of v5.91) (BE) */
		char tag[16];   		/**< 548 Tag of Work Unit (as of v5.00) */
		char z564[52];
		char memory[4]; 		/**< 616 Available memory (as of v6.00) (BE) */
		char z620[68];
		quint32  due[4];    	/**< 688 WU expiration time */
		quint32  plimit;    	/**< 704 Packet size limit (as of v5.00) */
		quint32  uploads;   	/**< 708 Number of upload failures (as of v5.00) */
	} entry[10]; 				/**< 0008 Array of ten queue entries */
	quint32  pfract;    /**< 7128 Performance fraction (as of v3.24) */
	quint32  punits;    /**< 7132 Performance fraction unit weight (as of v3.24) */
	quint32  drate;     /**< 7136 Download rate sliding average (as of v4.00) */
	quint32  dunits;    /**< 7140 Download rate unit weight (as of v4.00) */
	quint32  urate;     /**< 7144 Upload rate sliding average (as of v4.00) */
	quint32  uunits;    /**< 7148 Upload rate unit weight (as of v4.00) */
	char z7152[16]; 	/**< 7152 (as of v5.00) ...all zeros after queue conversion... */
};

class fahQueue
{
	public:
		fahQueue(QString path);
		void reload();
		QStringList output;
		queueformat queue;
		
		//////////
		// RUNNING CLIENT/INDEX PROPERTIES
		/////////////////////////////
		QString Version;
		QString Current; int nCurrent;
 		QString Status; int nStatus;
		QString CoreURL;
		QString CoreNo;
		QString WuinfoSize;
		
		QString ProjectNo;
		QString Run;
 		QString Clone;
 		QString Generation;
 		QString IssueTime;
 		QString MachineID;
 		 	
 		QString ServerIP;
 		QString ServerPort;
		QString WUType;
		QString Username;
		QString TeamNo;
 	
		QString StoredID;
	
 		QString CPU; 
 		QString OS;
	
 		QString Expiry;
 		QString Performance;
		
private:	
		QString path;
		
};	
	
#endif // __FAHQUEUE_H__		

