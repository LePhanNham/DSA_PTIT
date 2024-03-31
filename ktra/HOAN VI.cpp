#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n >> m;
	int a[n];
	vector<string> res;
	res.push_back("%%");
	for(int i = 0; i < n; i++) a[i]	= i + 1;
	do{
		string tmp = "";
		for(int i = 0; i < n; i++){
			tmp += to_string(a[i]) + ' ';
		}
		tmp.pop_back();
		res.push_back(tmp);
	}
	while(next_permutation(a, a + n));
	for(int i = 1; i < res.size() ; i++){
		if(i % m == 0) cout << res[i] << endl;
	}
}