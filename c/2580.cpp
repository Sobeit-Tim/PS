#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N, M;

int arr[10][10] = {0, };

vector<int> v;
int answer = 0;
bool flag = false;

int row[10][10] = {0,};
int col[10][10] = {0,};
int block[3][3][10] = {0,};

void solve(int cnt){
    
    if(cnt == 81 || flag){
        flag = true;
        for(int i = 0; i< N; i++){
            for(int j = 0; j<N; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        return;
    }

    int i = cnt/N;
    int j = cnt%N;

    if(arr[i][j] == 0){
        for(int k = 1; k <= N; k++){
            
            if(row[i][k] == 0 && col[j][k] ==0 && block[i/3][j/3][k] == 0){
                arr[i][j] = k;
                row[i][k] = 1;
                col[j][k] = 1;
                block[i/3][j/3][k] = 1;
                solve(cnt+1);
                row[i][k] = 0;
                col[j][k] = 0;
                block[i/3][j/3][k] = 0;
                arr[i][j] = 0;
                if(flag)
                    return;
            }
        }
    }else{
        solve(cnt+1);
    }
}



int main(){
    N = 9;
    freopen("input.txt", "r", stdin);

    for(int i = 0; i< N; i++)
        for(int j = 0; j<N; j++)
            cin >> arr[i][j];
    int c = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] != 0){
                row[i][arr[i][j]] = 1;
                col[j][arr[i][j]] = 1;
                block[i/3][j/3][arr[i][j]] = 1;
            }
        }
    }

    solve(c);
    return 0;
}