#include <cstdlib>
#include <iostream>
using namespace std;
const int MAX_LEN = 128;


int str_len(char * s)
{
  int i;
  for(; *s != '\0'; ++s)  i++;
  return i;
}


int lwr_str_cnt(char * s)
{
  int i;
  for(; *s != '\0'; ++s) {
  	if (*s>= 97 && *s <=127) i++;  
  }
  return i;
}


int upr_str_cnt(char * s)
{
   int i;
  for(; *s != '\0'; ++s) {
  	if (*s>= 65 && *s <=90) i++;  
  }
  return i;
}


int dgt_str_cnt(char * s)
{
   int i;
  for(; *s != '\0'; ++s) {
  	if (*s>= 48 && *s <=57) i++;  
  }
  return i;
}


int nalpha_str_cnt(char * s)
{
     int i;
  for(; *s != '\0'; ++s) {
  	if (*s>= 48 && *s <=57 || *s>= 65 && *s <=90 || *s>= 97 && *s <=127) i++;  
  }
  return i;
}


int chr_str_cnt(char c, char * s)
{
	int i;
    for(; *s != '\0'; ++s) {
  	if (*s == c ) i++;  
  	}
  return i;
}


char * chr_str_pos(char c, char * s)
{
	for(; *s != '\0'; s++) {
  	if (*s == c )  {
 		return  s;
	  } 
  	} 		
}


char * chr_str_rpos(char c, char *s)
{	
	int j=0,i;
	for(; *s != '\0'; s++) i++; 
  		do{
  			if(*s == c) {
  				return s;
			  }
			  s--;
			j++; 
		  }while(i > j);	  			
}


char * str_rev(char * s)
{		
		int i;
		for(; *s != '\0'; ++s) i++;
		char tmp[i];
		s-=i+1;
			for(int j = 0; i >= j;j++){
				tmp[j] = *s;
				s++;	
			}
			s-=i;		
			for(int x = 0; i > x; x++){
				*s = tmp[i - x];
				s++;			
			}
			s-=i; 
  return s;
}


int str_word_count(char * s)
{
   int words;
   for(; *s != '\0'; ++s){
   		if(*s == ' ' || *s == 9){
   			--s;
   		   		if (*s>= 48 && *s <=57 || *s>= 65 && *s <=90 || *s>= 97 && *s <=127 || *s == 95){
   		   			  words++;
					}
			s+=2;
		   }	
   }
   
   if(words == 0 ) words--;
   return words+1;
}

int main()
{
  char line[MAX_LEN];
  char c;
  char * pos;

  cout << "\n\nWpisz linie tekstu: ";
  cin.getline(line, MAX_LEN-1);

  cout << "\nLiczba znakow         : " << str_len(line);
  cout << "\nLiczba malych liter   : " << lwr_str_cnt(line);
  cout << "\nLiczba duzych liter   : " << upr_str_cnt(line);
  cout << "\nLiczba cyfr           : " << dgt_str_cnt(line);
  cout << "\nLiczba alfanumerycznych: " << nalpha_str_cnt(line);

  cout << "\n\nPodaj pojedynczy znak: ";
  cin >> c;

  cout << "\nLiczba wystapien znaku " << c << ": " << chr_str_cnt(c, line);

  if((pos = chr_str_pos(c, line)) != 0)
    cout << "\nPierwsze wystapienie znaku " << *pos << " na pozycji: " << pos - line + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  if((pos = chr_str_rpos(c, line)) != 0)
    cout << "\nOstatnie wystapienie znaku " << *pos  << " na pozycji: " << pos - line + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  cout << "\n\nNapis oryginalny : " << line;
  cout << "\nNapis odwrocony  : " << str_rev(line);
  cout << "\nLiczba slow w napisie: " << str_word_count(line);
  cin.ignore();
  cin.get();
  return EXIT_SUCCESS;
}
