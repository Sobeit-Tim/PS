#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int arr[100][100][100] = {0, };
int check[100][100][100] = {0, };
int n, m, h;

int mov[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 1}};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> h;
    queue<pair<pair<int,int>, pair<int,int> >>q;

    int cnt = 0;
    int block = 0;

    for(int k = 0; k<h; k++){
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                int num;
                cin >> num;
                arr[i][j][k] = num;
                if(num == 1){
                    q.push(make_pair(make_pair(i,j), make_pair(k, 0)) );
                }
                if(num == -1)
                    block++;  
            }
        }
    }
    int answer = 0;
    while(!q.empty()){
        int r, c, p, w;
        r = q.front().first.first;
        c = q.front().first.second;
        p = q.front().second.first;
        w = q.front().second.second;
        q.pop();
        cnt++;
        if (w > answer)
            answer = w;
        for(int i = 0; i<6; i++){
            int tempR = r +mov[i][0], tempC = c + mov[i][1], tempP = p + mov[i][2];
            if(tempR < 0 || tempR >= n || tempC < 0 || tempC >= m || tempP < 0 || tempP >= h)
                continue;
            if(arr[tempR][tempC][tempP] == -1 || arr[tempR][tempC][tempP] == 1)
                continue;
            arr[tempR][tempC][tempP] = 1;
            q.push(make_pair(make_pair(tempR, tempC), make_pair(tempP, w+1)));
            
        }
    }
    if(cnt < n*m*h - block)
        cout << -1;
    else
        cout << answer;

    return 0;
}