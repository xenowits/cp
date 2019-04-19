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
    //unordered_set<string,string> s;
    vector<string> v = {"Power","Time","Space","Soul","Reality","Mind"};
    vector<bool> visited(6,false);
    int n;string temp;
    cin >> n;
    fori(i,1,n)
    {
      cin >> temp;
      if (temp == "red")
        visited[4] = true;
      if (temp == "purple")
        visited[0] = true;
      if (temp == "green")
        visited[1] = true;
      if (temp == "blue")
        visited[2] = true;
      if (temp == "orange")
        visited[3] = true;
      if (temp == "yellow")
        visited[5] = true;
    }
    cout << 6-n << endl;
    vector<string> p;
    fori(i,0,5)
    {
      if (!visited[i])
        cout << v[i] << endl;
    }
    // fori(i,0,p.size()-1)
    // {
    //   if (i < p.size()-1)
    //     cout << p[i] << endl;
    //   else
    //     cout << p[i];
    // }
    return 0;
}
