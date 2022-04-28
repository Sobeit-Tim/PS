#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

long long N,M;
mat fiboM = {{1, 1}, {1, 0}};
mat init = {{1, 0}, {0, 1}};

mat matMul(mat a, mat b){
    mat res = {{0, 0}, {0, 0}};
    int m = a.size();
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            for(int k=0; k<m; k++){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

mat fibo(long long k){
    if(k == 1)
        return fiboM;

    mat temp = fibo(k/2);

    if(k%2 == 1){
        return matMul(fiboM, matMul(temp, temp));
    }else  
        return matMul(temp, temp);
}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N;

    mat res = {{1, 0}, {0, 1}};
    if(N <= 1){
        cout << N;
        return 0;
    }

    // while(N > 0){
    //     if(N%2 == 1){
    //         res = matMul(res, fiboM);
    //     }
    //     fiboM = matMul(fiboM, fiboM);
    //     N /= 2;
    // }
    
    // cout << res[0][1];

    res = fibo(N-1);

    cout << res[0][0];

    return 0;
}