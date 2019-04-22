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
  int t;
  cin >> t;
  while (t>0)
  {
    ll n,a,b,x,y,z,temp;
    cin >> n >> a >> b >> x >> y >> z;
    //set<ll, greater<ll> > c;
    priority_queue<ll> c;
    fori(i,1,n)
    {
      cin >> temp;
      c.push(temp);
    }

    ll d2 = (z-b)/y;
    if ((z-b)%y == 0)
      d2 = (z-b)/y - 1;
    else
      d2 = (z-b)/y;


    ll ans = a + d2*x;
    ll rem = z-ans;
    if (rem < 0)
    {
      cout << 0 << endl;
      t-=1;
      continue;
    }


    else
    {
        ll contrib = 0 ;
        ll tatti = 0 ;
        while (!c.empty() && tatti < rem)
        {
          // tatti += *(c.begin());
          // temp = *(c.begin());
          // c.erase(c.begin());
          // if (temp/2 > 0)
          //   c.insert(temp/2);
          tatti += c.top();
          temp = c.top();
          c.pop();
          if (temp/2 > 0)
            c.push(temp/2);
          contrib += 1;
        }

        if (tatti >= rem)
        {
          cout << contrib << endl;
          t-=1;
          continue;
        }
        else if (c.empty() && tatti < rem)
        {
          cout << "RIP" << endl;
          t-=1;
          continue;
        }
    }
    t-=1;
  }
  return 0;
}
