#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;

int arr[21][21];
int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int findMax(int a[][21]){
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[i][j] > res)
                res = a[i][j];
        }
    }
    return res;
}

/* a의 값을 b로 */
void copyArray(int a[][21], int b[][21]){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            a[i][j] = b[i][j];
}

int dfs(int a[][21], int depth){
    // cout << depth << " depth \n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // } 
    int res = 0;
    if(depth >= 5){

        return findMax(a);
    }

    // 가로 방향, 세로 방향 0이 아닌 요소들 찾기
    vector<int>rowVec[21], colVec[21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[i][j] != 0){
                rowVec[i].push_back(a[i][j]);
                colVec[j].push_back(a[i][j]);
            }
        }
    }
    
    // 행,열 왼쪽, 위쪽 
    int rowTemp[21][21] = {0, }, colTemp[21][21] = {0, };
    int rowCnt = 0, colCnt = 0;
    int vSize;
    for(int i=0; i<N; i++){ 
        // 행
        rowCnt = 0;
        colCnt = 0;
        vSize = rowVec[i].size();
        for(int j=0; j<vSize; j++){
            if(j != vSize-1 && rowVec[i][j] == rowVec[i][j+1]){
                rowTemp[i][rowCnt] = 2*rowVec[i][j];
                j++;
            }else{
                rowTemp[i][rowCnt] = rowVec[i][j];
            }
            rowCnt++;
        }
        // 열
        vSize = colVec[i].size();
        for(int j=0; j<vSize; j++){
            if(j != vSize-1 && colVec[i][j] == colVec[i][j+1]){
                colTemp[colCnt][i] = 2*colVec[i][j];
                j++;
            }else{
                colTemp[colCnt][i] = colVec[i][j];
            }
            colCnt++;
        }
    }
    
    res = max(res, dfs(rowTemp, depth+1));
    res = max(res, dfs(colTemp, depth+1));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            rowTemp[i][j] = 0;
            colTemp[i][j] = 0;
        }

    for(int i=0; i<N; i++){ 
        // 행
        vSize = rowVec[i].size();
        rowCnt = 0;
        colCnt = 0;
        for(int j=0; j<vSize; j++){
            if(j != vSize-1 && rowVec[i][vSize-1-j] == rowVec[i][vSize-1-j-1]){
                rowTemp[i][N-1-rowCnt] = 2*rowVec[i][vSize-1-j];
                j++;
            }else{
                rowTemp[i][N-1-rowCnt] = rowVec[i][vSize-1-j];
            }
            rowCnt++;
        }
        // 열
        vSize = colVec[i].size();
        for(int j=0; j<vSize; j++){
            if(j != vSize-1 && colVec[i][vSize-1-j] == colVec[i][vSize-1-j-1]){
                colTemp[N-1-colCnt][i] = 2*colVec[i][vSize-1-j];
                j++;
            }else{
                colTemp[N-1-colCnt][i] = colVec[i][vSize-1-j];
            }
            colCnt++;
        }
    }

    res = max(res, dfs(rowTemp, depth+1));
    res = max(res, dfs(colTemp, depth+1));
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    // 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력.
    // depth가 5가 될 때까지 하는 함수 생성.

    cout << dfs(arr, 0);


    return 0;
}