#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct{
    int rx, ry, bx, by;
    int cnt;
}Pos;

int n, m;
char arr[11][11];
int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1,0}};
int visit[11][11][11][11] = {0, };

int checkMove(int r, int c){
    if(arr[r][c] == '.'){
        return 0;
    }
    return 1;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    Pos pos = {0, 0, 0, 0, 0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'R'){
                pos.ry = i;
                pos.rx = j;
            }else if(arr[i][j] == 'B'){
                pos.by = i;
                pos.bx = j;

            }
        }
    }

    bool flag = false;

    queue<Pos> q;
    q.push(pos);
    visit[pos.ry][pos.rx][pos.by][pos.bx] = 1;
    while(!q.empty()){
        Pos temp = q.front();
        q.pop();
        // 빨간 구슬이 빠진 경우
        if(arr[temp.ry][temp.rx] == 'O'){
            flag = true;
            cout << temp.cnt;
            break;
        }

        // 횟수 초과
        if(temp.cnt >= 10)
            continue;
        for(int i=0; i<4; i++){
            
            int nrx = temp.rx, nry = temp.ry, nbx = temp.bx, nby = temp.by;
            int moveRedCnt = 0, moveBlueCnt = 0;
            // 빨간 공 움직임
            // 현재 위치가 구멍이 아니고, 다음 위치가 벽이 아닐때까지 move
            while(arr[nry][nrx] != 'O' && arr[nry+mov[i][0]][nrx+mov[i][1]] != '#'){
                nry += mov[i][0];
                nrx += mov[i][1];
                moveRedCnt++;
            }

            // 파란 공 움직임
            // 현재 위치가 구멍이 아니고, 다음 위치가 벽이 아닐때까지 move
            while(arr[nby][nbx] != 'O' && arr[nby+mov[i][0]][nbx+mov[i][1]] != '#'){
                nby += mov[i][0];
                nbx += mov[i][1];
                moveBlueCnt++;
            }

            // 파란 공이 빠진 경우 제외 
            // 파란 공이 구멍으로 빠진 경우라면 이 경우는 아예 지ㅔ외
            if(arr[nby][nbx] == 'O')
                continue;

            // 겹친 경우 고려 
            // 빨간 공 파란 공 같은 경우에, 많이 움직인쪽을 빼주기. 
            if(nry == nby && nrx == nbx){
                if(moveRedCnt > moveBlueCnt){
                    nry -= mov[i][0];
                    nrx -= mov[i][1];
                }else{
                    nby -= mov[i][0];
                    nbx -= mov[i][1];
                }
            }

            // 이미 방문한 경우 제외
            if(visit[nry][nrx][nby][nbx] == 1)
                continue;

            // q에 새로 삽입
            visit[nry][nrx][nby][nbx] = 1;
            q.push({nrx, nry, nbx, nby, temp.cnt+1});
            
        }
    }

    if(!flag)
        cout << -1;

    return 0;
}