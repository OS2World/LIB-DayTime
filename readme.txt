=============================================================================
readme.pgh                        README                          30-Jan-1998
=============================================================================

                   Copyright (c) 1998 by Patrick G Horneker


                Information on "PGH Date/Time Library for EMX"

                                Version 1.00



I wrote this library as part of a data conversion program that involved the
use of dates.

Before I got the EMX/GCC System, I was writing in Turbo Pascal for DOS.
Date handling in DOS is much simpler than date handling in UNIX or OS/2.

I could have used OS/2's internal date handling function calls.  However, I
want this library to be portable with other GCC compilers on other platforms.

The UNIX way of handling dates is by simply returning the number of seconds
elapsed since January 1, 1970.  A number of functions have been implemented to handle this number into a form used primarily for display and printing purposes, as well as date and time stamping of files.

When it comes to handling dates in many commercial applications I have come across, the DOS function calls handle dates differently, by implementing separate date and time function calls, and then by assigning each component of the date and time (e.g. hour, second, day of week, month, etc.) to separate variables.

This library attempts to bridge that gap through the use of functions I have implemented in this library.

Included in this archive is the following:


	DATETIME.C	The source code for the library.
	DATETIME.H	A public header file.
	DATETIME.O	Object file compiled with EMX 0.9c
	README		You're reading it.

To use this library, place DATETIME.O and DATETIME.H in your project's 
directory.  (You can also place DATETIME.C if you wish).

Then do the following:

1.  Insert the following into your list of #include statements.

	#include "datetime.h"

2.  Compile your program as usual.
3.  When linking, be sure to include datetime.o in the list of object files
    to link.

That's it.

Per GNU Public License, you can modify this library to suit your needs, or 
improve on it if you wish.

After all, this is only the first version of the library.


-------------------
CONTACT INFORMATION
-------------------

I can be contacted at the following e-mail addresses:

	2084647@mcimail.com
	cbsivlp@ibm.net
	os2junction@geocities.com


You can also visit my website at:

  http://www.geocities.com/SiliconValley/Heights/4301




