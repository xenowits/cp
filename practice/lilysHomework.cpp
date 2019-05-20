#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,temp;
  cin >> n;
  vector<pair<ll,ll> > arr(n+1);
  vector<ll> permutation(n+1),psecond(n+1);
  fori(i,1,n)
  {
      cin >> temp;
      arr[i] = mk(temp,i);
  }
  sort(arr.begin()+1,arr.end());
  fori(i,1,n)
  {
    permutation[arr[i].second] = i;
    //cout << arr[i].first << " " << arr[i].second << endl;
  }
  //checking for increasing sorted
  // fori(i,1,n)
  //   cout << permutation[i] << " ";
  int no_of_swaps = 0;
  vector <int> visited(n + 1, false);
  for(int i = 1; i <= n; i++)
  {
      if(!visited[i])
      {
          int cycle_size = 0;

          for(int current = i; !visited[current]; current = permutation[current])
          {
              visited[current] = true;
              cycle_size++;
          }

          no_of_swaps += cycle_size - 1;
      }
  }
  ll a = no_of_swaps;
  // now checking for decreasing sorted
  fori(i,1,n)
    psecond[i] = permutation[n+1-i];
  no_of_swaps = 0;
  vector <int> visited1(n + 1, false);
  for(int i = 1; i <= n; i++)
  {
      if(!visited1[i])
      {
          int cycle_size = 0;

          for(int current = i; !visited1[current]; current = psecond[current])
          {
              visited1[current] = true;
              cycle_size++;
          }

          no_of_swaps += cycle_size - 1;
      }
  }
  ll b = no_of_swaps;
  cout << min(a,b);
  return 0;
}
