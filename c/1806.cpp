#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <memory.h>

#define INF 987654321

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;
    int sum = 0, answer = N;
    vector<int> v;
    vector<int> sumList;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
        sum += num;
        sumList.push_back(sum);
    }

    if(v[0] >= S){
        cout << 1;
        return 0;
    }

    if(sumList[N-1] < S){
        cout << 0;
        return 0;
    }

    int s=0, e=1;
    while(s < N){
        int start = s==0 ? 0 : sumList[s-1];
        if(sumList[e] - start < S){
            e++;
            if(e >= N)
                break;
        }else{
            answer = min(answer, e-s+1);
            s++;
            if(s > e)
                break;
        }
    }

    cout << answer;

    return 0;
}