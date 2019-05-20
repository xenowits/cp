#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int e_count = 0;
  vector<int> v(n);
  string temp = "";
  int toRemove = (n-11)/2;
  fori(i,0,n-1)
  {
    if (s[i] == '8')
    {
        e_count += 1;
        v.pb(i);
    }
  }
  if (e_count <= (n-11)/2)
  {
    cout << "NO";
  }
  else
  {
    int some = 0;
    for(int i = 0 ; i <= n-1 ; ++i)
    {
        if (s[i] == '8' && some >= toRemove)
        {
          //cout << some << toRemove << temp << endl;
          temp += s[i];
          continue;
        }
        else if (s[i] == '8')
        {
            //temp += s[i];
            some += 1;
            //cout << temp << endl;
            continue;
        }
        else
        {
            temp += s[i];
            //cout << temp << endl;
        }
    }
    string now_temp = "";
    some = 0;
    fori(i,0,temp.length()-1)
    {
      if (temp[i] != '8' && some >= toRemove)
      {
          now_temp += temp[i];
          continue;
      }
      else if (temp[i] != '8')
      {
        some += 1;
        continue;
      }
      else
        now_temp += temp[i];
    }
    //cout << temp << " " << now_temp;
    if (now_temp.length() == 11 && now_temp[0] == '8')
    {
      cout << "YES";
    }
    else
      cout << "NO";
  }
  return 0;
}
