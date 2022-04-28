#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

typedef vector<vector<int> >matrix;

int N;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // 직선 교점 -> x = (ax1 - bx3 - y1 + y3)/(a-b)
    // 해당 x가 x1 ~ x2 에 있는지 확인

    // 기울기    
    int a, b;
    
    a = (y2-y1)/(x2-x1);
    b = (y4-y3)/(x4-x3);

    // 기울기 같으면 평행 또는 일치
    if(a == b){
        // y = a(x-x1) + y1   직선에   x3, y3 대입했을 때 성립하면 일치. 아니면 평행
        // y3 = a(x3-x1) + y1
        // y3 - ax3 = -ax1 + y1
        if(y3-a*x3 == -a*x1 + y1){ // 일치하면서 x범위 같을 때.
            cout << "일치 ";
            cout << 1;
        }else{  // 평행
            cout << "평행 " ;
            cout << 0;
        }
    }else{
        // 직선의 교점 구하기
        int x = (a*x1 - b*x3 - y1 + y3)/(a-b);
        if(x >= x1 && x <= x2 && x >= x3 && x <= x4){
            cout << "교점 " << x << " " ;
            cout << 1;
        }else
            cout << "없음 " ;
            cout << 0;
    }

    return 0;
}
