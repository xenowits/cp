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

void printLR(Node* root)
{
  if (root)
  {

    if (root->left == NULL && root->right == NULL)
      cout << root->data << " ";

    printLR(root->left);
    printLR(root->right);

  }
}

void printLeftBoundary(Node* root)
{
  if (root)
  {

    if (root->left)
    {
      cout << root->data << " ";
      printLeftBoundary(root->left);
    }

    else if (root->right)
    {
      cout << root->data << " ";
      printLeftBoundary(root->right);
    }

  }
}

void printRightBoundary(Node* root)
{
  if (root)
  {

    if (root->right)
    {
      printRightBoundary(root->right);
      cout << root->data << " ";
    }

    else if (root->left)
    {
      printRightBoundary(root->left);
      cout << root->data << " ";
    }

  }
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
  root->right->right = new Node(10);
  root->right->right->right = new Node(14);

  printLeftBoundary(root);

  printLR(root);

  printRightBoundary(root);

  return 0;
}
