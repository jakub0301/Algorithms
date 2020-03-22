#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int len, capacity, questions;
int seats, l, r, value;

const int NAX = 500000;

pair<int,int> tree[NAX];
int treeLeft[NAX];
int treeRight[NAX];

int check(int targetL, int targetR){
    int addL = 0;
    int addR = 0;
    int maX = -1;
    int actL = 0;
    int actR = 0;
    int l = 1, r = 1;
    while(l < targetL){
        addL += tree[l].first;
        addR += tree[r].first;
        if(treeLeft[l * 2 + 1] > treeLeft[targetL]){
            //go left
            l *= 2;
            actL = 1;
            
        }
        else{
            actL = 0;
            l = l * 2 + 1;
        }
        
        if(treeRight[r * 2] >= treeRight[targetR]){
            r *= 2;
            actR = 0;
        }
        else{
            r = r * 2 + 1;
            actR = 1;
            
        }
        if(l != r && l + 1 != r){
            if(actL){
                maX = max(maX, tree[l + 1].first + tree[l + 1].second + addL);//not right & not the same
            }
            if(actR){
                maX = max(maX, tree[r - 1].first + tree[r - 1].second + addR);
            }
                
        }
    }
    maX = max(maX, tree[l].first + tree[l].second + addL);
    maX = max(maX, tree[r].first + tree[r].second + addR);
    
    return maX;
    
}
void add(int l, int r, int value){
    int lact = 1;
    int ract = 1;
    
    while(l != r){
        //left
        if(l % 2 == 0){
            if(lact == 0 && l + 1 != r){
                tree[l + 1].first += value;
            }
        }
        if(l % 2 == 1){
            if(lact == 1){
                tree[l].first += value;
            }
            lact = 0;
        }
        
        //right
        if(r % 2 == 0){
            if(ract == 1){
                tree[r].first += value;
            }
            ract = 0;
        }
        if(r % 2 == 1){
            if(ract == 0 && r - 1 != l){
                tree[r - 1].first += value;
            }
        }
        
        l /= 2;
        r /= 2;
    }
    
    if(lact == ract && ract == 1){
        lact = 0;
        ract = 0;
        tree[l].first += value;
    }
    
    if(lact == 1){
        tree[l * 2].first += value;
    }
    if(ract == 1){
        tree[r * 2 + 1].first += value;
        
    }
}
void update(int l, int r){
    while(l != 1){
        //first value on a segment
        //second max from childerns
        l /= 2;
        r /= 2;
        tree[l].second = max(tree[l * 2].first + tree[l * 2].second, tree[l * 2 + 1].first + tree[l * 2 + 1].second);
        tree[r].second = max(tree[r * 2].first + tree[r * 2].second, tree[r * 2 + 1].first + tree[r * 2 + 1].second);
    }
}

int main(){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> len >> capacity >> questions;
    int beg = 1;
    while(beg < len){
        beg *= 2;
    }
    for(int i = 0; i < beg; i++){
        treeLeft[beg + i] = beg + i;
        treeRight[beg + i] = beg + i;
    }
    for(int i = beg - 1; i > 0; i--){
        treeLeft[i] = treeLeft[i * 2];
        treeRight[i] = treeRight[i * 2 + 1];
    }

    //beg first indx of the tree
    for(int i = 0; i < questions; i++){
        cin >> l >> r >> seats;
        r--;
        
        
        
        if(check(l + beg - 1, r + beg - 1) + seats <= capacity){
            cout << "T\n";
            add(l + beg - 1, r + beg - 1, seats);
            update(l + beg - 1, r + beg - 1);
        }
        else{
            cout << "N\n";
        }
        
    }
    
    /*
    cout << "\n\n";
     //Print tree
    for(int i = 1; i < 2 * beg; i++){
        cout << i << " (" << tree[i].first  << "," << tree[i].second << ")\n";
    }
     */
    return 0;
}

