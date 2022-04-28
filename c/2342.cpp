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

int dp[100001][5][5];

int N;


int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = -1;
    vector<int> v;
    while(true){
        cin >> num;
        if(num == 0)
            break;
        v.push_back(num);
    }

    N = v.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                dp[i][j][k] = 5000000;
    }

    int s = v[0];
    dp[0][s][0] = 2;
    dp[0][0][s] = 2;

    for(int i=1;i <N; i++){
        s = v[i];
        for(int j=0; j<5; j++){
            if(j==s)
                continue;
            for(int k=0; k<5; k++){
                int val = 0;
                int diff = abs(k-s);
                if(k==0)
                    val = 2;
                else if(diff == 0)
                    val = 1;
                else if(diff == 1 || diff == 3)
                    val = 3;
                else
                    val = 4;
                dp[i][j][s] = min(dp[i][j][s], dp[i-1][j][k] + val);
                dp[i][s][j] = min(dp[i][s][j], dp[i-1][k][j] + val);
            }
        }
    }

    int e = v[N-1];
    int res = 5000000;
    for(int i=0; i<5; i++){
        res = min(res, dp[N-1][i][e]);
        res = min(res, dp[N-1][e][i]);
        // cout << dp[N-1][i][e] << " " << dp[N-1][e][i] << endl; 
    }

    // for(int i=0; i<N; i++){
    //     cout << "N " << i << endl;
    //     for(int j=0; j<5; j++){
    //         for(int k=0; k<5; k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout <<endl;

    //     }
    // }

    cout << res;

    return 0;
}