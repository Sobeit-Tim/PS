#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

int N, M, K;

int arr[9];

int res[9];
int visit[100001] = {0,};
int parent[100001] = {0, };
vector<int> v[100001];

void solve(int node){
    visit[node] = 1;
    for(int i = 0; i<v[node].size(); i++){
        int child = v[node][i];
        if(visit[child] == 0){
            parent[child] = node;
            solve(child);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    int p, c;
    for(int i = 0; i < N; i++){
        cin >> p >> c;
        v[p].push_back(c);
        v[c].push_back(p);
    }
    
    solve(1);

    for(int i = 2; i<=N; i++){
        printf("%d\n", parent[i]);
    }

    return 0;
}