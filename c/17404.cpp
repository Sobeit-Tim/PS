#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,x=0;
int arr[1001][3] = {0, };
int cost[1001][3] = {0, };
int answer = INF;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    cost[0][0] = arr[0][0];
    cost[0][1] = cost[0][2] = INF;
    for(int i=1; i<n; i++){
        cost[i][0] = arr[i][0] + min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] = arr[i][1] + min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] = arr[i][2] + min(cost[i-1][0], cost[i-1][1]);
    }
    
    answer = min(answer, min(cost[n-1][1], cost[n-1][2]));

    
    cost[0][1] = arr[0][1];
    cost[0][0] = cost[0][2] = INF;
    for(int i=1; i<n; i++){
        cost[i][0] = arr[i][0] + min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] = arr[i][1] + min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] = arr[i][2] + min(cost[i-1][0], cost[i-1][1]);
    }
    
    answer = min(answer, min(cost[n-1][0], cost[n-1][2]));

    
    cost[0][2] = arr[0][2];
    cost[0][0] = cost[0][1] = INF;
    for(int i=1; i<n; i++){
        cost[i][0] = arr[i][0] + min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] = arr[i][1] + min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] = arr[i][2] + min(cost[i-1][0], cost[i-1][1]);
    }
    
    answer = min(answer, min(cost[n-1][0], cost[n-1][1]));

    cout << answer;

    return 0;
}