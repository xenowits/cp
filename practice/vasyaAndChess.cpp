#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t)
  {
    cout << "aurrrrrr " << t << endl;
    vector<ll> v(25);
    int n, quadrapleSum;
    cin >> n >> quadrapleSum;
    fori(i,1,n)
      cin >> v[i];
    vector<pi> psum[2001];
    //unordered_map<int,pi> psum;
    quadrapleSum += 1600;
    fori(i,1,n)
    {
      fori(j,i+1,n)
      {
        psum[800+v[i]+v[j]].pb(mk(i,j));
      }
    }
    vector<bool> visited(n+1,false);
    fori(i,0,2001)
    {
      bool truth;
      if (!psum[i].empty() && !psum[quadrapleSum-i].empty() )
      {
        for (auto a : psum[i])
        {
          truth = 0;
          //cout << "done kaise ho" << endl;
          for(auto b : psum[quadrapleSum-i])
          {
            if (!visited[a.first] && !visited[b.first] && !visited[b.second] && !visited[b.first])
            {
              truth = 1;
              visited[a.first] = visited[a.second] = visited[b.first] = visited[b.second] = true;
              vector<int> temp;
              temp.pb(v[a.first]);temp.pb(v[a.second]);temp.pb(v[b.first]);temp.pb(v[b.second]);
              sort(temp.begin(),temp.end());
              for(int x : temp)
                cout << x << " ";
              cout << "$";
              //cout << v[a.first] << " " << v[a.second] << " " << v[b.first] << " " << v[b.second] << endl;
              //break;
            }
          }
        }
      }
    }
    t-=1;
    cout << endl;
  }
  return 0;
}
