#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x,y;
    cin >> x >> y;
    if (y*log(x) > x*log(y))
      cout << ">";
    else if (y*log(x) == x*log(y))
      cout << "=";
    else
      cout << "<";
    return 0;
}
