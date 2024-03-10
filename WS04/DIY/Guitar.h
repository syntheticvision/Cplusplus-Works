/***********************************************************************
// OOP244 Workshop #4 p2
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 1 March 2024
// I have done all the coding by myself and only partially used internet to figure out a few things.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca {

    const int MAT_LEN = 10;
    const int MAX_LEN = 15;

    class GuitarStr {
        char m_material[MAT_LEN]{};
        double m_gauge{};
    public:
        const char* material()const;
        double gauge()const;
        GuitarStr();
        GuitarStr(const char* ma, double ga);
    };

    class Guitar {
        GuitarStr* m_string;
        int m_numStrings;
        char m_model[MAX_LEN];
    public:
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], int ns, const char* mod);
        ~Guitar();
        bool changeString(const GuitarStr& gs, int sn);
        void reString(GuitarStr strs[], int ns);
        void deString();
        bool strung() const;
        bool matchGauge(double ga) const;
        std::ostream& display(std::ostream& os = std::cout) const;

    };


}

#endif
