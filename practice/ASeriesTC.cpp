#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
int dp[MAXN][51];

class ASeries{
    public:
    int longest(vector<int> v)
    {
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i = 0; i < MAXN; ++i)
         	{
           for(int j = 0;j<50;++j)
                {
               dp[i][j] = -1;
           }
        }
        int final = INT_MIN;
        for(int i = 1; i < n;++i)
        {
            int some = INT_MIN;
            for(int j = i-1; j >= 0; --j)
            {
                int tp = v[i]-v[j];
                if (dp[tp][j] != -1)
                    dp[tp][i] = dp[tp][j] + 1;
               else
                   dp[tp][i] = 2;
                some = max(some,dp[tp][i]);
            }
            //cout << i << " " << v[i] << " " << some << endl;
            final = max(final, some);
        }
        return final;
    }
};
int main()
{
    ASeries obj;
    vector<int> v{-10,-20,-10,-10};
    cout << obj.longest(v);
    return 0;
}
