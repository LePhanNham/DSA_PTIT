#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int val){
		val = data;
		left = right = NULL;
	}
};

node *insertNode( node *root, int x){
	if(root == NULL){
		return new node(x);
	}
}