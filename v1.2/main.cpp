#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include "studentass.h"
#include "lib.hpp"

int main() {
  ifstream ifStudentuFailas("studentų sąrašas.txt");
  ofstream ofStudentuFailas("studentų sąrašas.txt");
  ofstream ofVargsiukaiFailas("vargšiukai.txt");
  ofstream ofKietiakaiFailas("kietiakai.txt");

  vector<Studentass> grupeStudentai;
  vector<Studentass> vargsiukai;

  Studentass stud;
  
  int nStudentai;
  int nPaz;
  
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)

  auto titClass = grupeStudentai.begin();
  
  cout << std::fixed;
  cout << "Įveskite studentų skaičių: " <<endl;
  cin >> nStudentai;
  
  cout<<"Kiek bus namų darbų pažymių? ";
  cin >> nPaz;
  
  grupeStudentai.reserve(nStudentai);

  generateList(grupeStudentai, nStudentai, nPaz);
  sort(grupeStudentai.begin(), grupeStudentai.end(), compareNames);

  writeGeneratedListTitle(nPaz, ofStudentuFailas);
  for(const auto &kint : grupeStudentai) { 
    writeGeneratedList(ofStudentuFailas, kint);   
  }
  ofStudentuFailas.close();

  grupeStudentai.clear();
  grupeStudentai.shrink_to_fit();

  start = std::chrono::high_resolution_clock::now();

  stud.readFile(ifStudentuFailas, grupeStudentai, stud);
  ifStudentuFailas.close();

  for(auto &kint : grupeStudentai){
    kint.pazSkaic();
  }
  
  copy_if(
    grupeStudentai.begin(),
    grupeStudentai.end(),
    std::back_inserter(vargsiukai),
    isLowGrade);
  
  titClass = remove_if(grupeStudentai.begin(), grupeStudentai.end(), isLowGrade);
  grupeStudentai.erase(titClass, grupeStudentai.end());

  sort(grupeStudentai.begin(), grupeStudentai.end(), compareNames);
  sort(vargsiukai.begin(), vargsiukai.end(), compareNames);

  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukai) {
    writeResults(ofVargsiukaiFailas, kint);
  }
  ofVargsiukaiFailas.close();

  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : grupeStudentai) {
    writeResults(ofKietiakaiFailas, kint);
  }
  ofKietiakaiFailas.close();

  grupeStudentai.clear();
  vargsiukai.clear();

  grupeStudentai.shrink_to_fit();
  vargsiukai.shrink_to_fit();

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai << " studentų programos veikimo laikas su class ";
  cout << diff.count() << "s" << endl;

}
