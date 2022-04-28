#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string str[50];
int N,M;

int solve(int r, int c){
    
    char check = str[r][c];
    int cntEven = 0, cntOdd = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                if(str[r+i][c+j] == check)
                    cntEven++;
            }else if(str[r+i][c+j] != check){
                cntOdd++;
            }
        }
    }
    return min(cntEven+cntOdd, 64-(cntEven+cntOdd));
}

int main(){
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> str[i];
        // cout << str[i];
    }
    
    int cnt = 987654321;
        
    for(int i = 0; i<N; i++){
        if(i + 8 > N)
            break;
        for(int j = 0; j<M; j++){
            if(j + 8 > M)
                break;
            cnt = min(cnt, solve(i, j));
        }
    }
    cout << cnt;
    return 0;
}