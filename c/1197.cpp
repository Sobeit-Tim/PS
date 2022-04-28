#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,x=0;
int V,E;
int answer = 0;
int cnt = 0;

int check[10001] = {0, };

vector<pair<int,int> >edge[10001];

struct cmp{
    bool operator()(pair<int, int>a, pair<int,int> b){
        return a.first > b.first;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    int A,B,C;

    for(int i = 0; i<E; i++){
        cin >> A >> B >> C;
        edge[A].push_back(make_pair(B, C));
        edge[B].push_back(make_pair(A, C));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q; // 비용, 위치 
    q.push(make_pair(0, 1));
    while(!q.empty()){
        int pos = q.top().second;
        int cost = q.top().first;
        // cout << pos << " " << cost << endl;
        q.pop();
        if(check[pos] == 1){
            continue;
        }
        check[pos] = 1;
        cnt ++;
        answer += cost;
        if(cnt == V)
            break;
        for(int i = 0; i < edge[pos].size(); i++){
            if(check[edge[pos][i].first] == 0)
                q.push(make_pair(edge[pos][i].second, edge[pos][i].first));
        }
    }
    
    cout << answer;

    return 0;
}