#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n,m,cnt=0;
int answer = 987654321;
int arr[8][8] = {0, };
int arr2[8][8];
vector <pair<int, int> > blank, virus;
vector <int>v;

int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void acopy(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
            arr2[i][j] = arr[i][j];
    }
}

int count(){
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr2[i][j] == 0)
                res++;
        }
    }
    return res;
}

int print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int r, int c){
    for(int i = 0; i < 4; i++){
        int tempR = r + mov[i][0], tempC = c + mov[i][1];
        if(tempR < 0 || tempR >= n || tempC < 0 || tempC >= m)
            continue;
        if(arr2[tempR][tempC] == 0){
            arr2[tempR][tempC] = 2;
            dfs(tempR, tempC);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num;
            cin >> num;
            arr[i][j] = num;
            if(num == 2)
                virus.push_back(make_pair(i, j));
            else if(num == 0){
                blank.push_back(make_pair(i, j));
            }
        }
    }
    
    for(int i = 0; i < blank.size(); i++){
        for(int j = i+1; j< blank.size(); j++){
            for(int k = j+1; k < blank.size(); k++){
                acopy();

                int a = blank[i].first, b = blank[i].second;
                arr2[a][b] = 1;
                a = blank[j].first, b = blank[j].second;
                arr2[a][b] = 1;
                a = blank[k].first, b = blank[k].second;
                arr2[a][b] = 1;

                for(int l = 0; l < virus.size(); l++){
                    dfs(virus[l].first, virus[l].second);
                }

                int temp = count();
                if(temp > answer)
                    answer = temp;
            }
        }
    }

    cout << answer;
    return 0;
}