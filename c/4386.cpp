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

struct cmp{
    bool operator()(pair<double,int> a, pair<double,int> b){
        return a.first > b.first;
    }
};

double getDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int check[101] = {0, };
vector<pair<double, int>>edge[101];
double arr[101][2];

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        double x, y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    for(int i=0; i<n-1; i++){
        double x1 = arr[i][0], y1 = arr[i][1];
        for(int j=i+1; j<n; j++){
            double x2 = arr[j][0], y2 = arr[j][1];
            double dist = getDistance(x1, y1, x2, y2);
            edge[i].push_back(make_pair(dist, j));
            edge[j].push_back(make_pair(dist, i));
        }
    }

    priority_queue<pair<double, int>, vector<pair<double,int>>, cmp>q;
    double answer = 0;
    int cnt = 0;
    q.push(make_pair(0.0, 0));
    while(!q.empty()){
        double cost = q.top().first;
        int pos = q.top().second;
        q.pop();

        if(check[pos] == 1)
            continue;
        check[pos] = 1;
        answer += cost;
        cnt ++;
        if(cnt == n)
            break;
        
        for(int i=0; i<edge[pos].size(); i++){
            double c = edge[pos][i].first;
            int p = edge[pos][i].second;
            if(check[p] == 0){
                q.push(make_pair(c, p));
            }   
        }

    }

    printf("%.2f", answer);
    return 0;
}