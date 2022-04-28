#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int check[4000001] = {0, };

vector<int>v;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 2; i<=n; i++){
        if(check[i] == 1)
            continue;
        for(int j=i*2; j<=n; j+=i){
            check[j] = 1;
        }
    }

    for(int i=2; i<=n; i++){
        if(check[i] == 0)
            v.push_back(i);
    }

    // for(int i=0; i<v.size(); i++)
    //     cout << v[i] << " ";

    int s=0, e=0;
    int answer = 0;
    int sum = 2;
    while(e<v.size() && v[e] <= n && s <= e){
        
        if(sum == n){
            answer++;
            sum -= v[s];
            s++;
        }else if(sum < n){
            e++;
            sum += v[e];
        }else{
            sum -= v[s];
            s++;
        }
    }

    cout << answer;

    return 0;
}