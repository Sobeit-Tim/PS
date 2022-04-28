#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int N;
int arr[501][2];

long long dp[501][501] = {0, };

// 3 일 때는,

// s 와 e 사
// f(i,j) = i~j 행렬 곱할 때 최소 연산
// f(i,j) = f(i, k) + f(k+1, j) + arr[i][0] * arr[k][1] * arr[j][1]
long long solve(int s, int e){
    
    if(e==s)
        return 0;

    long long &ret = dp[s][e];
    if(ret)
        return ret;


    if(e-s == 1){
        dp[s][e] = arr[s][0] * arr[s][1] * arr[e][1];
        return dp[s][e];
    }

    ret = (1<<31)-1;
    
    for(int k = s; k < e; k++){
        ret = min(ret, solve(s, k) + solve(k+1, e) + arr[s][0] * arr[k][1] * arr[e][1]);
    }
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    cout << solve(0, N-1);

    return 0;
}