#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define MOD 1000000007

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

long long N,M;

int priority(char a){
    if(a == '(')
        return 0;
    else if(a == '+' || a == '-')
        return 1;
    else if(a == '*' || a == '/')
        return 2;
}

int main(){
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    vector<char>v;
    stack<char>st;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];
        else{
            if(s[i] == ')'){
                while(st.top() != '(' ){
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }else if(s[i] == '('){
                st.push(s[i]);
            }else{
                        
                while(!st.empty() && priority(s[i]) <= priority(st.top()) ){
                    
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}