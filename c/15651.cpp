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

void solve(int len){
    if(len == M){
        for(int i = 0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i<=N; i++){
        arr[len] = i;
        solve(len+1);
    }

    return;
}

int main(){

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    solve(0);

    return 0;
}