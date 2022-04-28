#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int arr[51][2];
    int N, x, y;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
        // cout << x << y << endl;
    }
    for(int i = 0; i<N; i++){
        int cnt = 0;
        for(int j = 0; j<N; j++){
            if(i == j)
                continue;
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                cnt++;
            
        }
        cout << cnt+1 << endl;
    }
}