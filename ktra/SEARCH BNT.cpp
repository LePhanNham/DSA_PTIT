#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7; 
struct node{
	int val;
	node *left, *right;
	node(int v){
		val = v;
		left = right = NULL;
	}
};
node *insertNode(node *root, int x){
	if(root == NULL){
		return new node(x);
	}
	if(x < root->val){
		root->left = insertNode(root->left, x);
	}
	else{
		root->right = insertNode(root->right, x);
	}
	return root;
}
void preOrder(node *root){
	if(root == NULL) return;
	cout << root->val << ' ';
	preOrder(root->left);
	preOrder(root->right);
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node *root = NULL;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			root = insertNode(root, x);
		}	
		preOrder(root);
		cout << endl;
	}
}