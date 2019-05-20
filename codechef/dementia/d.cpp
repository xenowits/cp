#include<bits/stdc++.h>
using namespace std;

long glomin;

pair<int, int> bfs(int u, vector<long> v[],long V)
{
    int dis[V+1];
    memset(dis, -1, sizeof(dis));

    queue<int> q;
    q.push(u);

    dis[u] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (auto it = v[t].begin(); it != v[t].end(); it++)
        {
            int v = *it;

            if (dis[v] == -1)
            {
                q.push(v);

                dis[v] = dis[t] + 1;
            }
        }
    }

    int maxDis = 0;
    int nodeIdx;

    for (int i = 1; i <= V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}

long longestPathLength(vector<long> v[],long n)
{
    pair<int, int> t1, t2;

    t1 = bfs(1,v,n);
    t2 = bfs(t1.first,v,n);

    // cout << "Longest path is from " << t1.first << " to "
    //      << t2.first << " of length " << t2.second;
    glomin = t2.first;
    return t2.second;
}

int main() {
    long n,m,a,b;
    cin >> n >> m;
    vector<long> v[n+1];
    for (int i =1; i <= n-1; ++i)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (m >= 2*n-2)
    {
        cout << n;
        return 0;
    }
    long maxLen = longestPathLength(v,n);
    if (m <= maxLen)
    {
        cout << m;
        return 0;
    }
    return 0;
}
