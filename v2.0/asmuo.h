#ifndef ASMUO_H
#define ASMUO_H

#include <iostream>
#include <string>

class Asmuo {
  protected:
    std::string vardas_ { "vardas" }; 
    std::string pavarde_ { "pavarde" };
  
  public:
    Asmuo() {}
    virtual ~Asmuo() = 0;
    Asmuo(const Asmuo &a);
    Asmuo &operator=(const Asmuo &a) = default;
    
    void setVardas(std::string s) { vardas_ = s; }
    void setPavarde(std::string s) { pavarde_ = s; }

    std::string getVardas() const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }
};


#endif 