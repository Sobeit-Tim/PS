#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

int N, M, K;

int arr[501][501] = {0, };
int visit[501][501] = {0, };

int save[501][501] = {0, };

int dfs(int r, int c){
    int res = arr[r][c];
    if(r == N){
        return res;
    }

    if(visit[r][c] != 0){
        return res + visit[r][c];
    }

    visit[r][c] = max(dfs(r+1, c), dfs(r+1, c+1));
    res = res + visit[r][c];

    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs(0, 0);

    return 0;
}