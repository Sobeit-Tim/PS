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

int pos[1000001] = {0, };
int N;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    vector<int> arr;
    v.push_back(-1000000001);
    arr.push_back(-1000000001);
    cin >> N;

    // LIS 길이 구하기 
    // v에는 LIS 의 원본이 아닐 수 있음. 왜냐하면, 최종 갱신된 시점 ( v.back() 에 추가된 경우)에는 모든 값들이 답이지만
    // 그 이후에 LIS의 길이는 늘어나지 않고 안의 값들만 갱신되며 vector만 유지될 수 있음. 그러한 경우에는 답이 되지 못함.
    // 14002 에서 풀었던 dp[i]의 최대값의 위치를 찾고 순서대로 1씩 감소되며 그 dp값에 맞는 idx를 출력한 것과 마찬가지로
    // 비슷한 형태로 풀이하면 됨.
    // 각 값들이 갱신되는 위치를 기록하고, 위와 같이 최대 길이 위치 값부터 1씩 감소하며 원소를 찾아나가면 됨. 
    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        arr.push_back(num);
        if(num > v.back()){
            // 이 때의 스냅샷이, 답인데.  이를 알기 위해서는 위에 말한 것처럼 갱신되는 idx를 저장한다.
            pos[i] = v.size();
            v.push_back(num);
        }else{
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
            pos[i] = idx;
        }
    }

    // for(int i=0; i<=N; i++){
    //     cout << pos[i] << " ";
    // }
    // cout << endl;

    // LIS 길이
    int ans = v.size()-1; // -INF값 제외  v[0]
    cout << ans << endl;

    // LIS 
    vector<int>answer_lis;

    for(int i=N; i>=1; i--){
        if(pos[i] == ans){
            ans--;
            answer_lis.push_back(arr[i]);
        }
    }
    
    for(int i=answer_lis.size()-1; i>=0; i--){
        cout << answer_lis[i] << " ";
    }

    return 0;
}
