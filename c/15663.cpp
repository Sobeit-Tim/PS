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

int arr[9];

int res[9];
int visit[9] = {0,};

void solve(int cnt, int num){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }
    int last = -1;
    for(int i = 0; i < N; i++){
        if(arr[i] == last)
            continue;
        if(visit[i] == 0){
            visit[i] = 1;
            last = arr[i];
            res[cnt] = arr[i];
            solve(cnt+1, i);
            visit[i] = 0; 
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for(int i = 0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N);
    solve(0, 0);

    return 0;
}