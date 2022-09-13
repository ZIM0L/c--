#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

double kwadrat (double a);
double prostokat (double a, double b);
double kolo(double a);
double trojkat(double a,double h);
double trapez(double a,double b,double h);
bool poprawnosc (double a);

int main(int argc, char *argv[]){
	int Figura;
	double a,b,h;
	cout << "Program do obliczen pol figur plaskich." << endl;
	bool blad = false,wyjscie;
do{
	cout << "Program do obliczen pol figur plaskich. Prosze wybrac jedna z figur poprzez podanie numeru ksztaltu" << endl;
	cout  << "1: kwadrat" << endl << "2: prostokat" << endl <<"3: kolo" << endl <<"4: trojkat" << endl <<"5: trapez" << endl;
	cin >> Figura;	
	if(cin.good()){
		switch(Figura){
			case 1:{
				cout << "Prosze podac wymiary boku kwadrata: " << endl;
				cin >> a;
					if(cin.good()){
						if(!poprawnosc(a)) {
							cout << "Podano nieodpowiednia liczbe" << endl; 
							cin.clear();
							break;	
						}
						cout <<	"Pole wynosi: " << kwadrat (a);
						cin.clear();
						break;
					} else{
						blad = true;
						cout << "Podano zle dane" << endl;
						cin.clear();
						break;
					}
			}
			case 2: {
				cout << "Prosze podac wymiary 2 bokow prostokata: " << endl;
				cin >> a >> b;
					if(cin.good()){
						if(!poprawnosc(a)) {
							cout << "Podano nieodpowiednia liczbe" << endl; 
							cin.clear();
							break;	
						}
						cout <<	"Pole wynosi: " << prostokat(a,b);
						cin.clear();
					} else{
						blad = true;
						cout << "Podano zle dane" << endl;
						cin.clear();
						break;
					}
				break;
			}
				case 3: {
				cout << "Prosze podac wymiary promienia kola: " << endl;
				cin >> a;
					if(cin.good()){
						if(!poprawnosc(a)) {
							cout << "Podano nieodpowiednia liczbe" << endl; 
							cin.clear();
							break;	
						}
						cout <<	"Pole wynosi: " << kolo(a);
						cin.clear();
					} else{
						blad = true;
						cout << "Podano zle dane" << endl;
						cin.clear();
						break;
					}
				break;
			}
			case 4: {
				cout << "Prosze podac wymiary podstawy oraz wysokosci trojkata: " << endl;
				cin >> a >> h;
					if(cin.good()){
						if(!poprawnosc(a)) {
							cout << "Podano nieodpowiednia liczbe" << endl; 
							cin.clear();
							break;	
						}
						cout <<	"Pole wynosi: " << trojkat(a,h);
						cin.clear();
					} else{
						blad = true;
						cout << "Podano zle dane" << endl;
						cin.clear();
						break;
					}
				break;
			}
			default:{
				cout << "Wybrano liczbe poza wyborem!";
				break;
			}
			case 5: {
				cout << "Prosze podac wymiary 2 podstaw oraz wysokosci trapezu: " << endl;
				cin >> a >> b >> h;
					if(cin.good()){
						if(!poprawnosc(a)) {
							cout << "Podano nieodpowiednia liczbe" << endl; 
							cin.clear();
							break;	
						}
						cout <<	"Pole wynosi: " << trapez(a,b,h);
						cin.clear();
					} else{
						blad = true;
						cout << "Podano zle dane" << endl;
						cin.clear();
						break;
					}
				break;
			}
		}
		
		// zapytanie czy chce powtarzac
		string wybor;
			if(blad == false){
			cout << endl << "Czy chcesz kontynuowac obliczenia dla innych figur ? pisz TAK lub NIE." << endl;		
			do{
				cin.clear();
				cin.ignore();
				cin >> wybor;
				if((!wybor.compare("TAK")) || (!wybor.compare("NIE"))){  // 1 LUB 0
					if(!wybor.compare("TAK")) {
						wyjscie = false;
						break;
					}
					if(!wybor.compare("NIE")){
						wyjscie = true;
						break;
					}
				} else cout << "Wpisz TAK lub NIE\n";	
			}while(true);
	
			 if(wyjscie == true) break;	
			} else break; 
			
			
	}	else{
		cout << "Zakonczono Program. Dziekuje za uzycie programu";
		break;
	}
}while(true);

}
bool poprawnosc (double a){
	if(a <= 0) return false;
	else return true;
}

double kwadrat (double a){
	double Pole = a*a;
	return Pole;
}
double prostokat (double a,double b){
	double Pole = a*b;
	return Pole;
}
double kolo(double a){
	double Pole = 3.14*(a*a);
	return Pole;
}
double trojkat(double a,double h){
	double Pole = (a*h)/2;
	return Pole;
}
double trapez(double a,double b,double h){
	double Pole = ((a+b)*h)/2;
	return Pole;
}


