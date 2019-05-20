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
  int k;
  cin >> k;
  if (k < 25)
  {
    cout << -1;
    return 0;
  }
  vector<ll> divisors;
  for(int i = 5; i*i <= k; ++i)
  {
    if (k%i == 0 && k/i >= 5)
      divisors.pb(i);
    if (divisors.size())
      break;
  }
  if (divisors.size() == 0)
    cout << -1;
  else
  {
    ll temp = divisors[0];
    char arr[temp][k/temp];
    vector<char> vowels = {'a','e','i','o','u'};
    fori(i,0,4)
    {
      fori(j,0,4)
        arr[i][j] = vowels[j];
      std::rotate(vowels.begin(), vowels.begin()+1, vowels.end());
    }
    // for(auto l : vowels)
    //   cout << l << " ";
    //cout << endl;
    fori(j,5,k/temp-1)
    {
      fori(i,0,4)
      {
        arr[i][j] = vowels[i];
      }
    }
    fori(i,5,temp-1)
    {
      fori(j,0,4)
      {
        arr[i][j] = vowels[j];
      }
    }
    fori(i,5,temp-1)
    {
      fori(j,5,k/temp-1)
      {
        arr[i][j] = 'a';
      }
    }
    fori(i,0,temp-1)
    {
      fori(j,0,k/temp-1)
      {
        cout << arr[i][j];
      }
      //cout << endl;
    }
  }
  return 0;
}
