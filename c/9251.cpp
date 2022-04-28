#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,K;

int dp[1001][1001] = {0, };


int main(){
    freopen("input.txt", "r", stdin);
    string a,b;
    cin >> a >> b;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++ ){ 
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.size()][b.size()];

    return 0;
}