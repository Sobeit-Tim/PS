#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr [12];
int oper[11];
int visit[11] = {0,};
int s[11] = {0, };
vector<int> v;
int mi = 1987654321;
int ma = -1987654321;

int calculate(int a, int b, int o){
    switch(o){
        case 0: return a+b;
        case 1: return a-b;
        case 2: return a*b;
        case 3: return int(a/b);
        default:break;
    }
}

void solve(int cnt, int num){
    if(cnt == N-1){
        ma = max(ma, num);
        mi = min(mi, num);
        return;
    }

    for(int i = 0; i<4; i++){
        if(oper[i] > 0){
            oper[i]--;
            solve(cnt+1, calculate(num, arr[cnt+1], i));
            oper[i]++;
        }
        
    }
    return;
}



int main(){

    freopen("input.txt", "r", stdin);
    scanf("%d", &N);

    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0 ; i<4; i++)
        scanf("%d", &oper[i]);
    
    solve(0, arr[0]);

    cout << ma << endl << mi;
    return 0;
}