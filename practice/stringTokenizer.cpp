#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define fs first
#define sc second

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  std::string s = "scott>=tiger>=mushroom";
  std::string delimiter = ">=";
  // code1 returning token : doesn't modify s
  auto start = 0;
  auto end = s.find(delimiter);
  while (end != std::string::npos)
  {
    std::cout << s.substr(start, end - start) << std::endl;
    start = end + delimiter.length();
    end = s.find(delimiter, start);
  }
  std::cout << s.substr(start, end) << endl;

  // code2 returning token : modifies s

  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      std::cout << token << std::endl;
      s.erase(0, pos + delimiter.length());
  }
  std::cout << s << std::endl;

  //end of code2

// vector<vector<int> > v(5, vector<int>(5,-1) );

  return 0;
}
