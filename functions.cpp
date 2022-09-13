 #include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_LEN 128

int str_len( char s[] )
{	
 
	 int znak;
 		for(int i=0;i < MAX_LEN;i++){
  			if(s[i] != '\0') {
  			znak++;	
			} else {
				break;
			}
  		}
  return znak;
}

int lwr_str_cnt( char s[] )
{
  int male_litery;
  for(int i=0;i < MAX_LEN;i++){
	  	if(s[i] != '\0') {
	  		if(s[i] >= 97 && s[i] <= 122 ) male_litery++;
			} else {
			break;
			}
	  
  }
  return male_litery;
}

int upr_str_cnt( char s[] )
{
   int duze_litery;
  for(int i=0;i < MAX_LEN;i++){
  	if(s[i] != '\0') {
	  		if(s[i] >= 65 && s[i] <= 90) duze_litery++;
			} else {
			break;
			}
  }
  return duze_litery;
}


int dgt_str_cnt( char s[] )
{
    int cyfry;
  for(int i=0;i < MAX_LEN;i++){
  		if(s[i] != '\0') {
	  			if(s[i] >= 48 && s[i] <= 57) cyfry++;
			} else {
			break;
			}
  }
  return cyfry;
}


int nalpha_str_cnt( char s[] )
{
 int znak;
 		for(int i=0;i < MAX_LEN;i++){
 			if(s[i] != '\0') {
	  			if(s[i] >= 48 && s[i] <= 57 || s[i] >= 97 && s[i] <= 122 || s[i] >= 65 && s[i] <= 90) znak++;
			} else {
			break;
			}
  		
  }
  return znak;
}

int chr_str_cnt( char c, char s[] )
{		
		int znak;
  		for(int i=0;i < MAX_LEN;i++){
  			if(s[i] != '\0') {
	  			if(s[i] == c) znak++;
			} else {
			break;
			}
  		}
  return znak;
}

int chr_str_pos( char c, char s[] )
{
 		int znak;
  		for(int i=0;i < MAX_LEN;i++){
  			if(s[i] != '\0') {
	  			if(s[i] == c) {
  				znak = i;
				break;	
			  }
			} 		
  		}
  		return znak;
}

int chr_str_rpos( char c, char s[] )
{
  int j=0,i = MAX_LEN; // 
  int znak;
  		do{
  			if(s[i] == c) {
  				znak = i;
  				break;
			  }
			  i--;
			j++; 
		  }while(MAX_LEN > j);
  		return znak;
}

void str_rev( char s[] )
{
  int znak;
 		for(int i=0;i < MAX_LEN;i++){
  			if(s[i] != '\0') {
  			znak++;	
			} else {
				break;
			}
  		}
  for(int i= znak; 0 <= i; i--){
	  	cout << s[i];
    }
}

int main()
{

  char line[ MAX_LEN ];
  char c;
  int pos;

  cout << "\n\nWpisz linie tekstu: ";
  cin.getline( line, MAX_LEN );
  cout << "\nLiczba znakow           : " << str_len( line );
  cout << "\nLiczba malych liter     : " << lwr_str_cnt( line );
  cout << "\nLiczba duzych liter     : " << upr_str_cnt( line );
  cout << "\nLiczba cyfr             : " << dgt_str_cnt( line );
  cout << "\nLiczba alfanumerycznych : " << nalpha_str_cnt( line );

  cout << "\n\nPodaj pojedynczy znak: ";
  cin.get( c );

  cout << "\nLiczba wystapien znaku  " << c << " : " << chr_str_cnt( c, line );

  if( ( pos = chr_str_pos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od poczatku : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  if( ( pos = chr_str_rpos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od konca : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  cout << "\n\nNapis oryginalny : " << line;
  cout << "\nNapis odwrocony  : " ;  str_rev( line );

  cin.ignore();
  cin.get();
  return EXIT_SUCCESS;
}
