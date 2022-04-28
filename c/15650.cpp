#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr[9] = {0, };
int visit[9] = {0, };

void solve(int len, int num){
    if(num > 8)
        return;
    if(len == M){
        for(int i = 0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = num+1; i<=N; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            arr[len] = i;
            solve(len+1, i);
            visit[i] = 0;
        }
    }

    return;
}

int main(){

    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    solve(0, 0);

    return 0;
}