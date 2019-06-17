#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

long selectAct(vector<pair<int,int> > v)
{
// Vector to store results.
    vector<pair<int,int>>ans;

// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]).

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;

    for(int i=0;i<v.size();i++){
        // Pushing elements in priority queue where the key is f[i]
        int a = v[i].first;
        int b = v[i].second;
        p.push(mk(b,a));
    }

    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start,end));

    while(!p.empty())
    {
        auto itr = p.top();
        p.pop();
        if(itr.second > end)
        {
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    return ans.size();
    cout << "Following Activities should be selected. " << endl << endl;

    for(auto itr=ans.begin();itr!=ans.end();itr++){
        cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> arr(n+1), prefixSum(n+1,0);
  fori(i,1,n)
  {
      cin >> arr[i];
      prefixSum[i] = arr[i] + prefixSum[i-1];
  }
  vector<pair<int,int> > ans[100001];
  fori(i,1,n)
  {
      fori(j,i,n)
      {
          ll sum = prefixSum[j] - prefixSum[i-1];
          ans[sum].pb(mk(i,j));
      }
  }
  priority_queue<pair<int,int> > pq;
  fori(i,1,100000)
  {
      if (!ans[i].empty())
      {
        //cout << i << " is the i ";
        // for(auto x : ans[i])
        // {
        //   cout << x.first << " " << x.second << " ";
        // }
        vector<pair<int,int> > sometemp = ans[i];
        int temp = selectAct(sometemp);
        pq.push(mk(temp, i));
      }
      //cout << endl;
  }
  int temp = pq.top().first;
  cout << temp << endl;
  priority_queue<int, vector<int> , greater<int> > finalPq;
  while(temp == pq.top().first)
  {
    //cout << pq.top().second << " ";
    finalPq.push(pq.top().second);
    pq.pop();
  }
  while(!finalPq.empty())
  {
    cout << finalPq.top() << " ";
    finalPq.pop();
  }
  // cout << endl;
  // for(auto x : ans[105])
  //   cout << x.first << " " << x.second << " ";
  return 0;
}
