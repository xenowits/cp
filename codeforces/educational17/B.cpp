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
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b,c;
  cin>>a>>b>>c;
  ll m;
  cin>>m;
  vector<ll>usb;
  vector<ll>ps2;
  for(ll i=0;i<m;i++)
  {
    ll d;
    string str;
    cin>>d;
    // cout << endl;
    getline(cin,str);

    // cin>>d>>str;
    // cout<<str<<endl;
    if(str[1]=='U')
    {
      usb.pb(d);
    }
    else
    ps2.pb(d);
  }
  sort(usb.begin(),usb.end());
  sort(ps2.begin(),ps2.end());
  ll i,j;
  ll n,k;
  i = 0;
  j = 0;
  n = usb.size();
  k = ps2.size();
  // cout<<n<<" "<<k<<endl;
  ll total = 0;
  ll count = 0;
  // while((i<n and j<k) and (a>0 or b>0 or c>0))
  // {
  //   if(usb[i]<=ps2[j] and (a>0 or c>0))
  //   {
  //     total+=usb[i];
  //     count++;
  //     i++;
  //     if(a)
  //     a--;
  //     else
  //     c--;
  //   }
  //   else if(usb[i]>=ps2[j] and (b>0 or c>0))
  //   {
  //     total+=ps2[j];
  //     count++;
  //     j++;
  //     if(b)
  //     b--;
  //     else
  //     c--;
  //   }
  // }
  // while (i<n and (a>0 or c>0)) {
  //   if(a>0 or c>0)
  //   {
  //     total+=usb[i];
  //     count++;
  //     i++;
  //     if(a)
  //     a--;
  //     else
  //     c--;
  //   }
  //   /* code */
  // }
  // while(j<k and (b>0 or c>0))
  // {
  //   if(b>0 or c>0)
  //   {
  //     total+=ps2[j];
  //     count++;
  //     j++;
  //     if(b)
  //     b--;
  //     else
  //     c--;
  //   }
  // }
  for(;i<n;i++)
  {
    if(a)
    {
      total+=usb[i];
      count++;
      a--;
    }
    else
    break;
  }
  for(;j<k;j++)
  {
    if(b)
    {
      total+=ps2[j];
      count++;
      b--;
    }
    else
    break;
  }
  // cout<<i<<" "<<j<<endl;
  // cout<<a<<" "<<b<<" "<<c<<endl;
  // cout<<a
  while(i<n and j<k and c>0)
  {
    if(usb[i]<=ps2[j])
    {
      total+=usb[i];
      i++;
      count++;
      c--;
    }
    else
    {
      total+=ps2[j];
      j++;
      count++;
      c--;
    }
  }
  while(i<n and c>0)
  {
    total+=usb[i];
    i++;
    count++;
    c--;
  }
  while(j<k and c>0)
  {
    total+=ps2[j];
    j++;
    count++;
    c--;
  }
  // cout<<a<< " "<<b<<" "<<c<<endl;
  cout<<count<<" "<<total<<endl;

  return 0;
}
