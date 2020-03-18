#include <iostream>

using namespace std;

int getInt(){
    int value = 0;
    char ch;
    do{
        ch = getchar_unlocked();
    }while(ch < '0' || '9' < ch);
    
	do{
        value = value * 10 + ch - '0';
        ch = getchar_unlocked();
    }while(ch >= '0' && '9' >= ch);
    return value;
}

int main() {
    int n = getInt();
    cout << n;
    return 0;
}
