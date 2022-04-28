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
        if(visit[i] == 0){
            visit[i] = 1;
            arr[len] = i;
            solve(len+1);
            visit[i] = 0;
        }
    }

    return;
}

bool comp(char a, char b){
    return a > b;
}

int main(){

    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);

    solve(0);

    return 0;
}