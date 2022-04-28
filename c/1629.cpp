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
long long A,B,C;

long long solve(long long num, long long p){
    if(p == 1)
        return num % C;
    long long temp = solve(num, p/2) % C ;
    long long res = (temp * temp) % C;
    if(p%2 == 0)
        return res;
    else
        return (res * solve(num, 1)) % C;

}
int main(){
    freopen("input.txt", "r", stdin);
    cin >> A >> B >> C;

    cout << solve(A, B);

    return 0;
}