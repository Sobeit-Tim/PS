#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;

int cost[101][101] = {0, };

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> m;
    int a,b,c;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            cost[i][j] = 987654321;
        }
    }

    for(int i = 0; i <= n; i++){
        cost[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }


    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == 987654321)
                cout << "0 ";
            else
                cout << cost[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}