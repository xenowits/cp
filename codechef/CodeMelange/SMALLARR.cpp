#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void maxSubArraySum(int a[], int size, long final, int x)
{
    float max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0, st = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = st;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            st = i+1;
        }
    }
    float asli;
    asli = final - max_so_far + (max_so_far)/x;
    cout << asli;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,x;
  cin >> n >> x;
  int a[n];
  long final = 0;
  fori(i,0,n-1)
  {
    cin >> a[i];
    final += a[i];
  }
  maxSubArraySum(a,n,final,x);
  return 0;
}
