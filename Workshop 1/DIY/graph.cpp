/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p2.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name: Babak Ghafourigivi
Student ID: 165118233
Student email: bghafourigivi@myseneca.ca
Date: 14 Jan 2023
***********************************************************************/

#include <iostream>
#include "graph.h"
#include "io.h"
using namespace std;

// Maximum number of samples in an graph
const int GRAPH_WIDTH = 65;

namespace seneca
{
    // prints a graph comparing the sample values visually
    void printGraph(int samples[], int noOfSamples, const char *label)
    {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++)
        {
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 10);
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max)
    {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++)
        {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH.
    int findMax(int samples[], int noOfSamples)
    {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++)
        {
            if (max < samples[i])
                max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }

    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples)
    {
        int i;
        for (i = 0; i < noOfSamples; i++)
        {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }
}