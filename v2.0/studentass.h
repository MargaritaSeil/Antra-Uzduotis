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

class Studentass : public Asmuo {
  private:
    std::vector <float> paz_;
    float egz_ { 0 };
    float galutinis_paz_ { 0 };
  
  public:
    Studentass() {}
    ~Studentass() { paz_.clear(); }
    Studentass(const Studentass &s); //copy constructor
    Studentass &operator=(const Studentass &s) = default; //copy assignment operator
    bool operator < (const Studentass &s);  
    bool operator > (const Studentass &s);   
    bool operator == (const Studentass &s);   
    bool operator != (const Studentass &s);   

    void setPaz(float paz) { paz_.push_back(paz); }
    void setEgz(float egz) { egz_ = egz; }
    void setGal(float gal) { galutinis_paz_ = gal; }
    
    std::vector <float> getPaz() const { return paz_; }
    float getEgz() const { return egz_; }
    float getGal() const { return galutinis_paz_; }
    
    void pazClear() { paz_.clear(); }
    void pazPop() { paz_.pop_back(); }

    void pazSkaic();
};

void readFile(std::ifstream &file, std::vector<Studentass> &grupe);

void writeTitle(std::ofstream &file); 
void writeResults(std::ofstream &file, Studentass a);
    
bool compareNames(Studentass a, Studentass b);
bool isLowGrade(Studentass a);

bool ifVargsiukai(float galutinis);
bool ifKietiakai(float galutinis);
float galutinisPaz(float vidur, float exam);

#endif


