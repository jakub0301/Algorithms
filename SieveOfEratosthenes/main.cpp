#include <iostream>

using namespace std;
int prime[100000000];
unsigned int num, to;
int main(){
	prime[0] = 1;
	prime[1] = 1;
    //False 1
    //True 0
    to = 1000000; //from 0 to 'to' prime numbers
	for(int i = 2; i * i <= to; i++){
		if(prime[i] == 0){
			for(int j = i * i; j <= to; j += i){
				prime[j] = 1;
			}
		}
	}
	cin >> num;
    if(prime[num] == 0){
        cout << "Prime";
    }
    else{
        cout << "NOPE";
    }
	return 0;
}
