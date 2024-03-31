#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7; 
int parent[100005];
int sz[100005];
int n, m;
void init(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}
int Find(int u){
	if(u == parent[u]) return u;
	else{
		parent[u] = Find(parent[u]);
		return parent[u];
	}
}

bool Union(int u, int v){
	int x = Find(u);
	int y = Find(v);
	if(x == y) return false;
	return true;
}
void Merge(int u, int v){
	if(Union(u, v)){
		int x = Find(u);
		int y = Find(v);
		if(sz[x] > sz[y]){
			sz[x] += sz[y];
			parent[y] = x;
		}
		else{
			sz[y] += sz[x];
			parent[x] = y;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	init();
	for(int i = 1; i <= n; i++){
		int x, y, q; cin >> x >> y >> q;
		if(q == 1){
			Merge(x, y);
		}
		else{
			if(!Union(x, y)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
}