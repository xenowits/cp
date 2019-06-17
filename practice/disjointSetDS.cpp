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
  long data;
  Node *parent;
  long rank;
};

vector<Node* > v(100001);

void makeSet(long data)
{
  Node* node = new Node();
  node->data = data;
  node->parent = node;
  node->rank = 0;
  v[data] = node;
}

Node* findSet(Node *node)
{
  Node* parent = node->parent;
  if (parent == node)
    return parent;
  node->parent = findSet(node->parent);
  return node->parent;
}

long findSet(long data)
{
  return findSet(v[data])->data;
}

bool Union(long data1, long data2)
{
  Node* node1 = v[data1];
  Node* node2 = v[data2];

  Node* parent1 = findSet(node1);
  Node* parent2 = findSet(node2);

  if (parent1->data == parent2->data)
    return false;

  if (parent1->rank >= parent2->rank)
  {
    parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1 : parent1->rank;
    parent2->parent = parent1;
  }
  else
    parent1->parent = parent2;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  makeSet(5);
  cout << v[5]->data << endl;
  makeSet(1);
  makeSet(2);
  makeSet(3);
  makeSet(4);
  makeSet(5);
  makeSet(6);
  makeSet(7);

  Union(1, 2);
  Union(2, 3);
  Union(4, 5);
  Union(6, 7);
  Union(5, 6);
  Union(3, 7);

  cout << findSet(1) << endl;
  cout << findSet(2) << endl;
  cout << findSet(3) << endl;
  cout << findSet(4) << endl;
  cout << findSet(5) << endl;
  cout << findSet(6) << endl;
  cout << findSet(7) << endl;
  cout << findSet(8) << endl;
  cout << findSet(9) << endl;

  return 0;
}
