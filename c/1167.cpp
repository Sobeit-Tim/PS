#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int check[100001] = {0,};
int answer = 0, last = 0;

vector<pair<int,int> > v[100001];

void dfs(int now, int len){
    if(v[now].size() == 0)
        return;
    if(check[now] == 1)
        return;
    check[now] = 1;
    if(len > answer){
        answer = len;
        last = now;
    }
    for(int i = 0; i<v[now].size(); i++){
        dfs(v[now][i].first, len + v[now][i].second);

    }
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cin >> n;
    int a,b,c;

    for(int i = 0; i < n; i++){
        int to, from, w, num;
        cin >> from;
        while(1){
            cin >> num;
            if(num == -1)
                break;
            to = num;
            cin >> w;
            v[from].push_back(make_pair(to, w));
            v[to].push_back(make_pair(from, w));
        }
    }

    dfs(1, 0);
    answer = 0;
    memset(check, 0, sizeof(check));
    dfs(last, 0);

    //cout << test;
    cout << answer;
    return 0;
}