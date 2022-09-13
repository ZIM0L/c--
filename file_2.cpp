#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <cstdio>
#include <fstream>
#include <ctime>

using namespace std;

class RideReport
{
public:
  RideReport(const char *fileName);
  ~RideReport();
  bool readData();
  int processData();
  int getSpeedUpCount();
  int getSlowDownCount();
  int getLeftTurnCount();
  int getRightTurnCount();
  bool saveCleanedData(const char *fileName);
  bool saveAsText(const char *fileName);
  bool saveAsXML(const char *fileName);

private:
	const char *fileName;
    int file_size,a,b,l,r;	
    string file_name;
    string text = "";  
    string clear_text;
    
};


int main(int argc, char *argv[]){
  RideReport report("dane.txt");
  if(report.readData()){
  	 if(report.processData() > 0){
  	  cout << "\nLiczba akcji " << report.processData();
      cout << "\nPrzyspieszenia: " << report.getSpeedUpCount();
      cout << "\nHamowania: " << report.getSlowDownCount();
      cout << "\nW lewo: " << report.getLeftTurnCount();
      cout << "\nW prawo: " << report.getRightTurnCount();
      if(report.saveCleanedData("dane_czyste.txt"))
        cout << "\nOczyszczone dane zapisane";
      if(report.saveAsText("raport.txt"))
        cout << "\nRaport tekstowy zapisany";
      if(report.saveAsXML("raport.xml"))
        cout << "\nPlik XML zapisany";	
	   } else {
	   	cout << "Plik nie zawiera zadnych pozadanych akcji !";
	   }  
  } else {
  	cout << "Plik jest Pusty !";
  }
  return EXIT_SUCCESS;
}

 
RideReport::RideReport(const char *fileName){

	if(fileName != "") {
		this -> fileName = fileName;
		file_name = fileName;
	} 

}
  
RideReport::~RideReport(){
	delete fileName;
	cout << "Blad krytyczny";
} 
  
bool RideReport::readData(){
	ifstream file;
	file.open(fileName);
	if(file.good()) {
		getline(file,text);	
	file.close();
	file.clear();		
	return true;
	} else{
		return false;
	}
}

int RideReport::processData(){
	int i=0,actions=0;
	while(text[i] != '\0'){
		if(text[i] == 'a' || text[i] == 'b' || text[i] == 'l' || text[i] == 'r' || text[i] == 'A' || text[i] == 'B' || text[i] == 'L' || text[i] == 'R' ) {
		actions++;
		}
		i++;
	}
	if(actions == 0) return 0;
	return actions;
} 

int RideReport::getSpeedUpCount(){
	int i=0,actions=0;
	while(text[i] != '\0'){
		if(text[i] == 'a' || text[i] == 'A' ) {
		actions++;
		}
		i++;
	}
	a = actions;
	return actions;
} 


int RideReport::getSlowDownCount(){
	int i=0,actions=0;
	while(text[i] != '\0'){
		if(text[i] == 'b'|| text[i] == 'B') {
		actions++;
		}
		i++;
	}
	b = actions;
	return actions;
} 


int RideReport::getLeftTurnCount(){
	int i=0,actions=0;
	while(text[i] != '\0'){
		if(text[i] == 'l'|| text[i] == 'L') {
		actions++;
		}
		i++;
	}
	l = actions;
	return actions;
} 

int RideReport::getRightTurnCount(){
	int i=0,actions=0;
	while(text[i] != '\0'){
		if(text[i] == 'r'|| text[i] == 'R') {
		actions++;
		}
		i++;
	}
	r = actions;
	return actions;
} 


bool RideReport::saveCleanedData(const char *fileName){
	ofstream file;
	file.open(fileName);
	if(file.good()){
		int i=0;
		while(text[i] != '\0'){
			if(text[i] == 'a' || text[i] == 'b' || text[i] == 'l' || text[i] == 'r' || text[i] == 'A' || text[i] == 'B' || text[i] == 'L' || text[i] == 'R' ) {
			clear_text = clear_text + text[i]; 
			}
			i++;
		}
		file << clear_text;
		file.close();
		file.clear();
		return true;	
	}
	
} 

bool RideReport::saveAsXML(const char *fileName){
	ofstream file_raport;
	file_raport.open(fileName);
	if(file_raport.good()){
		file_raport << "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
		time_t ttime = time(0);
		tm *local_time = localtime(&ttime);
		file_raport << "\n<report file=\" "<< file_name << "\" date= \"" << 1900 + local_time->tm_year << "-" << 1 + local_time->tm_mon << "-" << local_time->tm_mday << "\" time=\"" << 0 + local_time->tm_hour << ":" << 0 + local_time->tm_min << ":" << 0 + local_time->tm_sec << "\">";
		file_raport << "\n<speed-up-count>" <<  a  << "</speed-up-count>";
		file_raport << "\n<slow-down-count>" <<  b  << "</slow-down-count>";
		file_raport << "\n<left-turn-count>" <<  l  << "</left-turn-count>";
		file_raport << "\n<right-turn-count>" <<  r  << "</right-turn-count>";
		file_raport << "</report>";
		return true;	
	}
	
} 

bool RideReport::saveAsText (const char *fileName){
	ofstream file_raport;
	file_raport.open(fileName);
	if(file_raport.good()){
		file_raport << "Raport dla pliku: " << file_name;
		time_t ttime = time(0);
		tm *local_time = localtime(&ttime);
		file_raport << "\nData utworzenia:  " << 1900 + local_time->tm_year << "-" << 1 + local_time->tm_mon << "-" << local_time->tm_mday;
		file_raport << "\nCzas utworzenia:  " << 0 + local_time->tm_hour << ":" << 0 + local_time->tm_min << ":" << 0 + local_time->tm_sec;
		file_raport << "\nPrzyspieszenia" << ": " <<  a;
		file_raport << "\nHamowania" << ": " <<b;
		file_raport << "\nLewo" << ": " << l;
		file_raport << "\nPrawo" << ": " << r;		
		return true;	
	}
	
} 






