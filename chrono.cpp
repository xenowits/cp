#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  //auto star = chrono::high_resolution_clock::time_since_epoch;
  // chrono::time_point<chrono::high_resolution_clock> start,end;
  // start = chrono::high_resolution_clock::now();
  srand(time(0));
  cout << rand()%10+1;

  mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
  chrono::high_resolution_clock::time_point tp = chrono::high_resolution_clock::now();
  for (long int i = 0 ; i < 109288445; ++i)
  {
    i+=0;
  }
  chrono::high_resolution_clock::time_point tp2 = chrono::high_resolution_clock::now();
  chrono::high_resolution_clock::duration dtn = tp2 - tp;
  chrono::high_resolution_clock::duration dd = tp2.time_since_epoch();
  cout << dtn.count() << endl;
  cout << dd.count() << endl;
  vector<int> v;
  for (int i = 1; i <= 9; ++i)
  {
      v.push_back(std::uniform_int_distribution<int>(0,9)(rng));
  }
  for (unsigned int i = 0 ; i < v.size() ; ++i)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  std::shuffle (v.begin() , v.end(),  rng);
  for (int i = 0 ; i < v.size() ; ++i)
  {
    cout << v[i] << " ";
  }
  return 0;
}
