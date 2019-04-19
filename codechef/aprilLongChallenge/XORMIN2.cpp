#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define INT_SIZE 20;

void dfs(lli s,vector<lli>*tree,bool *visited,vector<lli>&nodes,lli *start,lli *end)
{
    visited[s]=true;
    start[s]=nodes.size();
    nodes.pb(s);

    // cout<<s<<" ";
    for(auto i:tree[s])
    {
        if(!visited[i])
            dfs(i,tree,visited,nodes,start,end);
    }
    end[s]=nodes.size()-1;
}

lli xor_min(vector<lli>values,lli x,lli l,lli r,unordered_map<lli,lli>check,lli *w,lli *k)
{
    lli sam=0;
    lli result=0,res;
    lli par=INT_SIZE;
    sort(values.begin()+l,values.begin()+r+1);
    for(lli i=par-1;i>=0;i--)
    {
        if(x & (1<<i))
        {
            lli ind=lower_bound(values.begin()+l,values.begin()+r+1,sam+(1<<i))-values.begin();
            if(l<=ind-1)
            {
                r=min(r,ind-1);
                result+=(1<<i);
                res=ind;
            }
            else
                sam+=(1<<i);
        }
        else
        {
            lli ind=lower_bound(values.begin()+l,values.begin()+r+1,sam+(1<<i))-values.begin();
            if(r>=ind)
            {
                l=max(ind,l);
                result+=(1<<i);
                res=ind;
                sam+=(1<<i);
            }
        }
    }
    if(res==values.size())
    {
        cout<<check[values[res-1]]<<" ";
        *w=check[values[res-1]];
    }
    else
    {
        cout<<check[values[res]]<<" ";
        *w=check[values[res]];
    }
    *k=result;
    return result;
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t;
cin>>t;
while(t--)
{
    lli n,q;
    cin>>n>>q;
    lli wt[n+1];
    f(i,1,n+1)
    cin>>wt[i];
    vector<lli>tree[n+1];
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    f(i,0,n-1)
    {
        lli u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vector<lli>nodes,values;
    lli start[n+1],end[n+1];
    dfs(1,tree,visited,nodes,start,end);
    for(auto i:nodes)
    {
        // cout<<i<<" "<<start[i]<<" "<<end[i]<<endl;
        values.pb(wt[i]);
    }
    unordered_map<lli,lli>check;
    f(i,1,n+1)
    check[wt[i]]=i;
    // for(auto i:values)
    //     cout<<i<<" ";
    // cout<<endl;
    lli v=0,k=0;
    f(i,0,q)
    {
        lli a,b;
        cin>>a>>b;
        v=v^a;
        k=k^b;
        // cout<<v<<" "<<k<<endl;
        cout<<xor_min(values,k,start[v],end[v],check,&v,&k)<<endl;
    }

    //     cout<<i<<" ";
    // cout<<solve(values,62,start[1],end[1],check)<<endl;
    // int a=62^93;
    // for(int i=start[6];i<end[6];i++)
    // {
    //     int r=values[i]^(99^118);
    //     cout<<r<<" ";
    // }
}
return 0;
}

// 4 14
// 7 123
// 5 103
// 9 32
// 5 118


// 2
// 10 5
// 9 17 93 16 3 61 23 11 2 1
// 1 2
// 2 5
// 5 8
// 1 3
// 1 4
// 3 6
// 3 7
// 6 9
// 6 10
// 4 14
// 7 123
// 5 103
// 9 32
// 5 118
// 3 2
// 10 12 13
// 1 2
// 1 3
// 1 8
// 2 7
