#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int val) {
		this->data = val;
		left = NULL;
		right = NULL;
	}
};

struct Node* insert(Node *root, int key) {
	if (root == NULL) {
		return new Node(key);
	}

	if (root->data < key) {
		root->right = insert(root->right, key);
	}

	if (root->data > key) {
		root->left = insert(root->left, key);
	}

	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}
}

int main() {
	Node *root = new Node(7);
	insert(root, 5);
	insert(root, 9);
	insert(root, 6);
	inorder(root);
}
