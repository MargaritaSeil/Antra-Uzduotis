#include "studentass.h"

Studentass::Studentass(const Studentass &s) {
  vardas_ = s.getVardas();
  pavarde_ = s.getPavarde();
  paz_ = s.getPaz();
  egz_ = s.getEgz();
  galutinis_paz_ = s.getGal();
}

bool Studentass::operator < (const Studentass &s) {
  if (vardas_ != s.getVardas()) {
    return vardas_ < s.getVardas();
  }
  else {
    return pavarde_ < s.getPavarde();
  }
}

bool Studentass::operator > (const Studentass &s) {
  if (vardas_ != s.getVardas()) {
    return vardas_ > s.getVardas();
  }
  else {
    return pavarde_ > s.getPavarde();
  }
}

bool Studentass::operator == (const Studentass &s) {
  if( vardas_ == s.getVardas() &&
      pavarde_ == s.getPavarde() &&
      paz_ == s.getPaz() &&
      egz_ == s.getEgz() &&
      galutinis_paz_ == s.getGal()
  ){
    return true;
  }
  else{
    return false;
  }
}

bool Studentass::operator != (const Studentass &s) {
  if( vardas_ != s.getVardas() ||
      pavarde_ != s.getPavarde() ||
      paz_ != s.getPaz() ||
      egz_ != s.getEgz() ||
      galutinis_paz_ != s.getGal()
  ){
    return true;
  }
  else{
    return false;
  }
}

void Studentass::pazSkaic() {
  float vid;
  vid=std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size();
  galutinis_paz_ = 0.4 * vid + 0.6 * egz_;
}

void readFile(std::ifstream &file, std::vector<Studentass> &grupe){
  Studentass stud;
  float readPaz;
  std::string readLine, vardas, pavarde;
  
  stud.pazClear();
  if(file.is_open()){
    getline(file, readLine);
    while(getline(file, readLine)) {
      std::istringstream iss(readLine);

      iss >> vardas >> pavarde;
      stud.setVardas(vardas);
      stud.setPavarde(pavarde);

      while(iss >> readPaz){
        stud.setPaz(readPaz);
        stud.setEgz(readPaz);
      }
			stud.pazPop();
      grupe.push_back(stud);
      stud.pazClear();
    }
  }
  else{ std::cout << "neišeina atidaryti failo"; }
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

bool compareNames(Studentass a, Studentass b){
	return a.getVardas().compare(b.getVardas()) < 0;
}

bool isLowGrade(Studentass a) {
  return a.getGal() < 5;
}

