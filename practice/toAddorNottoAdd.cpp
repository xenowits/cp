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

ll oc,no;

//binary search on length

void solver(ll oc_temp, ll no_temp)
{
  if (oc_temp > oc)
  {
    no = no_temp;
    oc = oc_temp;
  }
  else if (oc_temp == oc && no > no_temp)
  {
    no = no_temp;
  }
}

void func(int n, vector<ll> pre, int indx, ll k, ll a)
{
  int low = 0, high = indx;
  ll temp;
  int mid = (low+high)/2;
  //cout << "re ka ho gelau" << endl;
  while (low < high)
  {
    //cout << low << " " << mid << " " << high << " are the values" << endl;
    mid = (low+high)/2;
    if (mid == 0)
    {
      temp = a*(indx+1) - pre[indx];
      //cout << "awala prewala mid when 0 " << a*(indx-mid+1) << " " << mid << endl;
    }
    else
    {
      temp = a*(indx-mid+1) - (pre[indx] - pre[mid-1]);
      //cout << "awala prewala mid " << a*(indx-mid+1) << " " << pre[indx]-pre[mid-1] << " " << mid << endl;
    }
    //cout << temp << " hi temp h " << mid << " " << indx << endl;
    if (temp < k)    //// mid+1 to high ka sum
      high = mid;
    else if (temp > k)     ////
      low = mid+1;
    else if (temp == k)
    {
      //cout << low << " a " << mid << " " << high << " " << indx << " " << a << endl;
      solver(indx-mid+1,a);
      //cout << oc << " oc and no " << no << endl;
      high = mid;
    }
    //break;
    //cout << temp << " " << low << " is low " << high << " is high and mid is " << mid << endl;
  }
  //cout << low << " " << high << " " << indx << " " << a << endl;
  // if (low < high)
  // {
  //   while (temp == 0)
  //   {
  //
  //   }
  // }
  solver(indx-low+1,a);
  //cout << "kya dekhte ho ji" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> pre(n);
  fori(i,0,n-1)
    cin >> a[i];
  sort(a.begin(),a.end());
  fori(i,0,n-1)
  {
    if (i == 0)
      pre[i] = a[i];
    else
      pre[i] = a[i] + pre[i-1];
  }
  // for (int i : a)
  //   cout << i << " ";
  // cout << endl;
  // for(int i : pre)
  //   cout << i << " ";
  // cout << endl;
  ///here we can binary search on number of elements and that's really cool
  /// so basically i think i should write a utility function for this
  fori(i,1,n-1)
    func(n,pre,i,k,a[i]);
  cout << oc << " " << no << endl;
  return 0;
}
