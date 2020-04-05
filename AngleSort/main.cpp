#include <iostream>
#include <utility>
#include <cmath>

#define LL (long long)
#define Det(b,c) (LL(b.x-0)*(c.y-0)-(b.y-0)*(c.x-0))

using namespace std;

struct punkt{
	int x;
	int y;
};
punkt pkt[10000];
int ile;

bool comperator(const punkt& a, const punkt& b){
    if(a.y == 0 && a.x < 0){
        if(b.y == 0 && b.x < 0){
            return a.x < b.x;
        }
        else{
            return 1;
        }
    }
    
    else if(a.y >= 0 && b.y  >= 0 || a.y < 0 && b.y < 0){
        return Det(a,b) < 0;
    }
    else{
        return a.y > b.y;
    }
    
    
}
//For numbers < 10^6 will not work when numbers are ~10^9 because of double precision loss
bool comperatorForSmallNumbers(const punkt& a, const punkt& b){
    return atan2(a.y, a.x) > atan2(b.y, b.x);
    
}




int main(){
	
    cin >> ile;
	for(int i = 0; i < ile; i++){
		cin >> pkt[i].x >> pkt[i].y;
	}
    
	sort(pkt, pkt + ile, comperator);
	cout << "\n\n";
    
	for(int i = 0; i < ile; i++){
		cout << pkt[i].x << " " << pkt[i].y << "\n";
	}
    
	return 0;
}

