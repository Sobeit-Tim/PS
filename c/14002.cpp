#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

typedef vector<vector<int> >matrix;

int N;
int dp[1001] = {0, };

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // dp로 해결
    cin >> N;
    vector<int> v;
    while(N--){
        int num;
        cin >> num;
        v.push_back(num);
    }

    // dp[0] = 1;
    // dp[i] = max(dp[i], dp[j] +1)   (v[j] < v[i] && 0 <= j < i) 
    int ans = 1;
    dp[0] = 1;
    for(int i=1; i<v.size(); i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        // cout << i << " " << dp[i] << endl;
        ans = max(ans, dp[i]); 
    }

    // LIS 길이
    cout << ans << endl;

    vector<int>answer_lis;
    int cnt = ans;
    for(int i=v.size()-1; i>=0; i--){
        if(dp[i] == ans){
            ans--;
            answer_lis.push_back(v[i]);
        }
    }

    reverse(answer_lis.begin(), answer_lis.end());

    for(int i=0; i<answer_lis.size(); i++)
        cout << answer_lis[i] << " ";
    return 0;
}