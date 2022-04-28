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

int arr[100001];
int arr2[100001];

bool solve(int num, int s, int e){
    int mid = (s+e)/2;
    if(s > e)
        return false;
    if(num == arr[mid])
        return true;
    else{
        if(num < arr[mid]){
            return solve(num, s, mid-1);
        }else{
            return solve(num, mid+1, e);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    int num;
    vector<int> v2;

    for(int i = 0; i < N; i++){
        cin >> num;
        arr[i] = num;
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        arr2[i] = num;
    }

    sort(arr, arr+N);
    int j = 0;
    for(int i = 0; i < M; i++){
        if(solve(arr2[i], 0, N-1)){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }


    return 0;
}