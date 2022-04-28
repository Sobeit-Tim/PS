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

int arr[100001];
int arr2[100001];

bool solve(int num, int s, int e){

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    queue<int> q;

    for(int i = 1; i<=N; i++){
        q.push(i);
    }

    int answer = 0;
    while(q.size() >= 1){
        answer = q.front();
        q.pop();
        if(q.size() == 0)
            break;
        answer = q.front();
        q.pop();
        q.push(answer);
    }

    cout << answer;
    return 0;
}