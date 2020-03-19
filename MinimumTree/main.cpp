#include <iostream>
#include <algorithm>

using namespace std;

int tree[1000000];
int n, qu, count, power = 1;

void update(int node){
    while(node > 1){
        node /= 2;
        tree[node] = min(tree[node * 2], tree[(node * 2) + 1]);
    }
}

int main() {
    cin >> n >> qu;
    //poower of 2
    int copy = n;
    while(copy != 1){
        copy = copy >> 1;
        power = power << 1;
    }
    if(power < n) power = power << 1;
    
    for(int i = 0; i < power * 2; i++){
        tree[i] = 1000000000;
    }
    for(int i = 0; i < n; i++)
        cin >> tree[i + power];
    
    for(int i = 0; i < n; i += 2){
        update(i + power);
    }
    char ch;
    int x, y;
    for(int i = 0; i < qu; i++){
        cin >> ch;
        if(ch == '?') cout << tree[1] << "\n";
        else{
            cin >> x >> y;
            tree[x + power - 1] = y;
            update(x + power - 1);
        }
    }
    return 0;
}
