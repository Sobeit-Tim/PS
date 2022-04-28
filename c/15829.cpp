#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <memory.h>

using namespace std;

int N, M;

int arr[102][102][102] = {0, };


void solve(string s){
    M = 1234567891;
    long long r = 1;
    long long sum = 0;
    for(int i = 0; i < s.size(); i++){
        int a = s[i] - 96;
        
        sum = (sum + (a * r ))%M;
        r = (r*31)%M;
    }

    cout << sum;
}



int main(){
    freopen("input.txt", "r", stdin);
    string s;
    cin >> N;
    cin >> s;
    solve(s);


    return 0;
}