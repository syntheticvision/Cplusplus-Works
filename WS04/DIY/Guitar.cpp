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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca {
    const char* GuitarStr::material() const {
        return m_material;
    }
    double GuitarStr::gauge() const {
        return m_gauge;
    }
    GuitarStr::GuitarStr() {};

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    };

    Guitar::Guitar(const char* mod) {
        m_numStrings = 0;
        m_string = nullptr;
        strcpy(m_model, mod);
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
        if (ns > 0 && mod != nullptr && mod[0] != '\0') {
            m_numStrings = ns;
            strcpy(m_model, mod);
            m_string = new GuitarStr[ns];
            for (int i = 0; i < ns; i++) {
                m_string[i] = strs[i];
            }
        }
        else
        {
            m_numStrings = 0;
            m_string = nullptr;
            m_model[0] = '\0';
        }

    }

    Guitar :: ~Guitar() {
        delete[] m_string;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn < m_numStrings) {
            m_string[sn] = gs;
            return true;
        }
        return false;   
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        if (ns > 0) {
            m_numStrings = ns;
            m_string = new GuitarStr[ns];
            for (int i = 0; i < ns; i++) {
                m_string[i] = strs[i];
            }
        }
        else {
            m_numStrings = 0;
            m_string = nullptr;
        }
    }

    void Guitar::deString() {
        delete[] m_string;
        m_string = nullptr;
    }

    bool Guitar::strung() const {
        if (m_string != nullptr && m_numStrings > 0 ) {
            return true;
        }
        return false;
    }

    bool Guitar::matchGauge(double ga) const {
        for(int i = 0; i < m_numStrings; i++){
            if (m_string[i].gauge() == ga) {
                return true;
            }
        }
        return false;
    }

    std::ostream& Guitar ::display(std::ostream& os) const {
        if (m_string == nullptr || m_numStrings == 0) {
            os << "***Empty Guitar***" << endl;
        }
        else {
            os << "Guitar Model:" << " " << m_model << endl;
            os << "Strings:" << " " << m_numStrings << endl;
            for (int i = 0; i < m_numStrings; i++) {
                os << "#" << (i + 1) << std::setw(MAT_LEN) << m_string[i].material() << " | "
                    << std::fixed << std::setprecision(1) << m_string[i].gauge() << endl;
            }
        }
        return os;
    }
}