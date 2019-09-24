#include<bits/stdc++.h>
#define loop(i,a,b)     for(int i=a;i<b;i++)
#define rloop(i,a,b)    for(int i=a-1;i>=b;i--)
typedef unsigned long long lld;
using namespace std;
bool comp1(const pair<int,int> a,const pair<int,int> b)
{
    // return (a.first!=b.first)?a.first>b.first:(a.second > b.second);
    return a.first+a.second>b.first+b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,r;cin>>n>>r;
    vector<pair<int,int> > pos, neg;
    loop(i,0,n)
    {
        int a,b;
        cin>>a>>b;
        if (b>=0)
          pos.push_back(make_pair(a,b));
        else
          neg.push_back(make_pair(a,b));
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),comp1);
    bool flag=0;
    loop(i,0,pos.size())
    {
        if(r>=pos[i].first)r+=pos[i].second;
        else
        {
            flag=1;break;
        }
    }
    loop(i,0,neg.size())
    {
        if(r>=neg[i].first && r+neg[i].second>=0)r+=neg[i].second;
        else
        {
            flag=1;break;
        }
    }
    cout<<(flag?"NO":"YES")<<endl;
    return 0;
}
