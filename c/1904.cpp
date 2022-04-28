#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr[1000001] = {0,};

void solve(){
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i<= N; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 15746;
    }
}



int main(){
    freopen("input.txt", "r", stdin);

    cin >> N;

    solve();

    cout << arr[N];
    return 0;
}