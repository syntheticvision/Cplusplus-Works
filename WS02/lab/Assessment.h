/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	Assessment.h
// Version 1.0
//
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 28 Jan 2024
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H
#define MAX_CHAR 60 
struct Assessment 
    {                    
        double *m_mark;  
        char *m_title;   
    };

namespace seneca
{
    bool read(int &value, FILE *fptr);
    bool read(double &value, FILE *fptr);
    bool read(char *cstr, FILE *fptr);
    bool read(Assessment &assess, FILE *fptr);
    void freeMem(Assessment *&aptr, int size);
    int read(Assessment *&aptr, FILE *fptr);
}
#endif