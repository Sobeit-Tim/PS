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
    int answer = 1;
    if(K == 0)
        return answer;
    int num = N;
    for(int i = 1; i<=K; i++){
        answer *= num;
        num--;
        answer /= i;
    }
    return answer;
}



int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    cout << solve();

    return 0;
}