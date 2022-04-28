#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
int parent[1000011] = {0, };
int answer = 0;

int find(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void unionParent(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb) parent[pb] = pa;
}


int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int query, a, b;
        cin >> query >> a >> b;
        if(query == 0){
            // union
            unionParent(a, b);
        }else{
            // find
            int parentA = find(a);
            int parentB = find(b);
            if(parentA == parentB)
                cout << "YES\n";
            else 
                cout << "NO\n";

        }
    }

    return 0;
}