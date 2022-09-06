#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

class kwadrat {
	public: 
		double a;
		kwadrat(double a){
			this -> a = a;
		}
		~kwadrat() {
		}
		
		double pole_kwadrat();
};
class prostokat {
	public: 
		double a,b;
		prostokat(double a,double b){
			this -> a = a;
			this -> b = b;
		}
		~prostokat() {
		}
		
		double pole_prostokat();
};
class kolo {
	public: 
		double a;
		kolo(double a){
			this -> a = a;
		}
		~kolo() {
		}
		
		double pole_kolo();
};
class trojkat {
	public: 
		double a,h;
		trojkat(double a,double h){
			this -> a = a;
			this -> h = h;
		}
		~trojkat() {
		}
		
		double pole_trojkat();
};
class trapez {
	public: 
		double a,b,h;
		trapez(double a,double b,double h){
			this -> a = a;
			this -> b = b;
			this -> h = h;
		}
		~trapez() {
		}
		
		double pole_trapez();
};
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
						kwadrat* kw = new kwadrat(a);
						cout <<	"Pole wynosi: " << kw -> pole_kwadrat();
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
						prostokat* pr = new prostokat(a,b);
						cout <<	"Pole wynosi: " << pr -> pole_prostokat();
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
						kolo* ko = new kolo(a);
						cout <<	"Pole wynosi: " << ko -> pole_kolo();
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
						trojkat* tr = new trojkat(a,h);
						cout <<	"Pole wynosi: " << tr -> pole_trojkat();
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
						trapez* tra = new trapez(a,b,h);
						cout <<	"Pole wynosi: " << tra -> pole_trapez();
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

double kwadrat::pole_kwadrat(){
	double Pole = a*a;
	return Pole;
}
double prostokat::pole_prostokat(){
	double Pole = a*b;
	return Pole;
}
double kolo::pole_kolo(){
	double Pole = 3.14*(a*a);
	return Pole;
}
double trojkat::pole_trojkat(){
	double Pole = (a*h)/2;
	return Pole;
}
double trapez::pole_trapez(){
	double Pole = ((a+b)*h)/2;
	return Pole;
}


