#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien );

int main()
{
  double odsetki;
  // Test 1
  odsetki = odsetkiProgresywne( 1000, 4, 3 );
  if(odsetki == 125.50)
    cout << "\nTest 1: OK";
  else
    cout << "\nTest 1: Blad\n";

  // Test 2
  odsetki = odsetkiProgresywne( 1000, 10, 3 );
  if(odsetki == 343.91)
    cout << "\nTest 2: OK";
  else
    cout << "\nTest 2: Blad\n";

  // Test 3
   odsetki = odsetkiProgresywne( 1200, 5, 4 );
  if(odsetki == 459.98)
    cout << "\nTest 3: OK";
  else
    cout << "\nTest 3: Blad\n";

  // Test 4
   odsetki = odsetkiProgresywne( 1100, 7, 2 );
  if(odsetki == 263.55)
    cout << "\nTest 4: OK";
  else
    cout << "\nTest 4: Blad\n";
    


  return EXIT_SUCCESS;
}

double odsetkiProgresywne( double kwota, double lbDni, double odsetkiZaDzien){
	
	const double procent =odsetkiZaDzien/100.0;
	do{
	kwota =	kwota + (kwota *procent);
	lbDni--;
	}while(lbDni !=0);
	kwota = floor(((kwota-1000)*1000)/10)/100;
	return kwota;
}

