#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int total = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0) count++;
            total+=arr[i];
        }
        int ans = 0;
        if(count+total!=0){
            cout<<count<<endl;
        }
        else
        {
            cout<<count+1<<endl;
        }


}
return 0;
}
