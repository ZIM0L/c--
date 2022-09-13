#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>


using namespace std;
const int MAX = 100;
 
void program (char s,string nazwa_1,string nazwa_2,int k); 

int ilosc_znakowPliku(fstream &file) 
{
	string text;
    	while(getline(file, text)){
      }	
    return text.length();  
 	
} 

void szyfrowanie(fstream &file, ofstream &file2, int k, int letters ) 
{
	string text;
	char tab[letters];
		file.clear();
    	file.seekg(0);
        getline(file, text)
		;
    	for(int i = 0; i < letters; ++i)  tab[i] = text[i] ^ k ;  
    	for(int i = 0; i < letters; ++i)  cout << tab[i];   
    	file.close();
    
    	for(int i = 0; i < letters; ++i)  file2 << tab[i]; 
} 

int main()
{
  string nazwa_1, nazwa_2;
  char s;
  int k;
	cin >>  s;
		cin >>  nazwa_1;
		cin >>  nazwa_2;
	cin >>  k;
	program(s, nazwa_1,nazwa_2 ,k);

  return 0;
}

void program (char s,string nazwa_1,string nazwa_2, int k){
	fstream file;
	ofstream file2;
	file.open(nazwa_1.c_str());	
	if(file.good()) {
		file2.open(nazwa_2.c_str());
		int letters = ilosc_znakowPliku(file);
		char tab_1[letters];
	 	switch(s){
	 		case 's':
	 			szyfrowanie(file,file2,k, letters);
	        break;	 
			case 'd':
				szyfrowanie(file,file2,k, letters);
				break;
			default:
				cout << "zle podane szyfrowanie";
	        break; 
	 		
		 
	   }
	} else {
		cout << "Brak pliku o tej nazwie";
	}
}


 


