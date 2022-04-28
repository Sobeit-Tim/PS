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

int n,m,x=0;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;
    
    stack<char>s;
    string res = "";

    int pointer = 0;
    int strSize = str.size();
    int bombSize = bomb.size();
    for(int i=0; i<strSize; i++){
        s.push(str[i]);
        if(s.size() >= bombSize && str[i] == bomb[bombSize-1]){
            int j;
            string temp = "";
            for(j = bombSize-1; j>=0; j--){
                if(s.top() != bomb[j]){
                    for(int k = temp.size()-1; k>=0; k--){
                        s.push(temp[k]);
                    }
                    
                    break;
                }
                temp += s.top();
                s.pop();
            }    
        }
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    if(res.size() == 0)
        cout << "FRULA";
    else{
        
        reverse(res.begin(), res.end());
        cout << res;
    }

    return 0;
}