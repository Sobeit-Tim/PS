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

int solve(int a, int b, int c){
    
    if(arr[a][b][c] != -1)
        return arr[a][b][c];
    
    if(a <= 50 || b <= 50 || c <= 50){
        arr[a][b][c] = 1;
        return 1;
    }
    if(a > 70 || b > 70 || c > 70){
        arr[a][b][c] = solve(70, 70, 70);
        return arr[a][b][c];
    }

    if (a < b && b < c){
        arr[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        return arr[a][b][c];
    }
        
        
    arr[a][b][c] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    return arr[a][b][c];
    
}



int main(){
    freopen("input.txt", "r", stdin);
    memset(arr, -1, sizeof(arr));
    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        a += 50;
        b += 50;
        c += 50;
        if(a == 49 && b == 49 && c == 49)
            break;
        printf("w(%d, %d, %d) = %d\n",a-50 ,b-50, c-50, solve(a, b, c));
    }


    return 0;
}