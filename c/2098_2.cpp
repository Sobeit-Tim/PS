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

int w[17][17] = {0, };

// i지점 상황에서,   j의 경로로 이동한 경우의 값.
int bitmask[16][1 << 16] = {0, };

int solve(int now, int route){
    
    int &ret = bitmask[now][route];
    // 이미 갱신이 된 경우라면
    if(ret)
        return ret;

    if(route == (1<<N) - 1){
        if(w[now][0] == 0)
            return INF;
        
        return w[now][0];
    }

    // 마지막 경우는 갱신하지 않기 위해서, 이렇게 두면 됨 ㅇㅇ..  위에 두면 마지막 경우가 갱신되서, 다시는 도달하지 못함 마지막 경우를.
    ret = 987654321;
    for(int i=0; i<N; i++){
        int newRoute = route | (1 << i);
        // 이미 경로 포함
        if(route & (1 << i))
            continue;
        
        // 경로 있는 경우
        if(w[now][i] != 0)
            ret = min(ret, w[now][i] + solve(i, newRoute));
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
        for(int j=0; j<N; j++)
            cin >> w[i][j];
    }

    cout << solve(0, 1);

    return 0;
}