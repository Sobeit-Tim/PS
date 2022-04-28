#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N,M;
vector<int> v;
vector<pair<int,int> >cnt;
int arr[8002] = {0, };

void solve(){
    
    return;
}

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    int num;
    for(int i = 0; i<N; i++){
        cin >> num;
        v.push_back(num);
    }
        
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v[i];
        arr[v[i]+4000]++;
    } 

    for(int i = 0; i<8002; i++){
        if(arr[i] == 0)
            continue;
        cnt.push_back(make_pair(arr[i], i));
    }
    
    sort(cnt.begin(), cnt.end(), comp);

    cout << round(float(sum)/N) << endl;
    cout << v[int(N/2)] << endl;
    if(N > 1 && cnt[0].first == cnt[1].first)
        cout << cnt[1].second-4000 << endl;
    else
        cout << cnt[0].second-4000 << endl;;
    if(N == 1)
        cout << 0;
    else
        cout << v[N-1] - v[0];
    return 0;
}