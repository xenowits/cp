#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int product(int x)
{
    int prod = 1;
    while (x) {
        prod *= (x % 10);
        x /= 10;
    }
    return prod;
}

// This function returns the number having
// maximum product of the digits
int findNumber(int l, int r)
{
    // Converting both integers to strings
    string a = to_string(l);
    string b = to_string(r);

    // Let the current answer be r
    int ans = r;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '0')
            continue;

        // Stores the current number having
        // current digit one less than current
        // digit in b
        string curr = b;
        curr[i] = ((curr[i] - '0') - 1) + '0';

        // Replace all following digits with 9
        // to maximise the product
        for (int j = i + 1; j < curr.size(); j++)
            curr[j] = '9';

        // Convert string to number
        int num = 0;
        for (auto c : curr)
            num = num * 10 + (c - '0');

        // Check if it lies in range and its product
        // is greater than max product
        if (num >= l && product(ans) < product(num))
            ans = num;
    }
    long int pror = 1;
    while(ans > 0)
    {
      pror = pror*(ans%10);
      ans = ans/10;
    }
    return pror;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin >> n;
  // int arr[n];
  // fori(i,0,n)
  // {
  //   cin >> arr[i];
  // }
  cout << findNumber(1,n);
  return 0;
}
