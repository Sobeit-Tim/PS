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
vector<int> v;

void dfs(int s, int e){

    if(s > e)
        return;
    if(s == e){
        cout << v[s] << endl;
        return;
    }

    int mid = e+1;
    for(int i = s+1; i <= e; i++){
        if(v[i] > v[s]){
            mid = i;
            break;
        }
    }

    dfs(s+1, mid-1);
    dfs(mid, e);
    cout << v[s] << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    while(cin >> num){
        
        v.push_back(num);
    }
    v.push_back(INF);
    dfs(0, v.size()-2);

    return 0;
}