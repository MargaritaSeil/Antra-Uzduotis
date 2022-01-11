#include "studentas.h"

void pazSkaic(std::vector<studentas> &grupe) {
  float vid;

  for (auto &kint: grupe) {
    vid=std::accumulate(kint.paz.begin(), kint.paz.end(), 0.0) / kint.paz.size();
    kint.galutinis_paz = 0.4 * vid + 0.6 * kint.egz;
  }
}

bool compareNamesStruct(studentas a, studentas b){
	return a.vardas.compare(b.vardas) < 0;
}

// write to file 
void writeResults(studentas kint, std::ofstream &file){

  if(file.is_open()) {
    file<<std::setw(15)<<kint.vardas<<std::setw(15)<<kint.pavarde;
    file<<std::setw(15)<<std::setprecision(3)<<kint.galutinis_paz<<std::endl;
    }
  else {
    std::cout << "negalima įrašyti." ;
  }
}

void readFile(std::ifstream &file, std::vector<studentas> &grupe){
  studentas readStud;
  float readPaz;
  std::string readLine;
  
  if(file.is_open()){
    getline(file, readLine);
    while(getline(file, readLine)) {
      std::istringstream iss(readLine);
      iss >> readStud.vardas >> readStud.pavarde;
      
      while(iss >> readPaz){
        readStud.paz.push_back(readPaz);
        readStud.egz = readPaz;
      }
			readStud.paz.pop_back();
      grupe.push_back(readStud);
      readStud.paz.clear();
    }
  }
  else{ std::cout << "neišeina atidaryti failo"; }
}

bool isLowGradeStruct(studentas kint) {
  return kint.galutinis_paz < 5;
}