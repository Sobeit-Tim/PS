#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

int N, M, K;

int arr[1001] = {0, };

bool solve(int num, int s, int e){

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> K; 
    int cnt = N;
    int pos = -1;
    vector<int> v;
    while(cnt){
        int check = K;
        while(check > 0){
            pos++;
            pos %= N;
            if(arr[pos] == 0)
                check--;
        }
        arr[pos] = 1;
        v.push_back(pos+1);
        cnt--;
    }
    printf("<%d", v[0]);
    for(int i = 1; i < v.size(); i++){
        printf(", %d", v[i]);
    }
    printf(">");
    return 0;
}