#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>

#define INF 987654321

using namespace std;

int n, m;
int parent[500001];

int getParent(int x){
    if(parent[x] == x)
        return x;
    
    return parent[x] = getParent(parent[x]);
}

void unionFind(int x, int y){
    int px = getParent(x);
    int py = getParent(y);

    parent[py] = px;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++)
        parent[i] = i;

    int cnt = 1;
    bool flag = false;
    while(m--){
        int from, to;
        cin >> from >> to;
        if(getParent(from) == getParent(to)){
            flag = true;
            break;
        }

        unionFind(from, to);
        cnt++;
    }

    if(flag)
        cout << cnt;
    else
        cout << 0;

    return 0;
}