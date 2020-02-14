//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define fs first
#define sc second

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  srand(time(0));
  int n = 50;
  fori(i,1,n) {
    int x = (rand()*100+1000)%1000;
    int y = (rand()*100+1000)%1000;
    cout << x << " " << y << endl;
    int temp1 = (x|y)-y;
    int temp2 = x-(x^y);
    if (temp1 != temp2) {
      cout << "YES dikkt h" << endl;
    }
  }

  return 0;
}
