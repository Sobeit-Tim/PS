#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,r=0;
int answer = 0;
int dist[1001] = {0, };
int parent[1001] = {0, };
vector<pair<int, int> >v[1001];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int A,B;

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    for(int i = 0 ; i<m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }

    cin >> A >> B;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>q;

    q.push(make_pair(A, 0));
    // cout << A << " " << B << endl;
    
    while(!q.empty()){
        int now = q.top().first;
        int cost = q.top().second;
        // cout << now << " " << cost << endl;
        if(cost < dist[now])
            dist[now] = cost;
        q.pop();
        if(now == B || cost > dist[B])
            continue;
        for(int i = 0; i < v[now].size(); i++){
            if(cost + v[now][i].second < dist[v[now][i].first]){
                dist[v[now][i].first] = cost + v[now][i].second;
                parent[v[now][i].first] = now;
                q.push(make_pair(v[now][i].first, cost + v[now][i].second));
            }
        }
    }

    cout << dist[B] << endl;
    int pos = B;
    vector<int>res;
    while(pos != A){
        res.push_back(pos);
        pos = parent[pos];
    }

    res.push_back(pos);
    cout << res.size() << endl;
    for(int i = res.size()-1; i >= 0; i--){
        cout << res[i] << " ";
    }


    return 0;
}