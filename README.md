FoldWatcher
===============

Copyright (C) 2008 Dr.Kameleon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

License
------------
FoldWatcher is free software. Please read the file LICENSE for details.

About
-----------
FoldWatcher is an integrated monitoring environment for Folding@Home Clients
designer for Linux and *nix Systems. It allows to quickly check the progress of
up to 100 clients and retrieve valuable information from the Work Unit 
being processed. It can fetch your personal stats or your team's stats and
show them into the main window, enabling even printing and exporting them in PDF. 
Along with the 'finstall' script, it can be used to start or stop running 
Folding@Home clients. Moreover, it integrates the ability - using either 
the RasMol Open-Source 3D Molecule Viewer or the JMol WebSite's Java Applet - 
to view the protein being folded.

Programming
-----------
FoldWatcher is entirely coded in C++, using the Qt (Version 4.3) library, 
which may allow in the future an easy porting of the application 
even to the Microsoft Windows environment.

System requirements
--------------
Linux or *nix - Any machine capable of running a modern X server, of either i386 or 
amd64 architecture.

Software requirements
--------------
FoldWatcher makes use of the Open-Source Molecule Viewer Rasmol and RasMol-Gtk. 
Even without this application being installed, FoldWatcher will try to evoque 
JMol WebSite's Java Applet integrated Molecule Viewer in order to be able to
show you the actual protein being folded.

Installation instructions
----------------
Please read the INSTALL file.


