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
Date: 20 Jan 2023
***********************************************************************/

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H
namespace seneca
{
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples);
    // Finds the largest sample in the samples array, if it is larger than 70,
    // therwise it will return 70.
    int findMax(int samples[], int noOfSamples);
    // Prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max);
    // Prints a graph comparing the sample values visually
    void printGraph(int samples[], int noOfSamples, const char *label);
}
#endif