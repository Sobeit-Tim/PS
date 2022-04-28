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

void tsp(int start, int now, int route){
    // cout << start << " " << now << " " << route << " " << bitmask[now][route] << endl;
    
    // 최종에 다 다르면 탐색 중지
    if(route == (1<<N) - 1){

        return;
    }

    int shift = 1;
    for(int i=0; i<N; i++){
        
        // 갈 수 없는 경우 스킵
        if(w[now][i] == 0)
            continue;

        shift = 1 << i;
        // 경로에 포함되어 있으면 스킵
        if(route & shift)
            continue;
        int newRoute = route | shift;

        // cout << "newRoute " << newRoute << endl;

        // 루트 탐색
        int sum = bitmask[now][route] + w[now][i];
        if(newRoute == (1<<N)-1){
            if(w[i][start] != 0 && sum + w[i][start] < bitmask[i][newRoute]){
                bitmask[i][newRoute] = sum + w[i][start];
                tsp(start, i, newRoute);
            }
        }else if(sum < bitmask[i][newRoute]){
            bitmask[i][newRoute] = sum;
            tsp(start, i, newRoute);
        }
        
        // if(dist + w[now][i] <= bitmask[newRoute]){
        //     bitmask[newRoute] = dist + w[now][i];
        // }

    }
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


    // 초기화
    for(int j=0; j<N; j++){
        for(int i=0; i< (1<<N); i++){
            bitmask[j][i] = INF;
        }
        bitmask[j][0] = 0;
    }
    
    
    for(int i=0; i<N; i++){
        bitmask[i][1<<i] = 0;
        tsp(i, i, 1<<i);
    }

    int mi = INF;   
    for(int i=0; i<N; i++){
        // cout << bitmask[i][(1<<N)-1] << endl;
        mi = min(mi, bitmask[i][(1<<N)-1]);
    }

    cout << mi;
    return 0;
}