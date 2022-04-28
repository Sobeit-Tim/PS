#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void solve(){
    
    return;
}

bool comp(char a, char b){
    return a > b;
}

int main(){
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    // cout << str << endl;
    sort(str.begin(), str.end(), comp);
    cout << str;        
    return 0;
}