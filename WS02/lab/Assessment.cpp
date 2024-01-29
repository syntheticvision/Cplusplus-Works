/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	Assessment.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "Assessment.h"
#include <iostream>
using namespace std;

namespace seneca
{
    bool read(int &value, FILE *fptr)
    {
        if (fscanf(fptr, "%d[^\n]", &value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool read(double &value, FILE *fptr)
    {
        if (fscanf(fptr, "%lf[^,]", &value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool read(char *cstr, FILE *fptr)
    {
        if (fscanf(fptr, ",%60[^\n]\n", cstr))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool read(Assessment &asmnt, FILE *fptr)
    {
        char temptitle[MAX_CHAR];
        double tempmarks = 0;
        if (read(tempmarks, fptr))
        {
            asmnt.m_mark = new double;
            *asmnt.m_mark = tempmarks;

            read(temptitle, fptr);
            asmnt.m_title = new char[strlen(temptitle) + 1];
            strncpy(asmnt.m_title, temptitle, strlen(temptitle) + 1);
            return true;
        }
        else
        {
            return false;
        }
    }
    void freeMem(Assessment *&aptr, int size)
    {
        if (aptr)
        {
            for (int i = 0; i < size; i++)
            {
                if (aptr[i].m_mark)
                {
                    delete aptr[i].m_mark;
                }
                if (aptr[i].m_title)
                {
                    delete[] aptr[i].m_title;
                }
            }
        }
        delete[] aptr;
    }
    int read(Assessment *&aptr, FILE *fptr)
    {
        int x = 0, i = 0;
        int count = 0;
        read(x, fptr);
        aptr = new Assessment[x];
        for (i = 0; (i < x) && (!feof(fptr)); i++)
        {
            read(aptr[i], fptr);
            count++;
        }
        if (count != x)
        {
            freeMem(aptr, count);
            return false;
        }
        else
        {
            return x;
        }
    }
}
