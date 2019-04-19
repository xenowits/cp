#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  string ac = "ACTG";
  cin >> s;
  vector<long> v;
  fori(i,0,n-1)
  {
    int cnt = -1,cost = 0;
    // for (int j = i ;;j+=1)
    // {
    //   j = j%n;
    //   cost += abs( int(s[j])%26 - int(ac[cnt])%26 );
    //   cnt += 1;
    //   cout << "cost " << s[j] << ac[cnt] << cnt << " " << abs( int(s[j])%26 - int(ac[cnt])%26 ) << endl;
    //   if (cnt == 4)
    //     break;
    // }
    int a = i;
    int b = (i+1)%n;
    int c = (i+2)%n;
    int d = (i+3)%n;
    cost += min ( abs( int(s[a])%26 - int(ac[0])%26 ) , int(s[a])%26);
    cost += abs( int(s[b])%26 - int(ac[1])%26 );
    cost += abs( int(s[c])%26 - int(ac[2])%26 );
    cost += abs( int(s[d])%26 - int(ac[3])%26 );
    cout << cost << " ";
    v.pb(cost);
  }
  sort(v.begin(),v.end());
  cout << v[0];
  return 0;
}
