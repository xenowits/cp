#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define ll long long int
#define ld long long double
#define vi vector<long long int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(i = (a); i < (n); i++)
#define fi(i,a,n) for(i = (a); i <= (n); i++)
#define F first
#define S second
ll p = 1000000007;

ll ans = -1;
vector<int> a(10,0);

void solve(int v, vector<int> vec)
{
    //cout << "aa gya " << v << endl;
    if (v <= 0)
    {
        ll temp = 0, cnt = 1;
        sort(vec.begin(),vec.end());
        for(int x : vec)
        {
          temp += x*cnt;
          cnt *= 10;
          //cout << x << " ";
        }
        //cout << temp << endl;
        if (temp > 0)
          ans = max(ans,temp);
        return;
    }
    for(int i = 1; i <= 9; ++i)
    {
        if (v >= a[i])
        {
            vec.pb(i);
            solve(v-a[i],vec);
            vec.pop_back();
        }
    }
}

int main()
{
    int v;
    cin >> v;

    for(int i = 1; i < 10; ++i)
        cin >> a[i];

    vector<int> vec;
    solve(v,vec);
    cout << ans << endl;
}
