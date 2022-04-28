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


// 
int solve(int num, matrix arr, int cnt){

    // cout << num << " " << cnt << endl;
    if(num >= N*N)
        return cnt;
    
    int color = (num%N  + num/N)%2;
    
    int res = cnt;

    int curCnt = num;
    while(curCnt < N*N){
        int r = curCnt/N;
        int c = curCnt%N;
        
        int tempColor = (r+c)%2;
        curCnt++;
        // cout << "temp " << tempColor << " " << color << endl;
        if(tempColor != color){
            continue;
        }
        // 놓을 수 있는 곳
        if(arr[r][c] == 1){
            
            // 대각선 비숍 확인
            int tempR = r, tempC = c;
            bool flag = true;

            while(flag && tempR >= 0 && tempC >= 0){
                if(arr[tempR][tempC] == 2){
                    flag = false;
                }
                tempR--;
                tempC--;
            }

            tempR = r, tempC = c;
            while(flag && tempR < N && tempC < N){
                if(arr[tempR][tempC] == 2)
                    flag = false;
                tempR++;
                tempC++;
            }

            tempR = r, tempC = c;
            while(flag && tempR >= 0 && tempC < N){
                if(arr[tempR][tempC] == 2)
                    flag = false;
                tempR--;
                tempC++;
            }

            tempR = r, tempC = c;
            while(flag && tempR < N && tempC >= 0){
                if(arr[tempR][tempC] == 2)
                    flag = false;
                tempR++;
                tempC--;
            }

            // 놓을 수 없는 곳
            if(!flag)
                continue;

            arr[r][c] = 2;
            res = max(res, solve(curCnt-1, arr, cnt+1));
            arr[r][c] = 1;
        }
    }

    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    matrix v(N, vector<int>(N, 0));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> v[i][j];

    // 체스판 색깔별로 경우를 나눔. 
    cout << solve(0, v, 0) + solve(1, v, 0);


    return 0;
}