#include <iostream>
#include <algorithm>
#include <utility>
#define x first
#define y second
#define INF 100000000
using namespace std;

int ile;

typedef pair<int,int> PKT;

PKT tab1[100000];
PKT tab2[100000];

long long odl(PKT a, PKT b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

long long paranajbpkt(int p, int k){
    if(p==k){
        return INF;
    }
    if(k-p==1){
        return odl( tab1[p], tab1[k] );
    }
    int sr=(p+k)/2;
    int licz=1;
    long long dl=paranajbpkt(p,sr-1);
    long long dp=paranajbpkt(sr,k);
    long long dlugosc=min(dl,dp);
    
    for(int i=p;i<=k;i++){
        if(abs(tab1[i].x-tab1[sr].x)<=dlugosc){
            tab2[licz]=make_pair(-tab1[i].y,tab1[i].x);
            licz++;
        }
    }
    sort(tab2+1,tab2+licz+1);
    for(int i=1;i<licz;i++){
        for(int j=i+1;j<min(7,licz-1);j++){
            dlugosc=min(dlugosc,odl(tab2[i],tab2[j]));
        }
    }
    return dlugosc;
}

int main(){
    cin>>ile;
    for(int i=1;i<ile+1;i++){
        cin>>tab1[i].x>>tab1[i].y;
    }
    sort(tab1+1,tab1+ile+1);
    cout<<paranajbpkt(1,ile);
    return 0;
}
