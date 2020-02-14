#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100005
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

vector<ll> divisors[MAXN];
vector<bool> negX(MAXN,0), posX(MAXN,0), posY(MAXN,0), negY(MAXN,0);

void resizer() {
  negX.resize(0);
  negX.resize(MAXN,0);
  posX.resize(0);
  posX.resize(MAXN,0);
  negY.resize(0);
  negY.resize(MAXN,0);
  posY.resize(0);
  posY.resize(MAXN,0);
}

void calcDivisors() {
  divisors[1].pb(1);
  fori(i,2,MAXN-4) {
    divisors[i].pb(1);
    for(ll j = 2; j*j <= i; j++) {
      if (i%j == 0) {
        divisors[i].pb(j);
        if (j*j != i) {
          divisors[i].pb(i/j);
        }
      }
    }
    divisors[i].pb(i);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  calcDivisors();

  int t;
  cin >> t;

  // fori(i,1,100) {
  //   cout << i << " ka divisors h" << endl;
  //   for(auto x : divisors[i]) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }
  while (t--) {
    ll n, m, ans = 0, x, y, temp1, temp2;
    cin >> n >> m;
    bool origin = false;
    vector<ll> xPoints, yPoints;
    fori(i,1,n) {
      //input the x co-ordinates
      cin >> x;
      if (x == 0) {
        origin = true;
      } else if (x > 0) {
        posX[x] = 1;
      } else {
        negX[x+100000] = 1;
      }
      if (x != 0)
        xPoints.pb(x);
    }
    fori(i,1,m) {
      //input the y co-ordinates
      cin >> y;
      if (y == 0) {
        origin = true;
      } else if (y > 0) {
        posY[y] = 1;
      } else {
        negY[y+100000] = 1;
      }
      if (y != 0)
        yPoints.pb(y);
    }
    //Iterate through the xPoints first
    for (auto xpt : xPoints) {
      // cout << xpt << " is the xpoint" << endl;
      for (auto divs : divisors[max(-xpt,xpt)]) {
        temp1 = xpt/divs;
        temp2 = -xpt*divs;
        if (xpt > 0) {
          //temp1 is positive and temp2 is negative
          if (posY[temp1] && negY[temp2+100000]) {
            // cout << temp1 << " xb " << temp2 << endl;
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is negative and temp2 is positive
          if (abs(temp1) != abs(temp2) && posY[temp2] && negY[temp1+100000]) {
            // cout << temp1 << " xb " << temp2 << endl;
            ans += 1;
          }
        } else {
          //temp1 is negative and temp2 is positive
          if (negY[temp1+100000] && posY[temp2]) {
            // cout << temp1 << " xc " << temp2 << endl;
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is positive and temp2 is negative
          if (abs(temp1) != abs(temp2) && negY[temp2+100000] && posY[temp1]) {
            // cout << temp1 << " xc " << temp2 << endl;
            ans += 1;
          }
        }
      }
    }
    //Now iterate through the yPoints
    for (auto ypt : yPoints) {
      for (auto divs : divisors[max(-ypt,ypt)]) {
        temp1 = ypt/divs;
        temp2 = -ypt*divs;
        if (ypt > 0) {
          //temp1 is positive and temp2 is negative
          if (posY[temp1] && negY[temp2+100000]) {
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is negative and temp2 is positive
          if (abs(temp1) != abs(temp2) && posY[temp2] && negY[temp1+100000]) {
            ans += 1;
          }
        } else {
          //temp1 is negative and temp2 is positive
          if (negY[temp1+100000] && posY[temp2]) {
            ans += 1;
          }
          temp1 = -temp1;
          temp2 = -temp2;
          //temp1 is positive and temp2 is negative
          if (abs(temp1) != abs(temp2) && negY[temp2+100000] && posY[temp1]) {
            ans += 1;
          }
        }
      }
    }
    //Output the answer
    if (origin) {
      cout << ans+(m-1)*(n-1) << endl;
    } else {
      cout << ans << endl;
    }
    //resize the vectors
    resizer();
  }

  return 0;
}
