#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,K;

typedef struct coord{
    int r;
    int c;
    int cnt;
    bool br;

    coord(){

    }

    coord(int a, int b, bool flag){
        r = a;
        c = b;
        br = flag;
        cnt = 0;
    }

    coord(int a, int b, bool flag, int d){
        r = a;
        c = b;
        br = flag;
        cnt = d;
    }
}coord;

int visit[1001][1001][2] = {0, };
string arr[1001];
queue<coord> q; 
int mov[4][2] = {{0, 1} ,{0, -1}, {1,0}, {-1,0}};

bool check(int i, int j){
    if(i < 0 || i >= N || j < 0 || j >= M)
        return false;
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    coord c = coord(0, 0, true);

    q.push(c);

    visit[0][0][0] = 1;
    visit[0][0][1] = 1;
    coord temp;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp.r == N-1 && temp.c == M-1){
            cout << temp.cnt + 1;
            return 0;
        } 
        
        if(temp.br == false){ // 이미 1번 부셨을 때
            for(int i = 0; i < 4; i++){
                int tempR = temp.r + mov[i][0];
                int tempC = temp.c + mov[i][1];
                if(check(tempR, tempC) && arr[tempR][tempC] == '0'){
                    if(visit[tempR][tempC][0] == 1 || visit[tempR][tempC][1] == 1)
                        continue;
                    q.push(coord(tempR, tempC, false, temp.cnt+1));
                    visit[tempR][tempC][1] = 1;
                }
            }
        }else{
            for(int i = 0; i < 4; i++){
                int tempR = temp.r + mov[i][0];
                int tempC = temp.c + mov[i][1];
                if(check(tempR, tempC)){
                    if(arr[tempR][tempC] == '0'){
                        if(visit[tempR][tempC][0] == 1)
                            continue;
                        q.push(coord(tempR, tempC, true, temp.cnt+1));
                        visit[tempR][tempC][0] = 1;
                    }else{
                        if(visit[tempR][tempC][1] == 1)
                            continue;
                        q.push(coord(tempR, tempC, false, temp.cnt+1));
                        visit[tempR][tempC][1] = 1;
                    }
                   
                }
            }
        }
    }

    cout << -1;

    return 0;
}