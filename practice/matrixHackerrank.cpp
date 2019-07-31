#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define pi pair<int,int>
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define MAXN 100005
#define ll long long int

vector<pair<int, pi> > edges, mst;
vector<bool> color(MAXN,0);

class Node{
public:
  int data, rank;
  Node *parent;
};

map<int, Node*> m;

void makeSet(ll a)
{
  Node *node = new Node();
  node->data = a;
  node->rank = 0;
  node->parent = NULL;
  m[a] = node;
}

Node* findSet(Node *x)
{

  if (x != x->parent)
    x->parent = findSet(x->parent);

  return x->parent;
}

Node* findSet(ll x)
{
  return findSet(m[x]);
}

void link(Node *x, Node *y)
{
  if (x->rank > y->rank)
    y->parent = x;
  else
  {
    x->parent = y;
    if (x->rank == y->rank)
      y->rank += 1;
  }
}

void Union(ll a, ll b)
{
  Node *node1 = m[a];
  Node *node2 = m[b];

  link(findSet(node1), findSet(node2));

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, n, e;
  cin >> n >> e;
  for(int i = 1; i <= e ; ++i)
  {
    cin >> a >> b >> c;
    edges.pb(mk(c, mk(a,b)));
  }

  sort(edges.begin(), edges.end());
  //reverse(edges.begin(), edges.end());
  // makeSet
  for(int i = 1 ; i <= n; ++i)
    makeSet(i);

  int total_edges = 0;

  for(auto p : edges)
  {
    // cout << x.fs << " " << (x.sc).fs << " " << (x.sc).sc << endl;
    int x = (p.sc).fs, y = (p.sc).sc;
    // detect cycle formation
    if (findSet(x) != findSet(y))
    {
      mst.pb(mk(p.fs, mk(x,y)));
      total_edges += 1;
      if (total_edges == n-1)
        break;
    }
    Union(x,y);
  }

  return 0;
}
