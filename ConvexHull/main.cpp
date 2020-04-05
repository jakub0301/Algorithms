#include <iostream>
#include <cmath>
#include <utility>
#include <queue>

#define LL (long long)
#define Det(a,b,c) (LL(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))

#define Det2(b,c) (LL(b.x-0)*(c.y-0)-(b.y-0)*(c.x-0))
using namespace std;

const long long INF = 1000000000;

struct point{
    long long x;
    long long y;
    long long nr;

};

point fpoint;


bool comperator(const point& a, const point& b){
    if(a.y == 0 && a.x < 0){
        if(b.y == 0 && b.x < 0){
            return a.x < b.x;
        }
        else{
            return 1;
        }
    }
    
    else if((a.y >= 0 && b.y  >= 0 )|| (a.y < 0 && b.y < 0)){
        return Det2(a,b) < 0;
    }
    else{
        
        return a.y > b.y;
    }
    
    
}

vector <point> otoczka;
int ile;
point pkt[30000];


int main(){
    
    fpoint.x = INF;
    fpoint.y = INF;
    cin >> ile;
    for(int i = 0; i < ile; i++){
        cin >> pkt[i].x >> pkt[i].y;
        pkt[i].nr = i;
        if(fpoint.x > pkt[i].x){
            fpoint.x = pkt[i].x;
            fpoint.y = pkt[i].y;
        }
    }
    
    sort(pkt, pkt + ile, comperator);
    
    
    pkt[ile] = pkt[0];
    ile++;
    
    otoczka.push_back(pkt[0]);
    otoczka.push_back(pkt[1]);
    for(int i = 2; i < ile; i++){
        while(Det(otoczka[otoczka.size() - 2], pkt[i], otoczka[otoczka.size() - 1]) < 0){
            otoczka.pop_back();
        }
        otoczka.push_back(pkt[i]);
    }
    
    cout << "\n\nOtoczka\n";
    
    for(int i = 0; i < otoczka.size(); i++){
        cout << otoczka[i].x + fpoint.x << " " << otoczka[i].y + fpoint.y << "\n";
    }
    
    
    return 0;
}
