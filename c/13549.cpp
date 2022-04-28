#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string str[50];
int N,M,K;

int visit[100001] = {0,};

struct cmp{
    bool operator()(pair<int, int> a, pair<int,int> b){
        if(a.second != b.second){
            return a.second > b.second;
        }else{
            return a.first > b.first;
        }
    }
};

priority_queue<pair<int,int>, vector<pair<int,int> >, cmp > q;

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    
    q.push(make_pair(N, 0));
    int pos, cnt;
    while(!q.empty()){
        cnt = q.top().second;
        pos = q.top().first;
        
        q.pop();
        if(pos == K){
            cout << cnt;
            break;
        }
        if(pos > 100000 || pos < 0 || visit[pos] == 1)
            continue;
        visit[pos] = 1;
        q.push(make_pair(pos*2, cnt));
        q.push(make_pair(pos+1, cnt+1));
        q.push(make_pair(pos-1, cnt+1));
        
    }

    return 0;
}