#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void bellmanFord(vector<pair<int,int> > v[], int n, int e,int src)
{
  vector<int> dist(n+1,INT_MAX);
  dist[src] = 0;
  fori(i,1,n-1)
  {
    fori(j,1,n)
    {
      for (auto x : v[j])
      {
        if (dist[j] != INT_MAX && dist[x.first] > dist[j] + x.second)
          dist[x.first] = dist[j] + x.second;
      }
    }
  }
  // negative wt edge check
  fori(j,1,n)
  {
    for (auto x : v[j])
    {
      if (dist[x.first] != INT_MAX && dist[x.first] > dist[j] + x.second)
      {
        cout << "Negative wt cycle re baba\n";
        return;
      }
    }
  }
  cout << "distances from source " << src << endl;
  fori(i,1,n)
    cout << dist[i] << " ";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //cout << "nice" << endl;
  int n,e,src,dest,wt;
  cout << "enter n and e" << endl;
  cin >> n >> e;
  vector<pair<int,int> > v[n+1];
  cout << "src   dest   weight" << endl;
  fori(i,1,e)
  {
    cin >> src >> dest >> wt;
    v[src].pb(mk(dest,wt));
  }
  cout << "give me the fucking source" << endl;
  cin >> src;
  bellmanFord(v,n,e,src);
  return 0;
}
