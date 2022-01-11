#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "studentas.h"
#include "studentass.h"
#include "lib.hpp"

int main() {
  
  string fn = " ";
  string varg = " ";
  string kiet = " ";
  
  ifstream ifStudentuFailas;
  ofstream ofVargsiukaiFailas;
  ofstream ofKietiakaiFailas;

  vector<studentas> grupeStudentaiStruct;
  vector<studentas> vargsiukaiStruct;

  vector<Studentass> grupeStudentaiClass;
  vector<Studentass> vargsiukaiClass;
 
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)
  
  auto titStruct = grupeStudentaiStruct.begin();
  auto titClass = grupeStudentaiClass.begin();
  
  cout << std::fixed;

  for(int i = 100000; i <= 1000000; i=i*10){
    fn = to_string(i) + " studentu sarasas.txt";
    varg = to_string(i) + " vargsiukai.txt";
    kiet = to_string(i) + " kietiakai.txt";
    
    //----------STRUCT-----------//
    ofVargsiukaiFailas.open(varg, std::ofstream::out  |std::ofstream::trunc);
    ofVargsiukaiFailas.close();
    
    ofKietiakaiFailas.open(kiet, std::ofstream::out  |std::ofstream::trunc);
    ofKietiakaiFailas.close();

    start = std::chrono::high_resolution_clock::now();

    ifStudentuFailas.open(fn);
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

    ofVargsiukaiFailas.open(varg);
    writeTitle(ofVargsiukaiFailas);
    for(const auto &kint : vargsiukaiStruct) {
      writeResults(kint, ofVargsiukaiFailas);
    }
    ofVargsiukaiFailas.close();
    
    ofKietiakaiFailas.open(kiet);
    writeTitle(ofKietiakaiFailas);
    for(const auto &kint : grupeStudentaiStruct) {
      writeResults(kint, ofKietiakaiFailas);
    }
    ofKietiakaiFailas.close();

    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " studentų programos veikimo laikas su struct ";
    cout << diff.count() << "s" << endl;
    
    grupeStudentaiStruct.clear();
    vargsiukaiStruct.clear();

    grupeStudentaiStruct.shrink_to_fit();
    vargsiukaiStruct.shrink_to_fit();
    
    //------------CLASS--------------//
    ofVargsiukaiFailas.open(varg, ofstream::out | ofstream::trunc);
    ofVargsiukaiFailas.close();

    ofKietiakaiFailas.open(kiet, ofstream::out | ofstream::trunc);
    ofKietiakaiFailas.close();

    start = std::chrono::high_resolution_clock::now();

    ifStudentuFailas.open(fn);
    readFile(ifStudentuFailas, grupeStudentaiClass);
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

    ofVargsiukaiFailas.open(varg);
    writeTitle(ofVargsiukaiFailas);
    for(const auto &kint : vargsiukaiClass) {
      writeResults(ofVargsiukaiFailas, kint);
    }
    ofVargsiukaiFailas.close();

    ofKietiakaiFailas.open(kiet);
    writeTitle(ofKietiakaiFailas);
    for(const auto &kint : grupeStudentaiClass) {
      writeResults(ofKietiakaiFailas, kint);
    }
    ofKietiakaiFailas.close();

    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " studentų programos veikimo laikas su class ";
    cout << diff.count() << "s" << endl;
    cout << endl;

    grupeStudentaiClass.clear();
    vargsiukaiClass.clear();

    grupeStudentaiClass.shrink_to_fit();
    vargsiukaiClass.shrink_to_fit();

    fn.clear();
    varg.clear();
    kiet.clear();
  }
} 