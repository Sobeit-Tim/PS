#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr[16][16] = {0, };

vector<int> v;
int mi = 1987654321;
int ma = -1987654321;
int answer = 0;

void check(int r, int c, int val, int pr, int pc){
    int tempR = r + pr;
    int tempC = c + pc;
    if(tempR < 0 || tempR >= N || tempC < 0 || tempC >=N)
        return;
    arr[tempR][tempC]+=val;
    if(arr[tempR][tempC] < 0)
        arr[tempR][tempC] == 0;
    check(tempR, tempC, val, pr, pc);
}

void solve(int cnt){
    if(cnt == N){
        answer++;
        return;
    }
    for(int i = 0; i<N; i++){
        if(arr[cnt][i] == 0){
            arr[cnt][i] = 2;
            check(cnt, i, 1, 1, 0);
            check(cnt, i, 1, 1, 1);
            check(cnt, i, 1, 1, -1);
            
            solve(cnt+1);

            arr[cnt][i] = 0;
            check(cnt, i, -1, 1, 0);
            check(cnt, i, -1, 1, 1);
            check(cnt, i, -1, 1, -1);
        }
    }
}



int main(){

    freopen("input.txt", "r", stdin);
    scanf("%d", &N);

    solve(0);
    cout << answer;
    return 0;
}