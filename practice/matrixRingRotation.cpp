#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int a[500][500];
vector<int> v[300];
int pos = 0;

void spiralPrint(int m, int n, int r)
{
    int M = m, N = n;
    int i, k = 0, l = 0;

    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n)
    {
        vector<int> temp;
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            //cout<<a[k][i]<<" ";
            v[pos].pb(a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            //cout<<a[i][n-1]<<" ";
            v[pos].pb(a[i][n-1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                //cout<<a[m-1][i]<<" ";
                v[pos].pb(a[m-1][i]);
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                //cout<<a[i][l]<<" ";
                v[pos].pb(a[i][l]);
            }
            l++;
        }
        pos += 1;
        //cout << endl;
    }
    vector<ll> ans;
    fori(i,0,300)
    {
      if (!v[i].empty())
      {
        int rotations = r%v[i].size();
        std::rotate(v[i].begin(), v[i].begin()+rotations, v[i].end());
        for(auto x : v[i])
          ans.pb(x);
      }
      else
        break;
    }
    // for(int x : ans)
    //   cout << x << " ";
    // cout << endl;
    pos = 0;
    k = 0, l = 0;
    m = M, n = N;
    while (k < m && l < n)
    {
      //cout << "ghus gya m" << endl;
        /* Insert in the first row from the remaining rows */
        ll someTemp;
        for (i = l; i < n; ++i)
        {
          someTemp = ans[pos];
          pos += 1;
          a[k][i] = someTemp;
          //cout << someTemp << " ";
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            someTemp = ans[pos];
            pos += 1;
            a[i][n-1] = someTemp;
            //cout << someTemp << " ";
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                someTemp = ans[pos];
                pos += 1;
                a[m-1][i] = someTemp;
                //cout << someTemp << " ";
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
              someTemp = ans[pos];
              pos += 1;
              a[i][l] = someTemp;
              //cout << someTemp << " ";
            }
            l++;
        }
        //cout << endl;
    }
    fori(i,0,M-1)
    {
        fori(j,0,N-1)
        {
          cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m,n,r;
  cin >> m >> n >> r;
  fori(i,0,m-1)
    fori(j,0,n-1)
      cin >> a[i][j];
  spiralPrint(m, n, r);
  return 0;
}
