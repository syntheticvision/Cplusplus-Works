/***********************************************************************
OOP244 Workshop # p2:
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name: Babak Ghafourigivi
Student ID: 165118233
Student email: bghafourigivi@myseneca.ca
Date: 20 Jan 2023
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca
{

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark
   {
      char name[21];
      char surname[31];
      int mark;
   };

   /// <summary>
   /// Tries to open the students' mark data file.
   /// If successful it will print a report based on the
   /// date in the file.
   /// </summary>
   /// <param name="filename">, holds the data file name</param>
   /// <returns>True if the date files is opened succesfully,
   /// otherwise returns false</returns>

   bool printReport(const char *filename);
}
#endif // !SENECA_STMARK_H
