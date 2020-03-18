#pragma GCC optimize ("03")

#include <iostream>
#include <algorithm>

using namespace std;


struct person {
    int age;
    int height;
};

person tab[100];
int n;

bool comp(const person& a,const person& b)
{
    //Operator trojskladnikowy
    return (a.height == b.height ? a.age < b.age : a.height < b.height);
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tab[i].age >> tab[i].height;
    }
    sort(tab, tab + n, comp);
    
    return 0;
}
