#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

const int INF = 98765432;

int arr [501][501];
int dist[501] = {0, };
vector<int>cost, memory;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, w;
    cin >> T;  

    while(T--){
        cin >> n >> m >> w;
        // 초기화
        vector<pair<int,int>>v[501];
        for(int i = 1; i<=n; i++){
            dist[i] = INF;
            v[i].clear();
        }

        int from, to, cost;
        for(int i = 0; i<m; i++){
            cin >> from >> to >> cost;
            v[from].push_back(make_pair(to, cost));
            v[to].push_back(make_pair(from, cost));
        }
        
        for(int i = 0; i<w; i++){
            cin >> from >> to >> cost;
            v[from].push_back(make_pair(to, -cost));
            arr[from][to] = -cost;
        }

        // 벨만 포드 
        bool flag = false; // negative cycle detection
        dist[1] = 0;
        for(int i=0; i<n; i++){ // vertex  번 
            for(int j=1; j<=n; j++){
                for(int k=0; k<v[j].size(); k++){
                    from = j;
                    to = v[j][k].first;
                    cost = v[j][k].second;

                    if(dist[from] + cost < dist[to]){
                        dist[to] = cost + dist[from];
                        if(i==n-1)
                            flag = true;
                    }
                }
            }
        }

        if(flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

    }
    return 0;
}