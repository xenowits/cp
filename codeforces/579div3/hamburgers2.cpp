#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;
  int reg[3] = {0};

  for(int i =  0; i < str.length(); ++i)
  {
    if (str[i] == 'B')
      reg[0] += 1;
    else if (str[i] == 'S')
      reg[1] += 1;
    else if (str[i] == 'C')
      reg[2] += 1;
  }

  int n[3], p[3];
  ll r;

  cin >> n[0] >> n[1] >> n[2];
  cin >> p[0] >> p[1] >> p[2];

  cin >> r;
  ll right = 10000000000000000, left = 0;
  while (left < right)
  {
    ll mid = left + (right-left)/2;
    ll req = 0, temp;
    for(int i = 0 ; i<3; ++i)
    {
      //kab cost ayega -- jb kharidna pade
      if (mid*reg[i] >= n[i])
        temp = (mid*reg[i]-n[i])*p[i];
      else
        temp = 0;
      req += temp;
    }
    if (req <= r)
      left = mid;
    else
      right = mid-1;
    if (right-left == 1)
      break;
  }
  ll req = 0;
  for(int i = 0 ; i<3; ++i)
  {
    //kab cost ayega -- jb kharidna pade
    ll temp = 0;
    if (right*reg[i] >= n[i])
      temp = (right*reg[i]-n[i])*p[i];
    req += temp;
  }
  if (req <= r)
    cout << right << endl;
  else
    cout << left << endl;
  return 0;
}
