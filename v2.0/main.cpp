#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include "studentass.h"
#include "asmuo.h"
#include "lib.hpp"

int main1() {
  
  string fn = " ";
  string varg = " ";
  string kiet = " ";
  
  ifstream ifStudentuFailas;
  ofstream ofVargsiukaiFailas;
  ofstream ofKietiakaiFailas;

  vector<Studentass> grupeStudentai;
  vector<Studentass> vargsiukai;
 
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)
  
  auto tit = grupeStudentai.begin();
  
  cout << std::fixed;

  for(int i = 1000; i <= 1000; i=i*10){
    fn = to_string(i) + " studentu sarasas.txt";
    varg = to_string(i) + " vargsiukai.txt";
    kiet = to_string(i) + " kietiakai.txt";

    ofVargsiukaiFailas.open(varg, ofstream::out | ofstream::trunc);
    ofVargsiukaiFailas.close();

    ofKietiakaiFailas.open(kiet, ofstream::out | ofstream::trunc);
    ofKietiakaiFailas.close();

    start = std::chrono::high_resolution_clock::now();

    ifStudentuFailas.open(fn);
    readFile(ifStudentuFailas, grupeStudentai);
    ifStudentuFailas.close();

    for(auto &kint : grupeStudentai){
      kint.pazSkaic();
    }
    
    copy_if(
      grupeStudentai.begin(),
      grupeStudentai.end(),
      std::back_inserter(vargsiukai),
      isLowGrade);
    
    tit = remove_if(grupeStudentai.begin(), grupeStudentai.end(), isLowGrade);
    grupeStudentai.erase(tit, grupeStudentai.end());

    sort(grupeStudentai.begin(), grupeStudentai.end(), compareNames);
    sort(vargsiukai.begin(), vargsiukai.end(), compareNames);

    ofVargsiukaiFailas.open(varg);
    writeTitle(ofVargsiukaiFailas);
    for(const auto &kint : vargsiukai) {
      writeResults(ofVargsiukaiFailas, kint);
    }
    ofVargsiukaiFailas.close();

    ofKietiakaiFailas.open(kiet);
    writeTitle(ofKietiakaiFailas);
    for(const auto &kint : grupeStudentai) {
      writeResults(ofKietiakaiFailas, kint);
    }
    ofKietiakaiFailas.close();

    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " studentų programos veikimo laikas su class ";
    cout << diff.count() << "s" << endl;
    cout << endl;

    grupeStudentai.clear();
    vargsiukai.clear();

    grupeStudentai.shrink_to_fit();
    vargsiukai.shrink_to_fit();

    fn.clear();
    varg.clear();
    kiet.clear();
  }
  
  return 0;
} 