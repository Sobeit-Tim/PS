#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

string s;

int palin[2501][2501] = {0, };
int dp[2501] = {0, };


// 문자의 길이가 1인 경우 palin drome
// 이미 값이 있는 경우 return
// s[i] == s[j] 인 경우,   문자열 2개 줄여서 palin 체크
int isPalin(int i, int j){

    if(j-i <= 0)
        return 1;
    
    if(i+1 == j) return s[i] == s[j];

    int &ret = palin[i][j];
    
    if(ret != -1)
        return ret;

    if(s[i] == s[j])
        return ret = isPalin(i+1, j-1);

    return 0;
}


int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(palin, -1, sizeof(palin));

    cin >> s;

    // i까지 분할 했을 때, 최소 분할 수
    // 0일 때는 1
    // 1이상일 때는,    0, i가 palindrome이면 1,    아니라면 1+dp[i-1] 이거나,   j~i 사이에 palin이 있다면. dp[j-1]+1;
    dp[0] = 1;
    for(int i=1; i<s.size(); i++){
        if(isPalin(0, i) == 1){
            dp[i] = 1;
        }else{
            dp[i] = dp[i-1] + 1;
            for(int j=1; j<i; j++){
                if(isPalin(j, i) == 1) 
                    dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
    }

    cout << dp[s.size()-1];

    return 0;
}