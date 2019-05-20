#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

struct Prod{
  int product;
  int a,b;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // Prod arr[16];
  // arr[1].product = 32; arr[1].a = 4; arr[1].b = 8;
  // arr[1].product = 60; arr[1].a = 4; arr[1].b = 15;
  // arr[1].product = 64; arr[1].a = 4; arr[1].b = 16;
  // arr[1].product = 92; arr[1].a = 4; arr[1].b = 23;
  // arr[1].product = 168; arr[1].a = 4; arr[1].b = 42;
  // arr[1].product = 120; arr[1].a = 8; arr[1].b = 15;
  vector<Prod> v;
  vector<int> a = {4,8,15,16,23,42};
  vector<int> permutation(7);
  fori(i,0,5)
  {
    fori(j,i+1,5)
    {
      int temp = a[i]*a[j];
      Prod obj;
      obj.a = a[i];obj.b = a[j];obj.product = temp;
      v.pb(obj);
    }
  }
  cout << "? 1 2" << endl;
  int a12,a45,a23,a34,A1,A2,B1,B2,C1,C2,D1,D2;
  cin >> a12;
  for(auto x : v)
  {
    if (x.product == a12)
    {
      A1 = x.a; B1 = x.b;
      A2 = x.b; B2 = x.a;
      break;
    }
  }
  cout << "? 4 5" << endl;
  cin >> a45;
  for (auto x : v)
  {
    if (x.product == a45)
    {
      C1 = x.a; D1 = x.b;
      C2 = x.b; D2 = x.a;
      break;
    }
  }
  cout << "? 2 3" << endl;
  cin >> a23;
  fflush(stdout);
  cout << "? 3 4" << endl;
  cin >> a34;
  fflush(stdout);
  for (auto x : v)
  {
    if (x.product == a23)
    {
      int t1, t2;
      t1 = x.a;t2 = x.b;
      if (t1 == B1 || t1 == B2)
      {
        permutation[2] = t1;
        permutation[3] = t2;
      }
      if (t2 == B1 || t2 == B2)
      {
        permutation[2] = t2;
        permutation[3] = t1;
      }
      break;
    }
  }
  for (auto x : v)
  {
    if (x.product == a34)
    {
      int t1, t2;
      t1 = x.a;t2 = x.b;
      if (t1 == C1 || t1 == C2)
      {
        permutation[4] = t1;
      }
      if (t2 == C1 || t2 == C2)
      {
        permutation[4] = t2;
      }
      break;
    }
  }
  permutation[1] = a12/permutation[2];
  permutation[5] = a45/permutation[4];
  fori(i,0,5)
  {
    int temp = a[i];
    bool found = false;
    fori(i,1,5)
    {
      if (permutation[i] == temp)
        found = true;
    }
    if (!found)
    {
      permutation[6] = temp;
      break;
    }
  }
  cout << "! ";
  fori(i,1,6)
  {
    cout << permutation[i] << " ";
  }
  return 0;
}
