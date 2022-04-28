#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
char arr[21][21];

int check[26] = {0, };
int mov[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int answer = 0;

void dfs(int r, int c, int cnt){
    bool flag = false;
    for(int i = 0; i<4; i++){
        int tempR = r + mov[i][0];
        int tempC = c + mov[i][1];
        if(tempR < 0 || tempR >= n || tempC < 0 || tempC >= m)
            continue;
        
        int nextChar = arr[tempR][tempC];
        if(check[nextChar-'A'] == 0){
            check[nextChar-'A'] = 1;
            dfs(tempR, tempC, cnt+1);
            check[nextChar-'A'] = 0;
            flag = true;
        }
    }
    if(!flag){

        answer = max(answer, cnt);
        return;
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0 ; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    check[arr[0][0]-'A'] = 1;
    dfs(0, 0, 1);
    cout << answer;
    return 0;
}