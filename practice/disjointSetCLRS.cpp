#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<ctime>
#include<deque>
#include<set>
#include<map>
#include<iterator>
#include<climits>
using namespace std;

class Node{
public:
  long data, rank;
  Node* parent;
};

map<long,Node*> m;

void makeSet(long a)
{
  Node* node = new Node();
  node->data = a;
  node->rank = 0;
  node->parent = node;
  m[a] = node;
}

void link(Node* a, Node* b)
{

  if (a->rank > b->rank)
    b->parent = a;
  else
  {

    a->parent = b;

    if (a->rank == b->rank)
      b->rank += 1;
  }
}


Node* findSet(Node *a)
{

  if (a != a->parent)
    a->parent = findSet(a->parent);

  return a->parent;
}

void Union(long a, long b)
{

  Node *node1 = m[a];
  Node *node2 = m[b];

  link(findSet(node1),findSet(node2));

}

long findSet(long a)
{
    return (findSet(m[a]))->data;
}

int main()
{
  makeSet(5);
  makeSet(8);
  makeSet(56);

  Union(5,8);
  Union(8,56);

  cout << findSet(56);

  return 0;
}
