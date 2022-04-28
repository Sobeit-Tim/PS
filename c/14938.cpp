#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n,m,r=0;
int score[101];
int res[101] = {0, };
int answer = 0;
int dist[101] = {0,};
vector<pair<int, int> > v[101];

void dfs(int now, int w, int val){
    //cout << now << " " << w << " " << val << endl;
    int result = 0;
    
    for(int i = 0; i<v[now].size(); i++){
        int p = v[now][i].first, weight = v[now][i].second;
        //cout << p <<  " " << weight << " " << dist[p] <<endl;
        if(w + weight <= m && dist[p] > w + weight){
            dist[p] = w + weight;
            dfs(p, w + weight, val + score[p]);
        }
    }
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;
    for(int i = 1; i <=n; i++){
        cin >> score[i];
    }
    for(int i = 0; i < r; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++)
            dist[j] = 987654321;
        dist[i] = 0;
        dfs(i, 0, score[i]);
        int t = 0;
        for(int j = 1; j <= n; j++){
            if(dist[j] < 987654321)
                t += score[j];
        }
        if (t > answer)
            answer = t;
    }
    cout << answer;
    return 0;
}