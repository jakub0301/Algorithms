#include <iostream>
#define LL (long long)
#define Det(a,b,c) (LL(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))
using namespace std;

int tab[4][4];
struct point {
    int x;
    int y;
    
};
point a;
point b;
point c;
int main(){
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    int det = Det(a, b, c);
    cout << Det(a, b, c);
	if(det == 0){
	cout << "Collinear";
	}
	else if(det > 0){
		cout << "Left";
	}
	else {
		cout << "Right";
	}
	return 0;
}
