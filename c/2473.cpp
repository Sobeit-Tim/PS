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

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long> v;

    while(N--){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    N = v.size();

    sort(v.begin(), v.end());
    long long answer = 4e9;
    long long low, high, answer_low, answer_high, answer_standard;
    answer_standard = v[0];
    answer_low = v[1];
    answer_high = v[N-1];
    
    for(int i = 0; i<N-2; i++){
        long long standard = v[i];
        low = i+1; 
        high = N-1;
        
        while(low < high){
            long long s = standard + v[low] + v[high];
            if(abs(s) < abs(answer)){
                answer = s;
                answer_low = v[low];
                answer_high = v[high];
                answer_standard = standard;
            }
            
            if(s < 0){
                low++;
            }else{
                high--;
            }
        }
    }

    cout << answer_standard << " " << answer_low << " " << answer_high;
    // long long d = 1234567890;
    // cout << llabs(d);
    return 0;
}