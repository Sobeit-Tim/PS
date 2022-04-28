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
int pos[200001] = {0, };

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int cnt = 0;
    answer = INF;
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        pos[now] = 1;
        if(cost > answer)
            break;
        if(now == m){
            cnt++;
            answer = cost;
            continue;
        }

        if(now*2 <= 200000 && pos[now*2] == 0)
            q.push(make_pair(now*2, cost+1));
        
        if(now+1 <= 200000 && pos[now+1] == 0)
            q.push(make_pair(now+1, cost+1));
            
        if(now-1 <= 200000 && pos[now-1] == 0)
            q.push(make_pair(now-1, cost+1));

    }

    cout << answer << endl << cnt;
    return 0;
}