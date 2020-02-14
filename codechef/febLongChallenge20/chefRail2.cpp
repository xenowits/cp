#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100005
#define MAX5 100000
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

// vector<ll> divisors[MAXN];
vector<bool> negX(MAXN,0), posX(MAXN,0), posY(MAXN,0), negY(MAXN,0);

void resizer() {
  negX.clear();
  negX.resize(MAXN,0);
  posX.clear();
  posX.resize(MAXN,0);
  negY.clear();
  negY.resize(MAXN,0);
  posY.clear();
  posY.resize(MAXN,0);
}

void calcDivisors2(ll n, vector<ll> &divisors) {
  divisors.pb(1);
  for (ll j = 2; j*j <= n; j++) {
    if (n%j == 0) {
      divisors.pb(j);
      if (j*j != n) {
        divisors.pb(n/j);
      }
    }
  }
  if (n != 1)
    divisors.pb(n);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    ll n, m, ans = 0, x, y, temp1, temp2;
    cin >> n >> m;
    bool originX = false, originY = false;
    vector<ll> xPoints, yPoints;
    fori(i,1,n) {
      //input the x co-ordinates
      cin >> x;
      if (x == 0) {
        originX = true;
      } else if (x > 0) {
        posX[x] = 1;
      } else {
        negX[x+MAX5] = 1;
      }
      if (x != 0)
        xPoints.pb(x);
    }
    fori(i,1,m) {
      //input the y co-ordinates
      cin >> y;
      if (y == 0) {
        originY = true;
      } else if (y > 0) {
        posY[y] = 1;
      } else {
        negY[y+MAX5] = 1;
      }
      if (y != 0)
        yPoints.pb(y);
    }
    //Iterate through the xPoints first
    for (auto xpt : xPoints) {
      vector<ll> divisors;
      calcDivisors2(max(-xpt,xpt), divisors);

      for (auto divs : divisors) {
        temp1 = xpt/divs;
        temp2 = -xpt*divs;
        if (xpt > 0) {
          //temp1 is positive and temp2 is negative
          if (temp2+MAX5 < MAXN && posY[temp1] && negY[temp2+MAX5]) {
            // cout << temp1 << " xb " << temp2 << endl;
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is negative and temp2 is positive
          if (temp1+MAX5 < MAXN && abs(temp1) != abs(temp2) && posY[temp2] && negY[temp1+MAX5]) {
            // cout << temp1 << " xb " << temp2 << endl;
            ans += 1;
          }
        } else {
          //temp1 is negative and temp2 is positive
          if (temp1+MAX5 < MAXN && negY[temp1+MAX5] && posY[temp2]) {
            // cout << temp1 << " xc " << temp2 << endl;
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is positive and temp2 is negative
          if (temp2+MAX5 < MAXN && abs(temp1) != abs(temp2) && negY[temp2+MAX5] && posY[temp1]) {
            // cout << temp1 << " xc " << temp2 << endl;
            ans += 1;
          }
        }
      }
    }
    //Now iterate through the yPoints
    for (auto ypt : yPoints) {
      vector<ll> divisors;
      calcDivisors2(max(-ypt,ypt), divisors);
      for (auto divs : divisors) {
        temp1 = ypt/divs;
        temp2 = -ypt*divs;
        if (ypt > 0) {
          //temp1 is positive and temp2 is negative
          if (temp2+MAX5 < MAXN && posY[temp1] && negY[temp2+MAX5]) {
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is negative and temp2 is positive
          if (temp1+MAX5 < MAXN && abs(temp1) != abs(temp2) && posY[temp2] && negY[temp1+MAX5]) {
            ans += 1;
          }
        } else {
          //temp1 is negative and temp2 is positive
          if (temp1+MAX5 < MAXN && negY[temp1+MAX5] && posY[temp2]) {
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is positive and temp2 is negative
          if (temp2+MAX5 < MAXN && abs(temp1) != abs(temp2) && negY[temp2+MAX5] && posY[temp1]) {
            ans += 1;
          }
        }
      }
    }
    //Output the answer
    if (originX) {
      cout << ans+m*(n-1) << endl;
    } else if(originY) {
      cout << ans+(m-1)*n << endl;
    } else {
      cout << ans << endl;
    }
    //resize the vectors
    resizer();
  }

  return 0;
}
