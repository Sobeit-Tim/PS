#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <memory.h>

#define INF 987654321

using namespace std;

int arr[9][9];
string s;
bool flag = false;

void print(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++)
            cout << arr[i][j];
        cout << endl;
    }
}

int check(int r, int c, int val){
    for(int i=0; i<9; i++){
        if(arr[r][i] == val || arr[i][c] == val)
            return 1;
    }

    int sr = (r/3)*3;
    int sc = (c/3)*3;
    for(int i=sr; i<sr+3; i++){
        for(int j=sc; j<sc+3; j++){
            if(arr[i][j] == val)
                return 1;
        }
    }

    return 0;
}

void solve(int r, int c){
    int nc = c+1;
    int nr = r;
    if(nc >= 9){
        nr++;
        nc = 0;
    }
    
    if(r == 9 && c == 0){
        print();
        flag = true;
        return;
    }

    if(arr[r][c] != 0){
        solve(nr, nc);
        return;
    }
    
    for(int i=1; i<=9; i++){
        if(check(r, c, i) == 0){
            arr[r][c] = i;
            solve(nr, nc);
            arr[r][c] = 0;
            if(flag)
                return;
        }
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 9;
    for(int i=0; i<9; i++){
        cin >> s;
        for(int j = 0; j < 9; j++){
            arr[i][j] = s[j] - '0';
        }        
    }

    solve(0, 0);

    return 0;
}