#include <iostream>
#include <algorithm>

using namespace std;
int n, tab[200010];

//upperbound
int upperBound(int value){
    int beg = 0, end = n - 1, mid = end / 2;
    while(beg <= end){
        mid = (beg + end) / 2;
        if(tab[mid] <= value){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return beg;
}

//lowerbound
int lowerBound(int value){
    int beg = 0, end = n - 1, mid = end / 2;
    while(beg <= end){
        mid = (beg + end) / 2;
        if(tab[mid] < value){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return beg;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    cout << lowerBound(8) << " " << upperBound(8);
}
