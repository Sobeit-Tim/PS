#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory.h>

using namespace std;

int N, M, K;

int solve(){

}

int arr[100001] = {0, };


int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    int num;
    vector<int> v1;
    vector<pair<int, int> >v2;
    for(int i = 0; i < N; i++){
        cin >> num;
        v1.push_back(num);
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        v2.push_back(make_pair(num, i));
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int j = 0;
    for(int i = 0; i < M; i++){
        while(j < N && v1[j] < v2[i].first)
            j++;
        
        if(j < N && v1[j] == v2[i].first)
            arr[v2[i].second] = 1;
    }

    for(int i = 0; i<M; i++)
        printf("%d\n", arr[i]);

    return 0;
}