#include <iostream>
using namespace std;
typedef long long int lli;
int arr[1000000];
int ans = 0;
#include <stack>
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  stack<pair<int, int>> s;
  s.push(make_pair(arr[n - 1], 0));
  for (int i = n - 2; i >= 0; i--) {
    // cout<<i<<endl;

    int count = 0;
    while ((!s.empty()) && s.top().first > arr[i]) {
      //  cout<<" in stack "<<endl;
      count = max(count + 1, s.top().second);
      //    cout<<"poppinongln "<<s.top().first<<" "<<s.top().second<<endl;
      s.pop();
    }
    // cout<<" here "<<endl;

    ans = max(ans, count);

    s.push(make_pair(arr[i], count));
    // cout<<"pusihing "<<arr[i]<<" "<<count<<endl;
  }
  cout << ans << endl;
}
