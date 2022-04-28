#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

long long N,M;

int arr[100][100];
int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c){
    arr[r][c] = 2;
    for(int i=0; i<4; i++){
        int tempR = r + mov[i][0];
        int tempC = c + mov[i][1];
        
        if(tempR < 0 || tempR >= N  || tempC < 0 || tempC >= M)
            continue;
        if(arr[tempR][tempC] == 0)
            dfs(tempR, tempC);
    }
    
}

int check(int r, int c){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int tempR = r + mov[i][0];
        int tempC = c + mov[i][1];
        if(tempR < 0 || tempR >= N  || tempC < 0 || tempC >= M)
            continue;
        if(arr[tempR][tempC] == 2)
            cnt++;
    }

    if(cnt >= 2)
        return 1;
    return 0;
        
}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    vector<pair<int, int>> v;
    dfs(0, 0);
    while(1){
        bool flag = false;
        for(int i = 0; i<v.size(); i++){
            dfs(v[i].first, v[i].second);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] == 1){
                    flag = true;
                    if(check(i, j) == 1)
                        v.push_back(make_pair(i,j));
                }
            }
        }
        if(!flag)
            break;
        cnt++;
    }

    cout << cnt;

    return 0;
}