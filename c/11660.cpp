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

int arr[1025][1025] = {0, };

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= N-1; j++){
            arr[i][j+1] += arr[i][j];
        }
    }

    for(int i = 1; i<=N-1; i++){
        for(int j = 1; j <= N; j++){
            arr[i+1][j] += arr[i][j];
        }
    }
    int x1,x2,y1,y2;
    for(int i=0; i<M; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1]);
    }

    return 0;
}