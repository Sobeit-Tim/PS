#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[50];
int N,M;
vector<int> v;

void solve(int s, int e, string a, string b){
    if(s < 0 || e < 0)
        return;
    if(s == 0 && e == 0){
        v.push_back(stoi(a + "666" + b));
        return;
    }
    if(s == 0){
        for(int i = 0; i<=9; i++)
            solve(s, e-1, a, b+to_string(i));
    }else{
        int i = 0;
        
        for(; i<=9; i++)
            solve(s-1, e, a+to_string(i), b);
    }
    return;
}

int main(){
    // freopen("input.txt", "r", stdin);
    cin >> N;
    string a = "666";
    for(int i = 0; i<6; i++){
        solve(i, 5-i, "", "");
    }
    // cout << v.size() << endl;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // cout << v.size() << endl;
    
    cout << v[N-1] << endl;
    return 0;
}