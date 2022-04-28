#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int cost[10001] = {0, };
int answer = 0;

vector<pair<int,int> > v[10001];

int dfs(int now){
    if(v[now].size() == 0)
        return 0;
    int m = 0;
    int m2 = 0;
    
    for(int i = 0; i<v[now].size(); i++){
        int temp = v[now][i].second + dfs(v[now][i].first);
        if(temp > m2){
            m2 = temp;
        }
        if(temp >= m){
            m2 = m;
            m = temp;
        }
    }
    cost[now] = m + m2;
    if(cost[now] > answer)
        answer = cost[now];
    return m;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    int a,b,c;

    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        
    }

    int test = dfs(1);

    //cout << test;
    cout << answer;
    return 0;
}