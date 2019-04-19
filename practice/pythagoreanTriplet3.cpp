#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d;
    cin >> n;
    ll max_abc = -1;
    fori(i,1,n)
    {
      fori(j,i+1,n)
      {
        fori(k,j+1,n)
        {
          d = i*j*k;
          if (i*i + j*j == k*k && i+j+k == n)
          {
              cout << i << " " << j << " " << k << endl;
              if (d > max_abc)
                max_abc = d;
          }
        }
      }
    }
    cout << max_abc;
    int a = 20;
    fori(i,1,100)
    {
      fori(j,i+1,100)
      {
        if (400 == j*j - i*i)
          cout << a << " "<< i << " " << j << endl;
      }
    }
    return 0;
}
