#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int dp[10001][101] = {0,};
vector<int>cost, memory;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memory.push_back(0);
    cost.push_back(0);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        memory.push_back(num);
    }
    
    int sum = 0;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        cost.push_back(num);
        sum += num;
    }
    bool flag = false;
    for(int i=0; i<=sum; i++){
        if(flag)
            break;
        for(int j=1; j<=n; j++){
            if(cost[j] <= i){
                dp[i][j] = max(memory[j] + dp[i-cost[j]][j-1], dp[i][j-1]);
                // cout << i << " " << j << " " << dp[i][j] << endl;
                if(dp[i][j] >= m){
                    cout << i;
                    flag = true;
                    break;
                }
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return 0;
}