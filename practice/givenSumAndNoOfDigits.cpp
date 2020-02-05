//xenowits -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, s;
  cin >> m >> s;

  if (m == 1 && s == 0) {
    cout << "0 0" << endl;
    return 0;
  }

  if (9*m < s || (m > 1 && s == 0)) {
    cout << "-1 -1" << endl;
    return 0;
  }

  string str1, str2;
  while (s) {
    if (s > 9) {
      str1.pb(9+'0');
      s -= 9;
    } else {
      str1.pb(s+'0');
      break;
    }
  }

  sort(str1.begin(), str1.end());
  reverse(str1.begin(), str1.end());

  bool flag = false;
  string tempString = str1;

  if (str1.length() < m) {
    flag = true;
    int temp = m-str1.length();
    fori(i,1,temp) {
      str1.pb('0');
    }
  }

  string maxString = str1;
  if (!flag) {
    //no trailing zeroes in max
    //so smallest is just reverse of the maxString
    str2 = str1;
    reverse(str2.begin(), str2.end());
    cout << str2 << " " << str1 << endl;
  } else {
    //so there are some zeroes
    //find the least non-zero digit and extract 1 out of it
    sort(tempString.begin(), tempString.end());
    char ch = tempString[0];
    tempString[0] = tempString[0]-1;
    str2 = "1";
    int temp = m-(tempString.length()+1);
    fori(i,1,temp)
      str2.pb('0');
    str2 += tempString;
    cout << str2 << " " << str1 << endl;
  }

	return 0;
}
