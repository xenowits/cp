#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
lli t=1;
//cin>>t;
while(t--)
{
lli n;
cin>>n;
char chess[n][n];
fi(i,0,n)
{
if(i%2==0)
{
fi(j,0,n)
{
if(j%2==0)
chess[i][j]='W';
else
chess[i][j]='B';
}
}
else
{
fi(j,0,n)
{
if(j%2==0)
chess[i][j]='B';
else
chess[i][j]='W';
}
}
}
fi(i,0,n)
{
fi(j,0,n)
cout<<chess[i][j];
cout<<endl;
}
}
return 0;
}
