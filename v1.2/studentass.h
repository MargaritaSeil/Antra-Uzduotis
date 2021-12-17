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
    ~Studentass() {} //destructor
    Studentass(const Studentass &s) = default; //copy constructor
    Studentass &operator=(const Studentass &s) = default;
    
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
    
    void clearPaz(){ paz_.clear(); }

    void readFile(std::ifstream &file, std::vector<Studentass> &grupe, Studentass &studentas);
    void pazSkaic();
};

void generateList(std::vector<Studentass> &grupe, int nStudentai, int nPaz);

void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(std::ofstream &file, Studentass a);

void writeTitle(std::ofstream &file); 
void writeResults(std::ofstream &file, Studentass a);

int randomNumber();   
bool compareNames(Studentass a, Studentass b);
bool isLowGrade(Studentass a);


#endif


