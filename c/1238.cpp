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
vector<pair<int,int>> v[1001];
int dist[1001][1001];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};


void dijkstra(int start, int end){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>q;
    q.push(make_pair(start, 0));
    dist[start][start] = 0;
    
    while(!q.empty()){
        int now = q.top().first;
        int cost = q.top().second;
        q.pop();

        if(now == end)
            continue;

        for(int i = 0; i < v[now].size(); i++){
            int n = v[now][i].first;
            int t = v[now][i].second;
            if(dist[start][n] > cost + t){
                dist[start][n] = cost + t;
                q.push(make_pair(n, cost+t));
            }
        }
        
    }
    // for(int i = 1; i<= n; i++){
    //     cout << dist[start][i] << endl;
    // }
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;
    for(int i = 0; i<m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }

    for(int i = 1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dist[i][j] = INF;

    dijkstra(x, -1);

    for(int i=1; i<=n; i++){
        if(i == x)
            continue;
        dijkstra(i, x);
        answer = max(answer, dist[i][x] + dist[x][i]);
    }


    cout << answer;    
    return 0;
}