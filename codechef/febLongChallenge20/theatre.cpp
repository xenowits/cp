#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

int main() {
    int tests;
    cin >> tests;
    ll total_ans = 0;
    while (tests--) {
        int arr[4][4];
        for(int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                arr[i][j] = 0;

        int n,t,row,col;
        char m;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> m >> t;
            row = m-'A';
            col = t/3-1;
            arr[row][col] += 1;
        }
        ll ans = INT_MIN;
        //now loop int 4*4 matrix
        for (int i = 0; i < 4; i++) {
            ll temp = arr[0][i];
            for (int j = 0; j < 4; j++) {
                ll temp1 = arr[1][j];
                for (int k = 0; k < 4; k++) {
                    ll temp2 = arr[2][k];
                    for (int l = 0; l < 4; l++) {
                        ll temp3 = arr[3][l];
                        //perform operations here
                        vector<int> adj[4];
                        adj[i].pb(temp);adj[j].pb(temp1);adj[k].pb(temp2);adj[l].pb(temp3);
                        ll temp4 = 0;
                        vector<int> vovuh;
                        for(int tat = 0; tat <= 3; tat++) {
                          auto x = adj[tat];
                          int sz = x.size();
                          if (sz > 0) {
                            sort(x.begin(),x.end(),greater<int>());
                            if (x[0] > 0)
                              vovuh.pb(x[0]);
                          }
                        }
                        sort(vovuh.begin(), vovuh.end(),greater<int>());
                        ll lauda = 1, vovuhKaSize = vovuh.size();
                        temp4 -= 100*(4-vovuhKaSize);
                        for (int sss = 0; sss < vovuhKaSize; sss++) {
                            temp4 +=(100-25*(lauda-1))*vovuh[sss];
                            lauda++;
                        }
                        ans = max(ans, temp4);
                    }
                }
            }
        }
        cout << ans << endl;
        total_ans += ans;
    }
    cout << total_ans << endl;
    return 0;
}
