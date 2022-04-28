#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int arr[27][2] = {0, };
int check[27] = {0, };

void pre(int now){
    if(check[now])
        return;
    cout << char('A'+now-1);
    if(arr[now][0] > 0)
        pre(arr[now][0]);
    if(arr[now][1] > 0)
        pre(arr[now][1]);
}

void mid(int now){
    if(check[now])
        return;

    if(arr[now][0] > 0)
        mid(arr[now][0]);
    cout << char('A'+now-1);
    if(arr[now][1] > 0)
        mid(arr[now][1]);
}

void post(int now){
    if(check[now])
        return;
    
    if(arr[now][0] > 0)
        post(arr[now][0]);
    if(arr[now][1] > 0)
        post(arr[now][1]);
    cout << char('A'+now-1);
}

int main(){
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cin >> n;
    
    char a, b, c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(b != '.')
            arr[a-'A'+1][0] = b-'A'+1;
        if(c != '.')
            arr[a-'A'+1][1] = c-'A'+1;
    }

    // 전위
    memset(check, 0, sizeof(check));
    pre(1);
    cout << endl;
    // 중위
    memset(check, 0, sizeof(check));
    mid(1);
    cout << endl;
    // 후위
    memset(check, 0, sizeof(check));
    post(1);
    cout << endl;
    return 0;
}