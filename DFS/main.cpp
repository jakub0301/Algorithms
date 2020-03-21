#include <iostream>
#include <vector>

using namespace std;

int krawedzi, wierzcholkow, a, b;

vector<int> tab[1000000];
int odw[1000000];
int czas = 1;

void DFS(int v){
    odw[v] = czas;
    for(int i = 0; i < tab[v].size(); i++){
        if(odw[tab[v][i]] == 0){
            DFS(tab[v][i]);
        }
    }
}

int main(){
    cin >> wierzcholkow >> krawedzi;
    for(int i = 0; i < krawedzi; i++){
        cin >> a >> b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    cout << "\n\n";

    for(int i = 1; i <= wierzcholkow; i++){
        if(odw[i] == 0){
            DFS(i);
            czas++;
        }
    }
    czas--;
       
    cout << czas;


}
