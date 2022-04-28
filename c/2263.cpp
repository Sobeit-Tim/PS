#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int in[100001] = {0, };
int post[100001] = {0, };

void solve(int is, int ie, int ps, int pe){
    
    if(ie-is < 0 || pe - ps < 0)
        return;
    cout << post[pe] << " ";
    int pos;
    for(int i = is; i<=ie; i++){
        if(in[i] == post[pe]){
            pos = i;
            break;
        }
    }
    int len = pos-is;
    solve(is, pos-1, ps, ps+len-1);
    solve(pos+1, ie, ps+len, pe-1);
    
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> in[i];
    }

    for(int i=0; i<n; i++){
        cin >> post[i];
    }

    solve(0, n-1, 0, n-1);
    return 0;
}