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
  int data,height;
  Node* left, *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL;
    height = 0;
  }
};

int height(Node* node)
{
  if (node == NULL)
  {
    return 0;
  }
  node->height = 1+max(height(node->left),height(node->right));
  return node->height;
}

bool isHB(Node* root)
{
  if (root == NULL)
    return 1;
  int lh,rh;

  lh = (root->left ? root->left->height : 0);
  rh = (root->right ? root->right->height : 0);

  if (abs(lh-rh) <= 1 && isHB(root->left) && isHB(root->right))
    return 1;

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(8);
  int s = height(root);
  cout <<  (isHB(root) ? "is height balanced" : "not height balanced");
  return 0;
}
