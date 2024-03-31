#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7; 
ll cal(ll a, ll b, string c){
    if(c == "/") return a / b;
    if(c == "*") return a * b;
    if(c == "+") return a + b;
    return a - b;
}
bool check(string s){
    return s != "+" && s != "-" && s != "*" && s != "/";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        stack<ll> st;
        if(check(v[0])){
            for(int i = 0; i < n; i++){
                if(v[i] == "*" || v[i] == "/" || v[i] == "+" || v[i] == "-"){
                    ll b = st.top(); st.pop();
                    ll a = st.top(); st.pop();
                    st.push(cal(a, b, v[i]));
                }   
                else{
                    ll val = stoll(v[i]);
                    st.push(val);
                }
            }
            cout << st.top() << endl;
        }
        else{
            for(int i = n - 1; i >= 0; i--){
                if(v[i] == "*" || v[i] == "/" || v[i] == "+" || v[i] == "-"){
                    ll a = st.top(); st.pop();
                    ll b = st.top(); st.pop();
                    st.push(cal(a, b, v[i]));
                }   
                else{
                    ll val = stoll(v[i]);
                    st.push(val);
                }
            }
            cout << st.top() << endl;
        }
    }   
    system("pause");
    return 0;
}