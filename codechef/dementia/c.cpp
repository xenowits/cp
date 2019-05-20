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
  long a[n+1];
  fori(i,0,n-1)
    cin >> a[i];
  if (n == 1)
  {
    cout << 1 << endl << "L";
    return 0;
  }
  string s = "";
  int j = n-1,temp = -1;
  for(int i = 0; i < n && i <= j;)
  {
    if (a[i] > temp && a[j] > temp)
    {
      if ((a[i]-temp) < (a[j]-temp))
      {
        temp = a[i];
        s += 'L';
        i += 1;
        //cout << "yeah" << endl;
      }
      else
      {
        temp = a[j];
        s += 'R';
        j -= 1;
        //cout << "wahha" << endl;
      }
    }
    else if (a[j] > temp)
    {
      s += 'R';
      temp = a[j];
      j -= 1;
      //cout << "kaha" << endl;
    }
    else if (a[i] > temp)
    {
      s += 'L';
      temp = a[i];
      i += 1;
      //cout << "jaha" << endl;
    }
    else
    {
        //cout << "chutiye" << i << j << temp << endl;
        break;
    }
  }
  cout << s.length() << endl << s;
  return 0;
}
