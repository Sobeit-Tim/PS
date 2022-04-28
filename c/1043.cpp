#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,x=0;
int answer = 0;

int flag[51] = {0, };
vector<int>v[51];
int day[51] = {0, };

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int known, num, peopleCnt;
    cin >> known;
    for(int i = 0; i<known; i++){
        cin >> num;
        flag[num] = 1;
    }

    for(int i = 1; i <= m; i++){
        cin >> peopleCnt;
        bool check = false;
        for(int j = 0; j<peopleCnt; j++){
            cin >> num; 
            v[i].push_back(num);
            if(flag[num] == 1)
                check = true;
        }
        if(check){
            day[i] = 1;
            for(int j = 0; j<peopleCnt; j++){
                flag[v[i][j]] = 1;
            }
        }
        
    }

    int prev = m;
    int answer = m;
    for(int i = 1; i<=m; i++){
        if(day[i] == 1)
            answer--;
    }

    while(prev != answer){
        prev = answer;
        for(int i = 1; i<=m; i++){
            if(day[i] == 1)
                continue;
            bool check =false;
            for(int j = 0; j < v[i].size(); j++){
                int now = v[i][j];
                if(flag[now] == 1){
                    check = true;
                    break;
                }
            }
            if(check){
                day[i] = 1;
                answer--;
                for(int j = 0; j < v[i].size(); j++){
                    int now = v[i][j];
                    flag[now] = 1;
                }
            }
        }
    }

    cout << answer;    
    return 0;
}