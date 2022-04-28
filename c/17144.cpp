#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int arr[50][50] = {0, };
int arr2[50][50] = {0, };
int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int machine = -1;

void diffuse(int r, int c, int w){
    for(int i=0; i<4; i++){
        int tempR = r + mov[i][0], tempC = c + mov[i][1];
        if(tempR < 0 || tempR >= n || tempC < 0 || tempC >= m)
            continue;
        if(tempC == 0 && (tempR == machine || tempR == machine+1))
            continue;
        arr2[tempR][tempC] += w;
        arr[r][c] -= w;
    }
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;

    cin >> n >> m >> T;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1 && machine == -1){
                machine = i;    
            }
        }
    }

    // print();

    while(T--){
        //확산
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] > 0){
                    int w = arr[i][j] / 5;
                    diffuse(i, j, w);
                }
            }
        }
        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] += arr2[i][j];
                arr2[i][j] = 0;
            }
        }

        // cout << "test\n";
        // print();

        //공기청정기
        //상단
        for(int i=machine-1; i>=1; i--){
            arr[i][0] = arr[i-1][0];
        }

        for(int i=1; i<m; i++){
            arr[0][i-1] = arr[0][i];
        }

        for(int i=1; i<=machine; i++){
            arr[i-1][m-1] = arr[i][m-1];
        }

        for(int i=m-2; i>=0; i--){
            arr[machine][i+1] = arr[machine][i];
        }
        
        //하단
        for(int i=machine+1; i<=n-2; i++){
            arr[i][0] = arr[i+1][0];
        }

        for(int i=0; i<=m-2; i++){
            arr[n-1][i] = arr[n-1][i+1];
        }

        for(int i=n-1; i>=machine+2; i--){
            arr[i][m-1] = arr[i-1][m-1];
        }

        for(int i=m-1; i>=1; i--){
            arr[machine+1][i] = arr[machine+1][i-1];
        }


        //초기화
        arr[machine][0] = -1;
        arr[machine][1] = 0;
        arr[machine+1][0] = -1;
        arr[machine+1][1] = 0;
        
        // cout << "test\n";
        // print();
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == -1)
                continue;
            answer += arr[i][j];
        }
    }
    cout <<answer;
    return 0;
}