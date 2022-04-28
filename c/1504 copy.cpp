#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MOD 1000000007
#define INF 987654321

using namespace std;

int M, N, E;
vector<pair<int, int>>v[801];
int dist[801][801];

struct cmp{
    bool operator()(pair<int, int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

void dijkstra(int start, int end){
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>q;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        int now = q.top().first;
        int cost = q.top().second;
        q.pop();
        if(now == end)
            continue;

        for(int i=0; i<v[now].size(); i++){
            int target = v[now][i].first;
            int w = v[now][i].second;
            if(dist[start][target] > cost + w){
                dist[start][target] = cost + w;
                q.push(make_pair(target, cost+w));
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N >> E;

    int from, to, cost;
    for(int i = 0; i < E; i++){
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
        v[to].push_back(make_pair(from, cost));
    }
    
    int p1, p2;

    cin >> p1 >> p2;

    // init
    for(int i = 1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j] = INF;
            if(i==j)
                dist[i][j] = 0;
        }
    }

    dijkstra(1, -1);

    dijkstra(p1, p2);

    dijkstra(p1, N);
    dijkstra(p2, N);

    long long answer = dist[p1][p2];
    
    answer = min(answer + dist[1][p1] + dist[p2][N], answer + dist[1][p2] + dist[p1][N]);
    if(answer >= INF)
        cout << -1;
    else    
        cout << answer;
    return 0;
}