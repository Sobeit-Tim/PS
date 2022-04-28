#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

typedef vector<vector<int> >matrix;

int N;

bool cmpWeight(pair<int, int> &a, pair<int, int> &b){
    // 무게 작은 순 정렬
    return a.first < b.first;
}

struct cmpValue{
    // value 큰 순으로 정렬 
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int> >jewerl;
    vector<int>bag;

    // input 
    for(int i=0; i<N; i++){
        int m, v;
        cin >> m >> v;
        jewerl.push_back(make_pair(m, v));
    }

    for(int i=0; i<K; i++){
        int num;
        cin >> num;
        bag.push_back(num);
    }

    // 무게 기준 오름차순 정렬
    sort(bag.begin(), bag.end());
    sort(jewerl.begin(), jewerl.end(), cmpWeight);

    // for(auto i = bag.begin(); i != bag.end(); i++){
    //     cout << *i << " ";
    // }

    // for(auto i = jewerl.begin(); i != jewerl.end(); i++){
    //     cout << i->first << " ";
    // }

    // 값 기준으로 내림차순 정렬할 pq 
    priority_queue<int, vector<int>, less<int>> q;

    std::vector<int>::iterator it;
    int j=0;
    long long answer = 0;
    
    // 무게가 가장 낮은 가방부터 순서대로 지금 무게보다 값이 작은 보석들을 pq에 삽입
    // 해당 pq는 값 기준 maxHeap
    // pq에서 pop -> 해당 가방에 가장 value가 큰 보석
    for(it = bag.begin(); it != bag.end(); it++){
        int siz = jewerl.size();
        for(; j<siz; j++){
            if(jewerl[j].first <= *it)
                q.push(jewerl[j].second);
            else
                break; 
        }

        if(!q.empty()){
            long long value = q.top();
            q.pop();
            answer+= value;
        }
    }

    cout << answer; 
    return 0;
}
