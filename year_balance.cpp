#include <iostream>
#include <cstdlib>
#include <math.h>


using namespace std;

void obliczanie(int tab[],int max,int min,int j);
void dochod(int przychod[],int koszty[]);
void miesiace(int value,int tab[]);

int main(int argc, char *argv[]){

int przychod[12],koszty[12],i=0,przychody=0,koszt=0,min=0,max=0,j;

cout << "Program do rozliczania roczengo bilansu. Wpisywanie liczby po kolei liczb jest rownoznaczne z wpisywaniem przychodu, badz kosztow do nastepnych miesiacy, zaczynajac od Stycznia. Program nie przyjmuje wartosci ujemynych oraz innych znakow, oprocz cyfr. \n";

		cout << "Prosze wprowadzic przychody roczne\n"; //przychod
		do{
		cin >> przychod[i];
		
		if(cin.good()){
			if(przychod[i]>=0) i++;
			else cout << "Prosze podac wartosci nieujemne\n";		
		} else {
			cout << "zle dane\n";	
			cin.clear();
			cin.ignore();		
		}
		j=1;
		}while(i<12);
		i=0; 
		
		min=przychod[0];
		obliczanie(przychod,max,min,j);
		
		cout << "\nProsze wprowadzic koszty roczne\n"; //koszty
		do{
		cin >> koszty[i];
		
		if(cin.good()){
			if(koszty[i]>=0) i++;
			else cout << "Prosze podac wartosci nieujemne\n";		
		} else {
			cout << "zle dane\n";	
			cin.clear();
			cin.ignore();	
		}
		j=0;
		}while(i<12);

		min=koszty[0];
		max=0;
		obliczanie(koszty,max,min,j);
		
		dochod(przychod,koszty);
		cout << "------------------------------------------------\n";
		cout << "\nSuma twojego przychodu wynosi: ";
		for(int j=0;j<12;j++) przychody += przychod[j];
		cout << przychody;
		
		cout << "\nSuma twoich kosztow wynosi: ";
		for(int j=0;j<12;j++) koszt += koszty[j];
		cout << koszt;
			if(przychody - koszt >=0){
				cout << "\nTwoj roczny Dochod wynosi: " << przychody - koszt;
			}   else{
				cout << "\nTwoja roczna Strata wynosi : " << przychody - koszt;
				}
			
}

 			// bilans dla kolejnych miesiêcy: program wyœwietla cztery kolumny, w pierwszej wartoœæ przychodu, w drugiej wartoœæ kosztu, w trzeciej wartoœæ dochodu, w czwartej odpowiednio napisy „strata”, „zysk” lub „zero” w zale¿noœci od relacji pomiêdzy przychodem a kosztem. Ka¿dy wiersz zawiera dane z jednego miesi¹ca.
void obliczanie(int tab[],int max,int min,int j){ //wartosc j jest aby wybrac ktory tekst ma wybrac do wyswietlania podczas obliczania dla przychodow badz dla kosztow
	int i=0,miesiac=0,Srednia;
		do{
			if(tab[i]>max)max= tab[i];	
			if(tab[i]<min)min= tab[i];
			Srednia += tab[i];
			i++;
		}while(i<12);
		Srednia /=12;
			
		if(j == 1){	
		cout << "--------------------------------------------------\n";
		cout << "Minimalny przychod miesieczny w roku wynosi: " << min; cout << ", w miesiacach: "; miesiace(min,tab);
		cout << "\nMaksymalny przychod miesieczny w roku wynosi: " << max; cout << ", w miesiacach: "; miesiace(max,tab);
		cout << "\nSrednia przychodow miesiecznych w roku wynosi: " << Srednia;
		cout << "\n------------------------------------------------\n";
		} else if(j == 0){	
		cout << "--------------------------------------------------\n";
		cout << "Minimalny koszt miesieczny w roku wynosi: " << min; cout << ", w miesiacach: "; miesiace(min,tab);
		cout << "\nMaksymalny koszt miesieczny w roku wynosi: " << max;	cout << ", w miesiacach: "; miesiace(max,tab);
		cout << "\nSrednia kosztow miesiecznych w roku wynosi: " << Srednia;
		cout << "\n------------------------------------------------\n";
		}
	}
void dochod(int przychod[],int koszty[]){
	int i=0,dochod[12],min=0,max=0,dochody;
	dochod[0] = przychod[0]-koszty[0];
	min=dochod[0];
	do{
		dochod[i] = przychod[i]-koszty[i];	
			if(dochod[i]>max) max = dochod[i];
			if(dochod[i]<min) min = dochod[i];
			dochody += dochod[i];
		i++;		
	}while(i<12);
        cout << "--------------------------------------------------\n";
		cout << "Minimalny dochod miesieczny w roku wynosi: " << min; cout << ", w miesiacach: "; miesiace(min,dochod);
		cout << "\nMaksymalny dochod miesieczny w roku wynosi: " << max; cout << ", w miesiacach: "; miesiace(max,dochod);
		cout << "\nSrednia dochodow miesiecznych w roku wynosi: " << dochody/12;
		cout << "\n------------------------------------------------\n";
	
	cout << "\n_____________________________________________\n"; 
		printf("|%10s|%10s|%10s|%10s|\n","przychod","koszty","dochod","bilans");
	cout << "|__________|__________|__________|__________|\n"; //19
		 for(int i=0;i<12;i++){
		 //	cout << przychod[i] <<  " " << koszty[i] << " " << dochod[i] <<endl;
			printf("|%10d|%10d|%10d|",przychod[i],koszty[i],dochod[i]);
				if(dochod[i] == 0) {
					printf("%10s|\n","zero");	
				} else if (dochod[i] > 0){
						printf("%10s|\n","zysk");	
				} else if (dochod[i] < 0){
						printf("%10s|\n","strata");	
				}
		 }	
	cout << "|__________|__________|__________|__________|\n"; 
}

void miesiace(int value,int tab[]){	

 for(int i=0;i<12;i++){
 	if(tab[i] == value) {
		switch(i){
			case 0:
				cout << "Styczen ";
				break;	
			case 1:
				cout << "Luty ";
				break;	
			case 2:
				cout << "Maczec ";
				break;
			case 3:
				cout << "Kwiecien ";
				break;	
			case 4:
				cout << "Maj ";
				break;	
			case 5:
				cout << "Czerwiec ";
				break;	
			case 6:
				cout << "Lipiec ";
				break;
			case 7:
				cout << "Sierpien ";
				break;
			case 8:
				cout << "Wrzesien ";
				break;	
			case 9:
				cout << "Pazdziernik ";
				break;	
			case 10:
				cout << "Listopad ";
				break;	
			case 11:
				cout << "Grudzien ";
				break;
		    default : 
			cout << "";
			break;
		}
		}
	}
}

	
			

