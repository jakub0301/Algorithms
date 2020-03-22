#include <iostream>
#include <vector>

using namespace std;

int vertex, edge, a, b;

vector<int> tab[1000000];
int vis[1000000];

int main(){
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        cin >> a >> b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    
    cout<<"\n\n";
    
    vector <int> q;
    int start = 1;//beg from 1
    q.push_back(start);
    vis[start] = 1;
    for(int i = 0; i < q.size(); i++){
        int w = q[i];
        for(int j = 0; j < tab[w].size(); j++){
            if(!vis[t[w][j]]){
                q.push_back(tab[w][j]);
                vis[tab[w][j]] = 1;
            }
        }
    }
}
