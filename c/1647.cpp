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

int maxEdge = 0;

int check[100001] = {0, };

vector<pair<int, int>>v[100001];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){

        return a.first > b.first;
    }  
};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int A,B,C;
    for(int i = 0; i<=m; i++){
        cin >> A >> B >> C;
        v[A].push_back(make_pair(B, C));
        v[B].push_back(make_pair(A, C));
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> q;

    q.push(make_pair(0, 1)); // 비용, 위치
    while(!q.empty()){
        int cost = q.top().first;
        int pos = q.top().second;
        q.pop();
        if(check[pos] == 1)
            continue;

        if(cost > maxEdge)
            maxEdge = cost;
        
        check[pos] = 1;
        cnt++;
        answer += cost;
        if(cnt == n)
            break;
        
        for(int i=0; i<v[pos].size(); i++){
            if(check[v[pos][i].first] == 0)
                q.push(make_pair(v[pos][i].second, v[pos][i].first));
        }

    }

    cout << answer - maxEdge;
    return 0;
}