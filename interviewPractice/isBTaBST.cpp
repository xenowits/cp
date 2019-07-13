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

class Node
{
public:
  int data;
  Node* left, *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

int ans = INT_MIN;

void inorder(Node* root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  if (root->data >= ans)
    ans = root->data;
  else
  {
    cout << "NOT A BST" << endl;
    exit(0);
  }
  inorder(root->right);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node* root = new Node(6);
  root->left          = new Node(4);
  root->right         = new Node(7);
  root->left->left    = new Node(2);
  root->left->right   = new Node(5);
  inorder(root);
  cout << "IS A BST" << endl;
  return 0;
}
