#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int arr[2001][2001] = {0, };

vector<int>v;

int dp(int i, int j){
    int& ret = arr[i][j];
    if(ret != -1)
        return ret;
    
    if(i==j)
        return ret=1;
    if(i+1 == j){
        if(v[i] == v[j])
            return ret = 1;
        else
            return ret = 0;
    }
    if(v[i] == v[j] && dp(i+1, j-1) == 1)
        return ret = 1;
    return ret = 0; 
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int num;
    for(int i = 0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }
    
    fill(&arr[0][0], &arr[2000][2001], -1);

    // for(int i = 0; i < n; i++ ){
    //     arr[i][i] = 1;
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(v[i] == v[j]){
    //             if(i+1 <= j-1){
    //                 if(arr[i+1][j-1] == 1)
    //                     arr[i][j] = 1;
    //             }else{
    //                 arr[i][j] = 1;
    //             }
    //         }
    //     }
    // }

    cin >> m;
    int s,e;
    while(m--){
        cin >> s >> e;
        // cout << arr[s-1][e-1] << endl;
        cout << dp(s-1, e-1) << "\n";
    }


    return 0;
}