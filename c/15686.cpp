#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n,m,cnt=0;
int answer = 987654321;
vector <pair<int, int> >chicken, house;
vector <int>v;

void solve(int now, int len){
    if(len == m){
        int res = 0;
        for(int i = 0; i < house.size(); i++){
            int temp = 987654321;
            for(int j = 0; j < v.size(); j++){
                int p = v[j];
                temp = min(temp, abs(house[i].first - chicken[p].first) + abs(house[i].second - chicken[p].second));
            }
            res += temp;
        }
        if(res < answer)
            answer = res;
        return;
    }

    for(int i=now+1; i<chicken.size(); i++){
        v.push_back(i);
        solve(i, len+1);
        v.pop_back();
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            cin >> num;
            if(num == 1)
                house.push_back(make_pair(i, j));
            else if(num == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    solve(-1, 0);

    cout << answer;
    return 0;
}