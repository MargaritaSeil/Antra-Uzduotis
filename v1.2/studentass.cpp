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

void generateList(std::vector<Studentass> &grupe, int nStudentai, int nPaz) {
  Studentass temp;
  float random;

  for (int i=0; i<nStudentai; i++) {
    temp.setVardas( "Vardas" + std::to_string(i+1) );
    temp.setPavarde( "Pavarde" + std::to_string(i+1) );

    for(int j=0; j<nPaz; j++) {
      
      random = (float) randomNumber();
      temp.setPaz(random);
    }
    
    random = (float) randomNumber();
    temp.setEgz(random);

    grupe.push_back(temp);
    temp.clearPaz();
  }
}

void writeGeneratedListTitle(int nPaz, std::ofstream &file) {
  if(file.is_open()) {
    file<<std::setw(15)<<std::left<<"Vardas"<<std::setw(15)<<std::left<<"Pavarde";
    for(int i = 0; i < nPaz; i++) {
      file<<std::setw(5)<<std::left<<"nd" + std::to_string(i+1);
    }
    file<<std::setw(5)<<std::left<<"Egz."<<std::endl;
  }
  else {
    std::cout << "negalima įrašyti." ;
  }
}

void writeGeneratedList(std::ofstream &file, Studentass a) {
  
  if(file.is_open()) {
    file<<std::setw(15)<<std::left<<a.getVardas()<<std::setw(15)<<std::left<<a.getPavarde();
    for(int i = 0; i < a.getPaz().size(); i++) {
      file<<std::setw(5)<<std::setprecision(3)<<a.getPaz()[i];
    }
    file<<std::setw(5)<<std::setprecision(3)<<a.getEgz()<<std::endl;
  }
  else {
    std::cout << "negalima įrašyti." ;
  }
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

int randomNumber() {

  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(0, 10);
  
  return dist(mt);
}

bool compareNames(Studentass a, Studentass b){
	return a.getVardas().compare(b.getVardas()) < 0;
}

bool isLowGrade(Studentass a) {
  return a.getGal() < 5;
}

