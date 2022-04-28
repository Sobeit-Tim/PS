#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>

#define INF 987654321

using namespace std;

int arr[1001][1001] = {0, };
string answer = "";
string a, b;

void print(int r, int c){
    if(r == 0 || c == 0 || arr[r][c] == 0)
        return;
    
    if(arr[r-1][c] == arr[r][c-1] && arr[r][c-1] == arr[r][c]-1){
        answer = a[r] + answer;
        print(r-1, c);
    }else if(arr[r-1][c] > arr[r][c-1])
        print(r-1, c);
    else
        print(r, c-1);
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> a >> b;

    a.insert(0, " ");
    b.insert(0, " ");
    // cout << a << endl << b;
    
    for(int i = 1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(a[i] == b[j]){
                arr[i][j] = 1 + arr[i-1][j-1];
            }else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    
    
    cout << arr[a.size()-1][b.size()-1] << endl;
    if(arr[a.size()-1][b.size()-1] > 0){
        print(a.size()-1, b.size()-1);
        cout << answer;
    }
    return 0;
}