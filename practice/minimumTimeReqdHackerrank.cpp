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
#define fs first
#define sc second

vector<long> machines(100005);
ll n,goal;

// Complete the minTime function below.

ll giveSum(ll num)
{
    ll ans = 0;
    for(int i = 0 ; i < n; i++)
    {
      //cout << machines[i] << " kya h" << endl;
      ans += num/machines[i];
    }
    return ans;
}

long minTime()
{
    // use binary search
    ll l = 1, h = (ll)1e18, mid, temp;
    while (l < h)
    {
        mid = l + (h-l)/2;
        temp = giveSum(mid);
        if (temp == goal)
            h = mid;
        else if (temp > goal)
            h = mid-1;
        else if (temp < goal)
            l = mid+1;
        //cout << l << " " << h << " " << temp << " " << mid << endl;
    }
    // if (l == h && giveSum(l) == goal)
    //     cout <<  "bs is nice" << endl;
    return l;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> goal;
  fori(i,0,n-1)
    cin >> machines[i];
  cout << minTime();
  return 0;
}
