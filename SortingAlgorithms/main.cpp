
#include <iostream>

using namespace std;

int tab[1000000];
int pom[1000000];
int ile;
int n;

void sorowanie_wstawianie(){
    int pom, j;
    for(int i = 1; i < n; i++){
            //wstawienie elementu w odpowiednie miejsce
            pom = tab[i]; //ten element będzie wstawiony w odpowiednie miejsce
            j = i - 1;
            
            //przesuwanie elementów większych od pom
            while(j >= 0 && tab[j] > pom){
                tab[j + 1] = tab[j]; //przesuwanie elementów
                j--;
            }
            tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
    }
}

void sortowanie_wybor(){
    for(int i = 0; i < n - 1; i++){
      int min = i;
      for(int j = i + 1; j < n; j++){
        if(tab[j] < tab[min]){
          min = j;
        }
      }
      int t = tab[i];
      tab[i] = tab[min];
      tab[min] = t;
    }
}


void sortowanie_babelkowe(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(tab[j] < tab[i]){
                int temp = tab[j];
                tab[j] = tab[i];
                tab[i] = temp;
            }
            
        }
    }
}

void quick_sort(int lewy, int prawy){
    if(prawy <= lewy) return;
    
    int i = lewy - 1, j = prawy + 1, pivot = tab[(lewy + prawy) / 2]; //wybieramy punkt odniesienia
    
    while(true){
        //szukam elementu wiekszego lub rownego piwot stojacego
        //po prawej stronie wartosci pivot
        while(pivot > tab[i++]);
        //szukam elementu mniejszego lub rownego pivot stojacego
        //po lewej stronie wartosci pivot
        while(pivot<tab[j--]);
        
        //jesli liczniki sie nie minely to zamień elementy ze soba
        //stojace po niewlasciwej stronie elementu pivot
        if( i <= j){
            //funkcja swap zamienia wartosciami tab[i] z tab[j]
            int temp = tab[j];
            tab[j] = tab[i];
            tab[i] = tab[j];
        }
        else
            break;
    }

    if(j > lewy)
        quick_sort(lewy, j);
    if(i < prawy)
        quick_sort(i, prawy);
}
void sortowanie_szybkie(){
    quick_sort(0, n - 1);
}


void scal(int tab[], int lewy, int srodek, int prawy)
{
  int i, j;
 
  //zapisujemy lewą częsć podtablicy w tablicy pomocniczej
  for(i = srodek + 1; i > lewy; i--)
    pom[i - 1] = tab[i - 1];
 
  //zapisujemy prawą częsć podtablicy w tablicy pomocniczej
  for(j = srodek; j < prawy; j++)
    pom[prawy + srodek - j] = tab[j + 1];
 
  //scalenie dwóch podtablic pomocniczych i zapisanie ich
  //we własciwej tablicy
  for(int k = lewy; k <= prawy; k++)
    if(pom[j] < pom[i])
      tab[k] = pom[j--];
    else
      tab[k] = pom[i++];
}
 

void sortowanie_przez_scalanie(int tab[],int lewy, int prawy)
{
    //gdy mamy jeden element, to jest on już posortowany
    if(prawy <= lewy) return;
    
    //znajdujemy srodek podtablicy
    int srodek = (prawy + lewy) / 2;
    
    //dzielimy tablice na częsć lewą i prawa
    sortowanie_przez_scalanie(tab, lewy, srodek);
    sortowanie_przez_scalanie(tab, srodek + 1, prawy);
    
    //scalamy dwie już posortowane tablice
    scal(tab, lewy, srodek, prawy);
}

void sortowanie_scalanie(){
    sortowanie_przez_scalanie(tab, 0, n - 1);
}


int main() {
    cin >> ile;
    
    for(int i = 0; i < ile; i++){
        cin >> tab[i];
    }
    n = ile;
    //sorowanie_wstawianie();

    //sortowanie_wybor();

    //sortowanie_babelkowe();

    //sortowanie_szybkie();

    //sortowanie_scalanie();
    
    
    for(int i = 0; i < ile; i++){
        cout << tab[i] << " ";
    }
    
    return 0;
}
