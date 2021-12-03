#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include "studentas.h"
#include "studentass.h"
#include "lib.hpp"

int main() {
  ifstream ifStudentuFailas("studentų sąrašas.txt");
  ofstream ofStudentuFailas("studentų sąrašas.txt");
  ofstream ofVargsiukaiFailas("vargšiukai.txt");
  ofstream ofKietiakaiFailas("kietiakai.txt");

  vector<studentas> grupeStudentaiStruct;
  vector<studentas> vargsiukaiStruct;
  
  vector<Studentass> grupeStudentaiClass;
  vector<Studentass> vargsiukaiClass;

  Studentass stud;
  
  int nStudentai;
  int nPaz;
  
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)

  auto titStruct = grupeStudentaiStruct.begin();
  auto titClass = grupeStudentaiClass.begin();
  
  //-------------LIST GENERATION------------//
  cout << std::fixed;
  cout << "Įveskite studentų skaičių: " <<endl;
  cin >> nStudentai;
  
  cout<<"Kiek bus namų darbų pažymių? ";
  cin >> nPaz;
  
  grupeStudentaiStruct.reserve(nStudentai);

  generateList(grupeStudentaiStruct, nStudentai, nPaz);

  sort(grupeStudentaiStruct.begin(), grupeStudentaiStruct.end(), compareNamesStruct);

  writeGeneratedListTitle(nPaz, ofStudentuFailas);
  for(const auto &kint : grupeStudentaiStruct) { 
    writeGeneratedList(kint, ofStudentuFailas);   
  }
  ofStudentuFailas.close();

  grupeStudentaiStruct.clear();
  grupeStudentaiStruct.shrink_to_fit();

  //--------------STRUCT------------//

  start = std::chrono::high_resolution_clock::now();

  readFile(ifStudentuFailas, grupeStudentaiStruct);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiStruct);
  
  copy_if(
    grupeStudentaiStruct.begin(),
    grupeStudentaiStruct.end(),
    std::back_inserter(vargsiukaiStruct),
    isLowGradeStruct);
    
  titStruct = remove_if(grupeStudentaiStruct.begin(), grupeStudentaiStruct.end(), isLowGradeStruct);
  grupeStudentaiStruct.erase(titStruct, grupeStudentaiStruct.end());

  sort(grupeStudentaiStruct.begin(), grupeStudentaiStruct.end(), compareNamesStruct);
  sort(vargsiukaiStruct.begin(), vargsiukaiStruct.end(), compareNamesStruct);

  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukaiStruct) {
    writeResults(kint, ofVargsiukaiFailas);
  }
  ofVargsiukaiFailas.close();
  
  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : grupeStudentaiStruct) {
    writeResults(kint, ofKietiakaiFailas);
  }
  ofKietiakaiFailas.close();

  grupeStudentaiStruct.clear();
  vargsiukaiStruct.clear();

  grupeStudentaiStruct.shrink_to_fit();
  vargsiukaiStruct.shrink_to_fit();

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai << " studentų programos veikimo laikas su struct ";
  cout << diff.count() << "s" << endl;

  //--------------CLASS--------------//

  ofVargsiukaiFailas.open("vargšiukai.txt", ofstream::out | ofstream::trunc);
  ofVargsiukaiFailas.close();

  ofKietiakaiFailas.open("kietiakai.txt", ofstream::out | ofstream::trunc);
  ofKietiakaiFailas.close();

  start = std::chrono::high_resolution_clock::now();

  ifStudentuFailas.open("studentų sąrašas.txt");
  stud.readFile(ifStudentuFailas, grupeStudentaiClass, stud);
  ifStudentuFailas.close();

  for(auto &kint : grupeStudentaiClass){
    kint.pazSkaic();
  }
  
  copy_if(
    grupeStudentaiClass.begin(),
    grupeStudentaiClass.end(),
    std::back_inserter(vargsiukaiClass),
    isLowGradeClass);
  
  titClass = remove_if(grupeStudentaiClass.begin(), grupeStudentaiClass.end(), isLowGradeClass);
  grupeStudentaiClass.erase(titClass, grupeStudentaiClass.end());

  sort(grupeStudentaiClass.begin(), grupeStudentaiClass.end(), compareNamesClass);
  sort(vargsiukaiClass.begin(), vargsiukaiClass.end(), compareNamesClass);

  ofVargsiukaiFailas.open("vargšiukai.txt");
  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukaiClass) {
    writeResults(ofVargsiukaiFailas, kint);
  }
  ofVargsiukaiFailas.close();

  ofKietiakaiFailas.open("kietiakai.txt");
  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : grupeStudentaiClass) {
    writeResults(ofKietiakaiFailas, kint);
  }
  ofKietiakaiFailas.close();

  grupeStudentaiClass.clear();
  vargsiukaiClass.clear();

  grupeStudentaiClass.shrink_to_fit();
  vargsiukaiClass.shrink_to_fit();

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai << " studentų programos veikimo laikas su class ";
  cout << diff.count() << "s" << endl;

}