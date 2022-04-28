#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr [21][21];
int visit[400] = {0,};
int s[400] = {0, };
vector<int> v;
int m = 987654321;

void solve(int cnt, int num){
    int start = 0;
    int link = 0;
    if(cnt == N / 2){
        int a = 0, b = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (i==j)
                    continue;
                if(visit[i] == 1 && visit[j] == 1)
                    a += arr[i][j];
                else if(visit[i] == 0 && visit[j] == 0)
                    b += arr[i][j];
            }
        }

        m = min(m, abs(b-a));
        return;
    }

    for(int i = num; i<N; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            solve(cnt+1, i+1);
            visit[i] = 0;
        }
    }

    return;
}



int main(){

    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++){
            int n;
            scanf("%d", &n);
            arr[i][j] = n;
        }

    solve(0, 1);
    cout << m;
    return 0;
}