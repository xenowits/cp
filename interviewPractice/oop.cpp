#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define fs first
#define sc second

class MNC{
public:
  //int kyah;
  MNC()
  {
    //kyah = 8;
    cout << "hi i am mnc" << endl;
  }
};

class BRANCH : private MNC
{
  int brapri;
public:
  int branch_hello;
  BRANCH()
  {
    cout << "Hello i am branch" << endl;
    brapri = 90;
  }
  void add()
  {
    cout << "hi i am add function and brapri is " << brapri << endl;
  }
};

class OUTLET : public BRANCH
{
public:
  int outlet_hello;
  OUTLET()
  {
    cout << "aur bhai kaisa h" << endl;
    outlet_hello = 94;
  }
  void outlet_func() const
  {
    cout << "outlet ka hi to function h";
  }
};

class EMPTY{};
// void OUTLET

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const OUTLET x;
  x.outlet_func();

  BRANCH y;

  cout << "size of object x is " << sizeof(x) << endl;
  cout << "size of object y is " << sizeof(y) << endl;
  //cout << x.kyah << endl;
  const EMPTY z;
  cout << "size of z is " << sizeof (z) << endl;
  return 0;
}
