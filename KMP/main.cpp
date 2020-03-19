#include <iostream>

using namespace std;

string pattern;
string sought;
string str;

int result;
int p[1000000];
int temp;

void kmp(){
    for(int i = 1; i < str.size(); i++){
        temp = p[i - 1];
        while(temp - 1 >= 0 && str[temp] != str[i]){
            temp = p[temp - 1];
        }
        if(str[temp] == str[i]){
            p[i] = temp + 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> sought >> pattern;
    str = sought + "$" + pattern;
    kmp();
    for(int i = 0; i < str.size(); i++){
        cout << p[i];
    }
    cout << endl << str << endl;
    for(int i = sought.size(); i < str.size(); i++){
        if(p[i] == sought.size()){
            result++;
        }
    }
    cout << result;
    return 0;
}
