#ifndef STUDENTAS_H    
#define STUDENTAS_H    

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>

struct studentas{
    std::string vardas, pavarde;
    std::vector <float> paz;
    float egz;
    float galutinis_paz;
};

void generateList(std::vector<studentas> &grupe, int nStudentai, int nPaz);

//void writeTitle(std::ofstream &file);
void writeResults(studentas kint, std::ofstream &file);
void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(studentas kint, std::ofstream &file);

void readFile(std::ifstream &file, std::vector<studentas> &grupe);

void pazSkaic(std::vector<studentas> &grupe);

int randomNumber();
bool compareNamesStruct(studentas a, studentas b);
bool isLowGradeStruct(studentas kint);

#endif     