#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if (a.first == b.first)
    {
        return (a.second > b.second);
    }
    else
        return (a.first < b.first);
}

void solve(int n, long int X, vector<int> nodes[], vector<int> values)
{
  int k = 0;
  ford(i,n,1)
  {
    if (nodes[i].size())
    {
      for(auto x : nodes[i])
      {
        values[i] += values[x];
      }
    }
  }
  long int final = values[1], temp;
  vector<pair<int,int> > v;
  fori(i,2,n)
  {
    v.pb(mk(values[i],i));
  }
  sort(v.begin(),v.end(), sortbysec);
  for (auto x : v)
  {
    cout << x.first << " " << x.second << endl;
  }
  bool doneWith[n+1] = {false};
  long int sumPromise = final, pichlaTemp = final;
  for(auto x : v)
  {
    //cout << "who else is here\n";
    //cout << x.first << " " << x.second;
    // if (!doneWith[x.second])
    // {
    //   //cout << "i am here\n";
    //   k += 1;
    //   sumPromise = sumPromise - x.first;
    //   temp = sumPromise - k*X;
    //   if (temp > pichlaTemp)
    //   {
    //     pichlaTemp = temp;
    //     doneWith[x.second] = true;
    //     for (auto a : nodes[x.second])
    //     {
    //       doneWith[a] = true;
    //     }
    //   }
    //   else
    //     break;
    // }
    if (!doneWith[x.second])
    {
      long int temp = X + values[x.second];
      if (temp < 0)
      {
        //cout << "temp itna h " << temp << endl;
        final = final - temp;
        //cout << "now final " << final << endl;
        doneWith[x.second] = true;
        for (auto a : nodes[x.second])
        {
          doneWith[a] = true;
        }
      }
      else
        break;
    }
  }
  fori(i,1,n)
  {
    if (doneWith[i])
      cout << "ho gya " << i << endl;
    else
      cout << "nhi hua " << i << endl;
  }
  // cout << pichlaTemp;
  cout << final;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,u,v;
  long int x;
  cin >> t;
  while (t>0)
  {
    cin >> n >> x;
    vector<int> nodes[n+1];
    vector<int> values(n+1);
    fori(i,1,n)
    {
      cin >> values[i];
    }
    fori(i,1,n-1)
    {
      cin >> u >> v;
      nodes[u].pb(v);
    }
    solve(n,x,nodes,values);
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}


// 1
// 10 2
// 5 -10 4 7 7 -1 3 8 -5 -3
// 1 2
// 1 3
// 1 4
// 2 5
// 3 8
// 3 9
// 4 10
// 5 6
// 5 7
