#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,k;
    cin >> n >> a >> b >> k;

    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    int req[n];

    for(int i=0;i<n;i++)
    {
        int m = arr[i]%(a+b);
        if(m==0){
            req[i]=ceil(double(b)/a);
        }
        else if(m<=a)
        {
            req[i]=0;
        }
        else
        {
            req[i]=ceil(double(m-a)/a);
        }
    }

    sort(req,req+n);

    int ans =0;
    for(int i=0;i<n;i++){
        if(req[i]<=k){
            ans++;
            k-=req[i];
        }
    }

    cout<<ans<<endl;
    return 0;
}
