#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

vector<int>v[1001];
int indegree[1001] = {0,};
vector<int>answer;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int cnt = 0;
    int T;
    for(int i=0; i<m; i++){
        cin >> T;
        int num;
        cin >> num;
        T--;
        int prev = num;
        while(T--){
            cin >> num;
            indegree[num]++;
            v[prev].push_back(num);
            prev = num;
        }
    }

    queue<int>q;

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer.push_back(now);

        for(int i=0; i<v[now].size(); i++){
            int target = v[now][i];
            indegree[target]--;
            if(indegree[target] == 0)
                q.push(target);
        }
    }

    if(answer.size() == n){
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << "\n";
        }
    }else
        cout << 0;

    return 0;
}