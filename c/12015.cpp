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

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // LIS 판별
    vector<int>v;

    // 최소값 하나 넣어두기.
    v.push_back(0);

    cin >> N;
    while(N--){
        int num;
        cin >> num;
        // 마지막 값보다 크면 LIS 길이 증가
        if(num > v.back()){
            v.push_back(num);
        }else{
            // 이분탐색 ( lower_bound ) 이용하여 이 값이 들어갈 수 있는 위치로 갱신       - log N
            // 그래서 추후에 더 큰값이 들어와서 갱신될 수 있게 만들어줌. ( vector에 있는 값이 LIS 가 아닐 수 있음. )
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;

            // v2
            // int idx = lower_boud(v.begin(), v.end(), num) - v.begin();
            // v[idx] = num;
        }
    }

    cout << v.size()-1;


    return 0;
}