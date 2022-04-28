#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,x=0;
int parent[1000001] = {0,};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num == 1)
            break;
        if(num == 0)
            continue;
        if(num%3 == 0 && parent[num/3] == 0){
            parent[num/3] = num;
            q.push(num/3);
        }
        
        if(num%2 == 0 && parent[num/2] == 0){
            parent[num/2] = num;
            q.push(num/2);
        }
        
        if(num > 1 && parent[num-1] == 0){
            parent[num-1] = num;
            q.push(num-1);
        }

    }
    
    vector<int> v;
    int i = 1;
    while(i != n){
        v.push_back(i);
        i = parent[i];
    }

    v.push_back(n);

    cout << v.size()-1 << endl;
    for(int i = v.size()-1; i >= 0; i--){
        cout << v[i] << " ";
    }
    return 0;
}