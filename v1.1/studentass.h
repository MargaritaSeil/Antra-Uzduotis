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

class Studentass{
  private:
    std::string vardas_ { "vardas" }; 
    std::string pavarde_ { "pavarde" };
    std::vector <float> paz_;
    float egz_ { 0 };
    float galutinis_paz_ { 0 };
  
  public:
    Studentass() {}
    ~Studentass() { paz_.clear(); }
    void setVardas(std::string s) { vardas_ = s; }
    void setPavarde(std::string s) { pavarde_ = s; }
    void setPaz(float paz) { paz_.push_back(paz); }
    void setEgz(float egz) { egz_ = egz; }
    void setGal(float gal) { galutinis_paz_ = gal; }
    
    std::string getVardas() const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }
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
    
bool compareNamesClass(Studentass a, Studentass b);
bool isLowGradeClass(Studentass a);


#endif


