#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

bool truth = false;

class Node
{
public:
  int data;
  Node *left, *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << endl;
  inorder(root->right);
}

bool isSumTree(Node* root)
{
  if(root == NULL)
    return true;
  if (root->right == NULL && root->left == NULL)
    return true;
  if (root->right == NULL && root->left != NULL && (root->left->data == root->data))
    return true;
  if (root->right != NULL && root->left == NULL && (root->right->data == root->data))
    return true;
  if (root->data == (root->left->data + root->right->data))
    return isSumTree(root->left) && isSumTree(root->right) ;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node* root = new Node(13);
  root->left          = new Node(10);
  root->right         = new Node(3);
  root->left->left    = new Node(4);
  root->left->right   = new Node(6);
  root->right->right = new Node(3);
  // cout << "Inorder traversal" << endl;
  // inorder(root);
  cout << (isSumTree(root) ? "OK" : "NO") << endl;
  return 0;
}
