#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int indegree[32001] = {0, };
vector<int> v[32001];

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        indegree[b]++;
        v[a].push_back(b);
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << " ";
        for(int i = 0; i<v[now].size(); i++){
            int target = v[now][i];
            indegree[target]--;
            if(indegree[target] == 0){
                q.push(target);
            }
        }

    }

    return 0;
}