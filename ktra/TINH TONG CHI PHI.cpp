#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k; cin >> n >> k;
	priority_queue<ll, vector<ll>, greater<ll>> q;	
	for(int i = 1; i <= n; i++){
		ll x; cin >> x;
		q.push(x);
	}
	ll ans = 0;
	while(q.size() > 1){
		ll maxx = -1e18, minn = 1e18, res = 0;
		for(int i = 1; i <= k; i++){
			if(q.empty()) break;
			ll tmp = q.top(); q.pop();
			maxx = max(maxx, tmp);
			minn = min(minn, tmp);
			res += tmp;
		}
		q.push(res);
		ans += maxx - minn;
	}
	cout << q.top() << endl;
	cout << ans << endl;
}