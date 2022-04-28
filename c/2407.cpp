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

int num[128];
string dp[101][101] = {}; 

string add(string a, string b){
    string c = "";
    int n1, n2, sum = 0;
    while(!a.empty() || !b.empty() || sum){
        if(!a.empty()){
            n1 = a.back() - '0';
            sum += n1;
            a.pop_back();
        }
        
        if(!b.empty()){
            n1 = b.back() - '0';
            sum += n1;
            b.pop_back();
        }

        c.push_back((sum%10) + '0');
        sum /= 10;

    }
    reverse(c.begin(), c.end());
    return c;
}

string solve(int n, int k){
    if(n == k || k == 0)
        return dp[n][k] = "1";

    if(dp[n][k] != "")
        return dp[n][k];

    return dp[n][k] = add(solve(n-1, k-1), solve(n-1, k));
    
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;

    long long answer = 1;
    
    // nCk = n-1Ck-1 + n-1Ck

    cout << solve(N, M);

    return 0;
}