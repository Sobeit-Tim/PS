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

    int N;
    cin >> N;
    vector<int> v;

    while(N--){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int low = 0, high = v.size()-1;

    N = v.size();
    int answer = v[low]+v[high];
    int answer_low = v[low], answer_high = v[high];
    while(low < high){
        int sum = v[low]+v[high];
        if(abs(answer) > abs(sum)){
            answer = sum;
            answer_low = v[low];
            answer_high = v[high];
        }
        if(sum == 0)
            break;
        else if(sum < 0)
            low++;
        else
            high--;
    }

    cout << answer_low << " " << answer_high;
    // cout << endl <<  answer;

    return 0;
}