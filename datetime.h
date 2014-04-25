// ******************************************************
//
//    Library Name:    DATETIME.C
//    Version:          1.00
//    Author:           Patrick G Horneker
//    Environment:     EMX 0.9c
//
// ******************************************************

/*

  Before I got the EMX/GCC system on both home and office PCs, I 
  was writing in Turbo Pascal for DOS.  Date handling in DOS is much
  simpler than handling in UNIX, much less OS/2.

  I also see that it makes more sense to handle dates in numeric form
  than in string form.  Look at how many commercial software packages
  handle dates this way.

  This library simplifies the retrieval of the system date and time
  for your programs.  Standard UNIX function calls for getting the
  system date are used.

  EMX uses the time_t structure to store the current system date and
  time when it is retrieved using the time() function.

  This header represents the public portion of the date and time library.
  

   Since this is free code, I am required to include the following:


    PGH Date/Time Module for EMX.
    Copyright (C) 1998  Patrick G Horneker

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful, but 
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


   You can contact me concerning this module at any of these 
   addresses:

   e-mail 1:  2084647@mcimail.com
   e-mail 2:  cbsivlp@ibm.net
   e-mail 3:  os2junction@geocities.com

   Website:   http://www.geocities.com/SiliconValley/Heights/4301

*/



// ******************************************************
//
//                          Function Prototypes
//
// ******************************************************

// This function is called first.

extern void GetRawDateTime(char *RawDate);

// Then you can call these functions.

extern int ExtractMonth(const char *RawDate);
extern int ExtractDayOfWeek(const char *RawDate);
extern int ExtractDayOfMonth(const char *RawDate);
extern int ExtractYear(const char *RawDate);
extern int ExtractHour(const char *RawDate);
extern int ExtractMinute(const char *RawDate);
extern int ExtractSecond(const char *RawDate);


