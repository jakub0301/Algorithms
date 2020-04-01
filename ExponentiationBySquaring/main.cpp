#include <iostream>

using namespace std;

const unsigned long long MOD = 10000007;
unsigned long long a, b;


unsigned long long pot(unsigned long long base, unsigned long long power){
    
    unsigned long long score = 1;
    
    while(power){
        if(power % 2 == 1){
            score = (score * base) % MOD;
        }
        base = base * base % MOD;
        power /= 2;
    }
    return score;
}

int main(){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << (pot(a, b)) % MOD << "\n";
    }
    
    return 0;
}

