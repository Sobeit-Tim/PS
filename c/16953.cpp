#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long A,B;
    cin >> A >> B;
    bool flag = false;
    queue<pair<long long, int> >q;
    q.push(make_pair(A, 1));
    while(!q.empty()){
        long long num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(num == B){
            cout << cnt;
            flag = true;
            break;
        }
        if(num > B)
            continue;
        string s = to_string(num);
        s += '1';
        if(s.length() <= 10){
            q.push(make_pair(stoll(s), cnt+1));
        }
        
        q.push(make_pair(num*2, cnt+1));

    }

    if(!flag)
        cout << -1;

    return 0;
}