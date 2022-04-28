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

void solve(string a){
    bool check = true;
    int len = a.size();
    for(int i = 0; i < len/2; i++){
        if(a[i] != a[len-1-i])
            check = false;
    }

    if(check)
        cout << "yes" << endl;
    else   
        cout << "no" << endl;
    
}



int main(){
    freopen("input.txt", "r", stdin);
    string s;
    while(1){
        cin >> s;
        if(s.size() == 1 && s[0] == '0')
            break;
        solve(s);
    }


    return 0;
}