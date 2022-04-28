#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

vector<int>v[32001];

int indegree[32001] = {0,};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int num;
    int from, to;
    for(int i = 1; i<=m; i++){
        cin >> from >> to;
        v[from].push_back(to);
        indegree[to]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int now = q.top();
        q.pop();
        cout << now << " ";
        for(int i = 0; i<v[now].size(); i++){
            int target = v[now][i];
            indegree[target]--;
            if(indegree[target] == 0)
                q.push(target);
        }
    }

    return 0;
}