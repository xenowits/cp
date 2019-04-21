#include <bits/stdc++.h>
using namespace std;

#define fori(i, a, b) for (long int i = a; i <= b; ++i)
#define ford(i, a, b) for (long int i = a; i >= b; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

class Node{
public:
  int x,y;
  vector<double> dist;
  Node()
  {
      dist.resize(11);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 500;
  ofstream ss;
  ss.open("testdata.txt", std::ios::app);
  mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
  vector<pair<double,int> > temp;
  vector<int> final;
  fori(i,1,t)
  {
    vector<Node> v(11);
    fori(j,1,10)
    {
      int x = std::uniform_int_distribution<int>(1,20)(rng);
      int y = std::uniform_int_distribution<int>(1,20)(rng);
      v[j].x = x;
      v[j].y = y;
    }
    fori(j,1,10)
    {
      fori(k,1,10)
      {
        if (j == k)
        {
            v[j].dist[k] = 0;
          continue;
        }
        int a = v[j].x;
        int b = v[j].y;
        int c = v[k].x;
        int d = v[k].y;
        v[j].dist[k] = exp((sqrt((c-a)*(c-a)+(d-b)*(d-b)))/5);
      }
    }
    if (i == 1){
    fori(j,2,10)
    {
      temp.pb(mk(v[1].dist[j],j));
    }
    sort(temp.begin(),temp.end());
    // cout << "FIRST WHITEWALKERS" << endl;
    // for(auto a : temp)
    //   cout << a.first << " " << a.second << endl;
    // cout << endl;
    fori(j,0,4)
    {
        final.pb(temp[j].second);
    }
  }
    fori(j,1,10)
    {
      // cout << "node " << j << " ";
      fori(k,1,10)
      {
        ss << v[j].dist[k] << " ";
      }
      ss << endl;
    }
    ss << endl;
  }
  ss << final.size() << endl;
  for(int x : final)
    ss << x-1 << " ";
  ss << endl;
  ss.close();
  return 0;
}
