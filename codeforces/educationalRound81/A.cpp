#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        ll total = n/2;
        ll remainder = n%2;

        if(remainder==0){
            for(int i=0;i<total;i++){
                cout << 1;
            }
        }
        else {
            cout << 7;
            for(int i=0;i<total-1;i++){
                cout << 1;
            }
        }
        cout<<endl;
      }
      return 0;
}
