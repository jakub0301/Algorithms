#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

string str;
vector <int> kmr[1000000];
int n;

int main(){
    
    cin >> str;
    n = int(str.size());
    for(int i = 0; i < n; i++){
        kmr[0].push_back(str[i]);
    }
    
    
    int level = 0;
    while(kmr[level].size() != 1){
        vector < pair<int,int> > pair;
        for(int i = 0; i < kmr[level].size() - 1; i++){
            pair.push_back(make_pair(kmr[level][i], kmr[level][i + 1]));
        }
        
        sort(pair.begin(), pair.end() );
        map<pair<int, int>, int> map;
        
        for(int i = 0; i < kmr[level].size() - 1; i++){
            map.insert(make_pair(pair[i], i));
        }
        for(int i = 0; i < kmr[level].size() - 1; i++){
            //find id from map to element and push on higher level
            kmr[level + 1].push_back(map.find(make_pair(kmr[level][i], kmr[level][i + 1]))->second);
        }
        level++;
        
    }
    
    
    cout << "Read questions:";
    
    int id1, len, id2, powe = 0;
    cin >> id1 >> len >> id2;
    while(len / 2 > 1){
        len /= 2;
        powe++;
    }
    
    id1--;
    id2--;
    if(kmr[powe][id1] == kmr[powe][id2]){
        int przes = len - pow(2, powe);
        if(kmr[powe][id1 + przes] == kmr[powe][id2 + przes]){
            cout << "Tak\n";
        }
        else{
            cout << "Nie\n";
        }
    }
    else{
        cout << "Nie\n";
    }
    
    return 0;
}
