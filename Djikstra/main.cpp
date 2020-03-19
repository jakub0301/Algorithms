#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>


using namespace std;
const int INF = 2400000;
priority_queue < pair < int, int > > q;
int visited[1000000];
int value[1000000];
vector < pair <int,int> > edge[1000000];
int vertex,edges;
int a, b, c;

void djikstra(){
    pair<int,int> x;
    pair<int,int>toq;
    q.push(make_pair(0, 0));
    while(q.size()){//im in x.second vertex
        x = q.top();
        x.first =- x.first;
        //cout << x.first << " " << x.second << "\n";
        q.pop();
        if(visited[x.second] != 0){
            //cout << x.second << " visited\n";
            //visited
            continue;
        }
        visited[x.second] = 1;
        //cout << "val " << x.second << " min" << x.first << " " << value[x.second] << "\n";
        value[x.second] = min(x.first, value[x.second]);
        for(int i = 0; i < edge[x.second].size(); i++){
            toq.first = (-value[x.second] - edge[x.second][i].first);
            toq.second = edge[x.second][i].second;
            q.push(toq);
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> vertex >> edges;
    for(int i = 0; i < vertex; i++){
        value[i] = INF;
    }
    for(int i = 0; i < edges; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        //edge number 'a' is connected with 'b' and edge value is c
        edge[a].push_back(make_pair(c, b));
        edge[b].push_back(make_pair(c, a));
    }
    
    djikstra();
    cout << "\n\n";
    
    
    for(int i = 0; i < vertex; i++){
        cout << value[i] << " ";
    }
    return 0;
}
