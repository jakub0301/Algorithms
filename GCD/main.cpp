#include <iostream>

using namespace std;

int GCD (int a, int b) {
	int temp;
	while (b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;

}


int a, b;

int main(){
	cin >> a >> b;
	cout << GCD(a, b);
	return 0;
}
