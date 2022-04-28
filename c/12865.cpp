#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[50];
int N,M,K;
vector<int> w, v;

int dp[101][100001];

int solve(int r, int c){
    
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    v.push_back(0);
    w.push_back(0);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }

    for(int i = 0; i < 100001; i++)
        dp[0][i] = 0;
    
    for(int i = 0; i < 101; i++)
        dp[i][0] = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(w[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }

        }
    }

    cout << dp[N][K];

    return 0;
}