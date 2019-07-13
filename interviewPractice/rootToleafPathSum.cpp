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

class Node{
public:
  int data;
  Node *left, *right;
  Node(int a)
  {
    this->data = a;
    left = right = NULL;
  }
};

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << endl;
  inorder(root->right);
}

bool hasPathSum(Node *root, int sum)
{
  if (root == NULL)
    return (sum == 0);
  else
  {
    int subSum = sum - root->data;
    if (root->left == NULL && root->right == NULL && subSum == 0)
      return 1;
    return ( (root->right && hasPathSum(root->right,subSum)) || (root->left && hasPathSum(root->left,subSum)) );
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node *root = new Node(10);
  root->left = new Node(8);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  inorder(root);
  //cout << (4 == 1 ? 6 : 98) << endl;
  cout << (hasPathSum(root,22) ? "It has a path" : "No boss such a path doesn't exist");
  return 0;
}
