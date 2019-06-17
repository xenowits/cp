#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

class disjointSet
{
public:
  class Node{
    ll data;
    Node* parent;
    ll rank;
  }
  map<ll,Node> m;
  void makeSet(ll data)
  {
    Node node = new Node();
    node.data = data;
    node.parent = node;
    node.rank = 0;
    m.insert(data, node);
  }
  bool union(ll data1, ll data2)
  {
    Node node1 = m[data1];
    Node node2 = m[data2];

    Node parent1 = findSet(node1);
    Node parent2 = findSet(node2);

    if (parent1.data == parent2.data)
      return false;

    if (parent1.rank >= parent2.rank)
    {
      parent1.rank = (parent1.rank == parent2.rank) ? parent1.rank+1 : parent2.rank;
      parent2.parent = parent1;
    }
    else
      parent1.parent = parent2;
    return true;
  }
  ll findSet(ll data)
    return findSet(map[data]).data;
  Node findSet(Node node)
  {
    Node parent = node.parent;
    if (parent == node)
      return parent;
    node.parent = findSet(node.parent);
    return node.parent;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  disjointSet ds = new disjointSet();

  ds.makeSet(1);
  ds.makeSet(2);
  ds.makeSet(3);
  ds.makeSet(4);
  ds.makeSet(5);
  ds.makeSet(6);
  ds.makeSet(7);

  ds.union(1, 2);
  ds.union(2, 3);
  ds.union(4, 5);
  ds.union(6, 7);
  ds.union(5, 6);
  ds.union(3, 7);

  cout << ds.findSet(1).data << endl;
  return 0;
}
