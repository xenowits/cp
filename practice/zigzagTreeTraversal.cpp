#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void zigzag(vector<int> t[], int n, int e)
{
  queue<int> q;
  q.push(1);
  vector<bool> visited(n+1,false);
  int count = 1;
  deque<int> stk;
  bool lol = false;
  while (!q.empty())
  {
    int temp = q.front();
    q.pop();count -= 1;
    visited[temp] = true;
    stk.push_back(temp);
    for (auto x : t[temp])
    {
      if (!visited[x])
        q.push(x);
    }
    if (count == 0)
    {
        lol = !lol;
        while(!stk.empty() && lol)
        {
          cout << stk.front() << " ";
          stk.pop_front();
        }
        while(!stk.empty() && !lol)
        {
          cout << stk.back() << " ";
          stk.pop_back();
        }
        cout << endl;
        count = q.size();
        //cout << count << endl;
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,a,b;
    cin >> n >> e;
    vector<int> t[n+1];
    fori(i,1,e)
    {
      cin >> a >> b;
      t[a].pb(b);
      t[b].pb(a);
    }
    zigzag(t,n,e);
    return 0;
}
