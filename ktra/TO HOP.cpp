#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7; 
int X[25], a[25];
int k, N;
string s;
set<string> se;
void Try(int i){
	for(int j = X[i - 1] + 1; j <= N - k + i; j++){
		X[i] = j;
		if(i == k){
			string s = "";
			for(int idx = 1; idx <= k; idx++){
				s += to_string(a[X[idx]]);
			}
			se.insert(s);
		}
		else Try(i + 1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		cin >> s >> k;
		for(int i = 0; i < (int)s.size(); i++){
			a[i + 1] = s[i] - '0';
		}
		N = s.size();
		se.clear();
		Try(1);
		for(string s : se) cout << s << endl;
	}	
	system("pause");
	return 0;
}