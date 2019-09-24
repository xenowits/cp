#include <bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[200005];

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

struct offer{
  int x,y;
  ll w;
};

vector<offer> o;

int main()
{
  // makeSet(5);
  // makeSet(8);
  // makeSet(56);
  //
  // Union(5,8);
  // Union(8,56);
  //
  // cout << findSet(56);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  ll a,b,c;
  vector<ll> v(n+1);
  fori(i,1,n)
    cin >> v[i];

  fori(i,1,m)
  {
    cin >> a >> b >> c;
    offer temp;
    temp.x = a, temp.y = b, temp.w = c;
    o.pb(temp);
  }

  sort(o.begin(), o.end(), [](const offer a, const offer b){
    return a.w < b.w;
  });

  ll ans = 0;

  fori(i,1,n)
    makeSet(i);

  for(auto p : o)
  {
    a = p.x, b = p.y, c = p.w;
    cout << c << " c h offer wala" << endl;
    if (findSet(a) != findSet(b) && v[a]+v[b] > c)
    {
      Union(a,b);
      ans += c;
    }
  }

  // now offers done with, now make connected graph
  set<int> rep;
  fori(i,1,n)
  {
    a = findSet(i);
    adj[a].pb(i);
    rep.insert(a);
  }

  if (rep.size() == 1)    //already connected
  {
    cout << ans << " ac" << endl;
    exit(0);
  }

  vector<ll> min_v;
  for(int p : rep)
  {
    ll minima = v[p];
    for(int q : adj[p])
      minima = min(minima,v[q]);
    min_v.pb(minima);
  }

  sort(min_v.begin(),min_v.end());
  c = min_v[0];
  fori(i,1,min_v.size()-1)
  {
    ans += (min_v[i]+c);
  }

  cout << ans << endl;

  return 0;
}
