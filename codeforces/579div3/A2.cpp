#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n,q;
  cin >> q;

  while (q--)
  {
    cin >> n;
    vector<int> v(n);
    vector<int> dup(n);
    int a;
    for(int i =  0; i < n; ++i)
    {
      cin >> v[i];
      if (v[i] == 1)
        a = i;
      dup[i] = i+1;
      //cout << v[i] << " " << dup[i] << endl;
    }
    std::rotate(v.begin(), v.begin()+a ,v.end());
    for(int i = 0 ; i < n; ++i)
      cout << v[i] << " " << dup[i] << endl;
    if (v == dup)
      cout << "YES" << endl;
    else
    {
      std::rotate(v.begin(), v.begin()-a ,v.end());
      reverse(v.begin(), v.end());
      a = n-(1+a);
      std::rotate(v.begin(), v.begin()+a ,v.end());
      if (v == dup)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }

}
