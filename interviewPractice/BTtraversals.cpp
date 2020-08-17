#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	//LRV
	
	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);
}

void preorder(Node *root) {
	if (root == NULL) {
		return;
	}

	//VLR
	
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void levelorder(Node *root) {
	if (root == NULL) {
		return;
	}
	
	queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}
}

int main() {
	//construct a binary tree
	
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 

	//Print inorder
	inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	levelorder(root);
	cout << endl;
}
