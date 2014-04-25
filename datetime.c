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

// We start by rounding up the headers we need to implement this
// function library.

#include <stdlib.h> // I always include this header in my programs.
#include <time.h>  // This is the key to this module.
#include <math.h>  // Needed for atoi() function.

// Then, set up that most important global to this unit, the variable
// needed to call time() and ctime().

time_t *UNIX_Date_and_Time;


// ******************************************************
//
//                          Function Prototypes
//
// ******************************************************

// This function is called first.

void GetRawDateTime(char *RawDate);

// Then you can call these functions.

int ExtractMonth(const char *RawDate);
int ExtractDayOfWeek(const char *RawDate);
int ExtractDayOfMonth(const char *RawDate);
int ExtractYear(const char *RawDate);
int ExtractHour(const char *RawDate);
int ExtractMinute(const char *RawDate);
int ExtractSecond(const char *RawDate);


// The following below are the actual functions.


/*  

   The GetDateTime function does the actual call of the system date
   and time UNIX style.  This function returns the date and time in
   the string format.  The rest of this library contains functions that
   you can use to process the day and time from that string.

   After having examined the string retrieved from the ctime() function,
   I have come up with this table of offsets these functions are based
   upon:

    offset    length                        description
   ------+--------+--------------------------------------
        0  |     3     |  Day of the week in initial capital format
        4  |     3     |  Month of year in initial capital format
        8  |     2     |  Day of the month
       11  |     2     |  Hour in 24 hour format
       14  |     2     |  Minute
       17  |     2     |  Second
       20  |     4     |  Year

  In the last field, I recommend extracting all four digits, especially 
  since the year 2000 is fast approaching.

  Also note, there is no hundreth of the second like there is in DOS.

  The Extract Month is an example of how I convert the month field
  to its numeric value.

*/

void GetRawDateTime(char *RawDate)
{
  time(UNIX_Date_and_Time);  
  strcpy(RawDate,ctime(UNIX_Date_and_Time));
};  

/*

  The next set of functions extracts the string into its numeric
  equivalents for functions that would use numeric values for date
  processing.  

*/


int ExtractMonth(const char *RawDate)
{
  int Temp;	       // I use this to return the result.
  char RawMonth[4]; // We need a temporary string to extract the
                       // month.

  // The first thing we need to do is extract the month name from
  // the retrieved string.

  RawMonth[0] = RawDate[4];
  RawMonth[1] = RawDate[5];
  RawMonth[2] = RawDate[6];
  RawMonth[3] = 0;  // Terminate string with a NULL

  // Then we find out what that month is.  So this may not be the best
  // way to find out.  But since this is structured and obvious, it 
  // should work.  Since the strcmp() returns 0 if the strings match
  // exactly, each if statement is compared to the value 0.  I feel this
  // makes more sense and more obvious than simply negating the
  // conditional statement just to see if the strings compare exactly.

  if (strcmp(RawMonth,"Jan") == 0)
  {
    Temp = 1;
  };
  if (strcmp(RawMonth,"Feb") == 0)
  {
    Temp = 2;  
  };
  if (strcmp(RawMonth,"Mar") == 0)
  {
    Temp = 3;
  };
  if (strcmp(RawMonth,"Apr") == 0)
  {
    Temp = 4;
  };
  if (strcmp(RawMonth,"May") == 0)
  {
    Temp = 5;
  };
  if (strcmp(RawMonth,"Jun") == 0)
  {
    Temp = 6;
  };
  if (strcmp(RawMonth,"Jul") == 0)
  {
    Temp = 7;
  };
  if (strcmp(RawMonth,"Aug") == 0)
  {
    Temp = 8;
  };
  if (strcmp(RawMonth,"Sep") == 0)
  {
    Temp = 9;
  };
  if (strcmp(RawMonth,"Oct") == 0)
  {
    Temp = 10;
  };
  if (strcmp(RawMonth,"Nov") == 0)
  {
    Temp = 11;
  };
  if (strcmp(RawMonth,"Dec") == 0)
  {
    Temp = 12;
  };
  return Temp;
};


int ExtractDayOfWeek(const char *RawDate)
{
  int Temp;	// I use this to return the result.
  char RawDOW[4]; // We need a temporary string to 
                      // grab the day of week.

  // The first thing we need to do is extract the day of the week from
  // the retrieved string.

  RawDOW[0] = RawDate[0];
  RawDOW[1] = RawDate[1];
  RawDOW[2] = RawDate[2];
  RawDOW[3] = 0;  // Terminate string with a NULL

  // In this function, Sunday is represented by a 1 and Saturday is
  // represented by a 7.

  if (strcmp(RawDOW,"Sun") == 0)
  {
    Temp = 1;
  };
  if (strcmp(RawDOW,"Mon") == 0)
  {
    Temp = 2;  
  };
  if (strcmp(RawDOW,"Tue") == 0)
  {
    Temp = 3;
  };
  if (strcmp(RawDOW,"Wed") == 0)
  {
    Temp = 4;
  };
  if (strcmp(RawDOW,"Thu") == 0)
  {
    Temp = 5;
  };
  if (strcmp(RawDOW,"Fri") == 0)
  {
    Temp = 6;
  };
  if (strcmp(RawDOW,"Sat") == 0)
  {
    Temp = 7;
  };
  return Temp;
};


// These next functions simply extract the day of the month
// and convert it to an integer.

int ExtractDayOfMonth(const char *RawDate)
{
  char RawDay[3];
  int Temp;

  RawDay[0] = RawDate[8];
  RawDay[1] = RawDate[9];
  RawDay[2] = 0;

  Temp = atoi(RawDay);
  return Temp;
};

// This next function always retrieves a four digit number.  This is
// especially useful for Year 2000 projects.

int ExtractYear(const char *RawDate)
{
  char RawYear[5];
  int Temp;

  RawYear[0] = RawDate[20];
  RawYear[1] = RawDate[21];
  RawYear[2] = RawDate[22];
  RawYear[3] = RawDate[23];
  RawYear[4] = 0;	// Terminate strings with a NULL character.

  Temp = atoi(RawYear);
  return Temp;
};


// ... and that is just for the system date.

// The time is simpler than the date.  Each field is two characters
// long.


int ExtractHour(const char *RawDate)
{
  char RawHour[3];
  int Temp;

  RawHour[0] = RawDate[11];
  RawHour[1] = RawDate[12];
  RawHour[2] = 0;	// Terminate strings with a NULL character.

  Temp = atoi(RawHour);
  return Temp;
};


int ExtractMinute(const char *RawDate)
{
  char RawMinute[3];
  int Temp;

  RawMinute[0] = RawDate[14];
  RawMinute[1] = RawDate[15];
  RawMinute[2] = 0;	// Terminate strings with a NULL character.

  Temp = atoi(RawMinute);
  return Temp;
};


int ExtractSecond(const char *RawDate)
{
  char RawSecond[5];
  int Temp;

  RawSecond[0] = RawDate[17];
  RawSecond[1] = RawDate[18];
  RawSecond[2] = 0;	// Terminate strings with a NULL character.

  Temp = atoi(RawSecond);
  return Temp;
};


