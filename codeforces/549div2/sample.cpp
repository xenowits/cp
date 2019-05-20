#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int setBitNumber(int n)
{
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;

    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> x;
  vector<ll> v;
  //int count = 0;
  if (((x-1)&x) == 0)
  {
    cout << 1 << endl << x-1;
    return 0;
  }
  while ( (x&(x+1)) != 0)
  {
    //cout << "xx " << (x&(x+1)) << endl;
    long temp = (int)log2(setBitNumber(x));
    //cout << "temp " << temp+1 << endl;
    long sex = (int)pow(2,temp+1) - 1;
    v.pb(temp+1);
    x = x^sex;
    x+=1;
    //cout << x <<endl;
    // count += 1;
    // if (count == 3)
    //   break;
  }
  cout << v.size() << endl;
  for (int x : v)
    cout << x << " ";
  return 0;
}
