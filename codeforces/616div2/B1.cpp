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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
          cin >> arr[i];
        bool flag = true;
        int i = 0;
        for(;i < n; i++){
            if(arr[i] >= i) {
                continue;
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Yes" <<endl;
            continue;
        }
        int count = 0;
        bool flag1 = true;
        for(int j=n-1; j >= i; j--){
            if(arr[j] >= count){
                count++;
                continue;
            }
            else {
                flag1 = false;
                break;
            }

        }
        if(flag1 and count<=arr[i-1])
          cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;
      }
      return 0;
}
