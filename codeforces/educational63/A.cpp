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
  string s;int n;
  cin >> n >> s;
  int i;
  for(i = 0; i <= n-1; ++i)
  {
    if (s[i] != 'a')
      break;
  }
  //cout << i << endl;
  char ch = s[i];
  //cout << ch << endl;
  for(int j = n-1; j>i; --j)
  {
    if (s[j] < ch)
    {
      cout << "YES" << endl;
      cout << i+1 << " " << j+1;
      return 0;
    }
  }
  cout << "NO";
  // int n;
  // cin>>n;
  // char arr[n];
  // for(int i=0;i<n;i++)
  // cin>>arr[i];
  // bool flag=true;
  // for(int i=1;i<n;i++)
  // {
  //   if( arr[i]- arr[i-1] < 0)
  //   {
  //     cout<<"YES"<<endl;
  //     cout<<i<<" "<<i+1;
  //     return 0;
  //   }
  // }
  //cout << "NO";
  return 0;
}
