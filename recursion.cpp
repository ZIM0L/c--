#include <iostream>
#include <cstdlib>
#include <math.h>

double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien );

using namespace std;
int main(int argc, char *argv[]){
	double kwota,lbDni,odsetkiZaDzien;
	double odsetki = odsetkiProgresywne( 1000, 4,3 );
}

double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien){
	
	const double procent = odsetkiZaDzien/100;	
	kwota =	kwota + (kwota *procent);
	--lbDni;
		if(lbDni !=0){				
					odsetkiProgresywne(kwota,lbDni,odsetkiZaDzien);		
		}	
		if(lbDni == 0){
			kwota = floor(((kwota-1000)*1000)/10)/100;
			cout << "\nIlosc zebranych odsetek: " << kwota;
		}
};
