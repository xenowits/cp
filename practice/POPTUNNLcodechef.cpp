#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

long solver(int n, int k, vector<string> &v) {
  queue<int> q;
  vector<bool> visited(n+1,false);
  vector<int> distance(n+1,-1);

  q.push(1);
  visited[1] = true;
  distance[1] = 0;
  while(!q.empty()) {
    int s = q.front();
    q.pop();
    string str = v[s];
    fori(i,0,n-1) {
      if (str[i] == '1' && abs(i+1-s) <= k && visited[i+1] == false) {
        distance[i+1] = distance[s]+1;
        q.push(i+1);
        visited[i+1] = true;
        if (i == n-1) {
          return distance[i+1];
        }
      }
    }
  }
  return distance[n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int k, n;
    std::cin >> n >> k;
    vector<string> v(n+1);
    fori(i,1,n) {
      cin >> v[i];
    }
    cout << solver(n,k,v) << endl;
  }

  return 0;
}
