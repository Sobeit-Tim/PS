#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321
#define N 8
#define MOD 1000000007

using namespace std;

typedef vector<vector<long long> > matrix;

long long D;
matrix graph(N, vector<long long>(N, 0));

void setValue(int i, int j){
    graph[i][j] = 1;
    graph[j][i] = 1;
}

matrix matmul(matrix A, matrix B){
    matrix result(N, vector<long long>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                (result[i][j] += A[i][k] * B[k][j])%=MOD;
            }
        }
    }

    return result;
}

matrix solve(long long k, matrix v){
    if(k == 1)
        return v;
    matrix ret = solve(k/2, v);
    ret = matmul(ret, ret);
    if(k%2 == 1)
        ret = matmul(ret, v);

    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D;

    setValue(0, 1);
    setValue(0, 2);
    setValue(1, 3);
    setValue(1, 2);
    setValue(2, 3);
    setValue(2, 4);
    setValue(3, 4);
    setValue(3, 5);
    setValue(4, 5);
    setValue(4, 6);
    setValue(5, 7);
    setValue(6, 7);
    
    graph = solve(D, graph);

    cout << graph[0][0] % MOD;
    return 0;
}