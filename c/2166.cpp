#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    long long x1, y1, x2, y2;
    long long x, y;

    vector<pair<long long, long long>>v;
    
    double sum = 0.0;
    
    for(int i=0; i<N; i++){
        cin >> x1 >> y1;
        v.push_back(make_pair(x1,y1));
    }

    for(int i=0; i<N-1; i++){
        sum += (v[i].first + v[i+1].first)*(v[i].second-v[i+1].second);
    }

    sum += (v[N-1].first + v[0].first)*(v[N-1].second-v[0].second);
    sum /= 2;
    sum = abs(sum);
    printf("%.1f", sum);
    return 0;
}