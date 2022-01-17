/*! \file asmuo.h
* Sis header filas yra Asmens failas.
*/
#ifndef ASMUO_H
#define ASMUO_H

#include <iostream>
#include <string>

//! abstarkti base klase
class Asmuo {
  protected:
    //! Laiko studento varda.
    std::string vardas_ { "vardas" };
    //! Laiko studento pavarde.
    std::string pavarde_ { "pavarde" };
  
  public:
    //! Default konstruktorius.
    Asmuo() {}
    //! grynas virtualus destruktorius.
    virtual ~Asmuo() = 0;
    //! Copy konstruktorius.
    Asmuo(const Asmuo &a);
    //! Copy assignment operatorius.
    Asmuo &operator=(const Asmuo &a) = default;

    //! vardas_ setter'is.
    void setVardas(std::string s) { vardas_ = s; }
    //! pavarde_ setter'is.
    void setPavarde(std::string s) { pavarde_ = s; }

    //! vardas_ getter'is.
    std::string getVardas() const { return vardas_; }
    //! pavarde_ getter'is.
    std::string getPavarde() const { return pavarde_; }
};


#endif 