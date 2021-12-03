#include "studentas.h"

void generateList(std::vector<studentas> &grupe, int nStudentai, int nPaz) {
  studentas temp;
  float random;

  for (int i=0; i<nStudentai; i++) {
    temp.vardas = "Vardas" + std::to_string(i+1);
    temp.pavarde = "Pavarde" + std::to_string(i+1);

    for(int j=0; j<nPaz; j++) {
      
      random = (float) randomNumber();
      temp.paz.push_back(random);
    }
    
    random = (float) randomNumber();
    temp.egz = random;

    grupe.push_back(temp);
    temp.paz.clear();
  }
}

void pazSkaic(std::vector<studentas> &grupe) {
  float vid;

  for (auto &kint: grupe) {
    vid=std::accumulate(kint.paz.begin(), kint.paz.end(), 0.0) / kint.paz.size();
    kint.galutinis_paz = 0.4 * vid + 0.6 * kint.egz;
  }
}

int randomNumber() {

  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(0, 10);
  
  return dist(mt);
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

void writeGeneratedList(studentas kint, std::ofstream &file) {
  
  if(file.is_open()) {
    file<<std::setw(15)<<std::left<<kint.vardas<<std::setw(15)<<std::left<<kint.pavarde;
    for(int i = 0; i < kint.paz.size(); i++) {
      file<<std::setw(5)<<std::setprecision(3)<<kint.paz[i];
    }
    file<<std::setw(5)<<std::setprecision(3)<<kint.egz<<std::endl;
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
