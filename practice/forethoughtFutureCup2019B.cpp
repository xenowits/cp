#include<bits/stdc++.h>
using namespace std;

int main()
{
  string t;
  cin >> t;
  int a_count = 0;
  string first, second;
  int i;
  for(i = t.length()-1 ; i >= 0; --i)
  {
    if (t[i] == 'a')
      break;
    second.push_back(t[i]);
  }
  for(int j = i; j >= 0; --j)
  {
    if (t[j] == 'a')
      a_count += 1;
    else
      first.push_back(t[j]);
  }
  if (a_count == t.length())
  {
    cout << t;
    return 0;
  }
  if (a_count == 0)
  {
    int n = t.size();
    if (t.substr(0,n/2) == t.substr(n/2,n/2))
    {
      cout << t.substr(0,n/2);
    }
    else
      cout << ":(";
    return 0;
  }
  if (second.length() == 0 || first.length() == 0)
  {
    cout << ":(";
    return 0;
  }
  reverse(first.begin(),first.end());
  reverse(second.begin(), second.end());
  string final = first+second;
  int n = final.size();
  int n1 = t.size();
  if (final.substr(0,n/2) == final.substr(n/2,n/2))
  {
    // cout << final.substr(0,n/2);
    // for(int i = t.length()-1; i >= n1-n/2 ; ++i)
    // {
    //
    // }
    cout << t.substr(0,n1-n/2);
  }
  else
    cout << ":(";
  return 0;
}
