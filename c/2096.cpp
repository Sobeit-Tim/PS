#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321

using namespace std;

int n,m,x=0;
int answer = 0;

int minScore[3];
int maxScore[3];
int temp[3];

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    minScore[0] = maxScore[0] = a;
    minScore[1] = maxScore[1] = b;
    minScore[2] = maxScore[2] = c;

    for(int i = 1; i<n; i++){
        cin >> a >> b >> c;
        temp[0] = a + min(minScore[0], minScore[1]);
        temp[1] = b + min(minScore[0], min(minScore[1], minScore[2]));
        temp[2] = c + min(minScore[1], minScore[2]);
        for(int j = 0; j<3; j++)
            minScore[j] = temp[j];

        temp[0] = a + max(maxScore[0], maxScore[1]);
        temp[1] = b + max(maxScore[0], max(maxScore[1], maxScore[2]));
        temp[2] = c + max(maxScore[1], maxScore[2]);
        for(int j = 0; j<3; j++)
            maxScore[j] = temp[j];

    }

    cout << max(maxScore[0], max(maxScore[1], maxScore[2])) << " ";

    cout << min(minScore[0], min(minScore[1], minScore[2])) ;  
    return 0;
}