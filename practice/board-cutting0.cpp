#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define fori(i,a,b) for (long int i = a; i <= b ; ++i)

// Complete the boardCutting function below.
int boardCutting(vector<int> cost_y, vector<int> cost_x) {

        priority_queue<int> yHeap, xHeap;
        for (int y : cost_y)
            yHeap.push(y);
        for (int x : cost_x)
            xHeap.push(x);
        //cout << yHeap.size() << " ghus chuka h " << xHeap.size() << endl;
        long long int xSections = 0, ySections = 0, cost = 0;
        while (!xHeap.empty() || !yHeap.empty())
        {
            int x,y;
            if (!xHeap.empty())
              x = xHeap.top();
            if (!yHeap.empty())
              y = yHeap.top();
            //cout << yHeap.size() << " " << xHeap.size() << " size tha" << endl;
            if (!yHeap.empty() && !xHeap.empty() && y>=x)
            {
                cost += (y*(xSections+1))%mod;
                ySections += 1;
                yHeap.pop();
                //cout << cost << " y wala" << endl;
            }
            if (!yHeap.empty() && !xHeap.empty() && y<x)
            {
                cost += (x*(ySections+1))%mod;
                xSections += 1;
                xHeap.pop();
                //cout << cost << " x wala" << endl;
            }
            if (xHeap.empty() && !yHeap.empty())
            {
              cost += (y*(xSections+1))%mod;
              ySections += 1;
              yHeap.pop();
            }
            if (yHeap.empty() && !xHeap.empty())
            {
              cost += (x*(ySections+1))%mod;
              xSections += 1;
              xHeap.pop();
            }
            // if (ySections == 40)
            //   break;
        }
        return cost%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    long long int m,n;
    cin >> q;
    while(q>0)
    {
      //cout << "chalo shuru krte h aaj ka mukadma" << endl;
      cin >> m >> n;
      vector<int> cost_y(m-1), cost_x(n-1);
      fori(i,0,m-2)
        cin >> cost_y[i];
      //cout << "age ao " << cost_y.size() << endl;
      fori(i,0,n-2)
        cin >> cost_x[i];
      //cout << "bhar gya bhaiya " <<  cost_x.size() << endl;
      cout << boardCutting(cost_y,cost_x) << endl;
      q-=1;
    }
    return 0;
}
