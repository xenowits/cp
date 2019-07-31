#include <iostream>
#include<queue>

using namespace std;

class Node{
public:
  int data, dist;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    left = NULL, right = NULL;
  }
};

void levelOrder(Node *root)
{
  queue<Node*> q;
  q.push(root);
  while (!q.empty())
  {
    int sz = q.size();bool cnt = 0;
    for(int i = 1 ; i <= sz ; ++i)
    {
      Node *temp = q.front();
      // if (!cnt)
      // {
      //   cout << temp->data << " ";
      //   cnt = 1;
      // }
      // if (i == sz)
      // {
      //   cout << temp->data << " ";
      // }
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
      q.pop();
    }
  }
}

void topview(Node *root)
{
  queue<Node*> q;
  q.push(root);
  while (!q.empty())
  {
    int sz = q.size();bool cnt = 0;
    for(int i = 1 ; i <= sz ; ++i)
    {
      Node *temp = q.front();
    }
  }
}

int main()
{
  Node *root = new Node(4);
  root->dist = 0;
  root->left = new Node(5);
  root->right = new Node(2);
  root->right->left = new Node(3);
  root->right->right = new Node(1);
  root->right->left->left = new Node(6);
  root->right->left->right = new Node(7);

  levelOrder(root);

  return 0;
}
