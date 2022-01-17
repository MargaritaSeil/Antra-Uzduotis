/*! \file studentass.h
* Sis header failas yra Studento klase.
* Taip pat yra kelios pagalbines global funkcijos.
*/
#ifndef STUDENTASS_H
#define STUDENTASS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#include "asmuo.h"

//! Derived klase, kuri yra is Base klases Asmuo, laikanti Studento informacija. 
class Studentass : public Asmuo {
  private:
    //! Laiko namu darbu pazymius, paz_ - float tipo vektorius. 
    std::vector <float> paz_;
    //! Laiko egzamino pazymi. 
    float egz_ { 0 };
    //! Laiko galutini pazymi.
    float galutinis_paz_ { 0 };
  
  public:
    //! Default konstruktorius.
    Studentass() {}
    //! Destructor su clear pazymius vektoriumi. 
    ~Studentass() { paz_.clear(); }
    //! Copy konstruktorius.
    Studentass(const Studentass &s);
    //! Copy assignment operatorius.
    Studentass &operator=(const Studentass &s) = default;
    //! Palyginimo operatorius <, palygina studentu vardus.
    bool operator < (const Studentass &s);  
    //! Palyginimo operatorius >, palygina studentu vardus.
    bool operator > (const Studentass &s);   
    //! Palyginimo operatorius ==, palygina studentu vardus.
    bool operator == (const Studentass &s);   
    //! Palyginimo operatorius !=, palygina studentu vardus.
    bool operator != (const Studentass &s);   

    //! paz_ setter'is.
    void setPaz(float paz) { paz_.push_back(paz); }
    //! egz_ setter'is.
    void setEgz(float egz) { egz_ = egz; }
    //! galutinis_paz_ setter'is.
    void setGal(float gal) { galutinis_paz_ = gal; }
    
    //! paz_ getter'is.
    std::vector <float> getPaz() const { return paz_; }
    //! egz_ getter'is.
    float getEgz() const { return egz_; }
    //! galutinis_paz_ getter'is.
    float getGal() const { return galutinis_paz_; }
    
    //! Funkcija, kuri isvalo pazymius. 
    void pazClear() { paz_.clear(); }
    //! Funkcija, kuri pasalina paskutini elementa is paz_.
    void pazPop() { paz_.pop_back(); }
    
    /*! Skaiciavimu funkcijos.
    * Skaiciuoja vidurki ir ji laiko vid kintamajame.
    * Skaiciavimu galutini bala ir ji laiko galutinis_paz_ kintamajame.
    */
    void pazSkaic();
};

/*! \relates Studentass
* Read file funkcija studentu sarasui. 
* Pirmas while ciklas skaito eilutes iki failo pabaigos.
* Antras while ciklas skaito duomenis is failo. 
  \param file ivesties failas, kuris laiko studentu informacija.
  \param grupe vektorius, kuris laiko nuskaityta informacija.
*/
void readFile(std::ifstream &file, std::vector<Studentass> &grupe);

/*! \relates Studentass 
* Antraciu formatavimas studentu rezultatu isvesties failui.
  \param file isvesties failas atrastes eilutei. 
*/
void writeTitle(std::ofstream &file); 

/*! \relates Studentass 
* Spausdina rezultatus i isvestied faila.
  \param file isvesties failas studentu inoformacijai, rezultatams.
  \param a prieigai prie studentu informacijos.
*/
void writeResults(std::ofstream &file, Studentass a);

/*! \relates Studentass 
* Palyginami studentu vardai ir surusuojami didejimo tvarka.
  \param a pirmas studentas.
  \param b antras studentas.
  \return nustato, kuris studentas eina pirmas su \a a < \a b palyginimu. 
*/    
bool compareNames(Studentass a, Studentass b);

/*! \relates Studentass
* Tikrina studento galutini pazymi.
  \param a priegai prie studentu informacijos.
  \return grazina true jeigu galutinis pazymys mazesnis uz 5.
*/
bool isLowGrade(Studentass a);


#endif


