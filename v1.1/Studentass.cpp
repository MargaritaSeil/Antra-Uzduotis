#include "studentass.h"

void Studentass::readFile(std::ifstream &file, std::vector<Studentass> &grupe, Studentass &studentas){
  float readPaz;
  std::string readLine;
  
  paz_.clear();
  if(file.is_open()){
    getline(file, readLine);
    while(getline(file, readLine)) {
      std::istringstream iss(readLine);
      iss >> vardas_ >> pavarde_;
      
      while(iss >> readPaz){
        paz_.push_back(readPaz);
        egz_ = readPaz;
      }
			paz_.pop_back();
      grupe.push_back(studentas);
      paz_.clear();
    }
  }
  else{ std::cout << "neišeina atidaryti failo"; }
}

void Studentass::pazSkaic() {
  float vid;
  vid=std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size();
  galutinis_paz_ = 0.4 * vid + 0.6 * egz_;
}

void writeTitle(std::ofstream &file) {
  if(file.is_open()){
    file<<std::setw(15)<<std::left<<"Vardas"<<std::setw(15)<<std::left<<"Pavarde"<<std::setw(15)<<std::left<<"Galutinis"<<std::setw(15)
    <<"\n-------------------------------------------\n";
  }
  else {
    std::cout << "negalima įrašyti. ";
  }
}

void writeResults(std::ofstream &file, Studentass a){
  if(file.is_open()) {
    file<<std::setw(15)<<a.getVardas()<<std::setw(15)<<a.getPavarde();
    file<<std::setw(15)<<std::setprecision(3)<<a.getGal()<<std::endl;
    }
  else {
    std::cout << "negalima įrašyti." ;
  }
}

bool compareNamesClass(Studentass a, Studentass b){
	return a.getVardas().compare(b.getVardas()) < 0;
}

bool isLowGradeClass(Studentass a) {
  return a.getGal() < 5;
}

