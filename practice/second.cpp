//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t = 1;
cin>>t;
while(t--){
    int n,q;
    cin >> n >> q;
    int arr[n][26];
    memset(arr,0,sizeof(arr));
    string str;
    cin >> str;

    arr[0][str[0]-'a']++;

    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            arr[i][j]=arr[i-1][j];
        }
        arr[i][str[i]-'a']++;
    }
    int check[q];
    for(int i=0;i<q;i++){
        cin>>check[i];
        check[i]--;
    }
    int ans[26];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<q;i++){
        for(int j=0;j<26;j++){
            ans[j]+=arr[check[i]][j];
        }
    }
    for(int i=0;i<26;i++){
        ans[i]+=arr[n-1][i];
    }
    for(int i=0;i<26;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	}
return 0;
}
