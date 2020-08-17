#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                cin >> arr[i][j];
            }
        }

        int x;
        cin >> x;

        //Let's begin the algorithm
        int r = 0, c = m-1;
        int ans_r = -1, ans_c = -1;

        while (r < n && c >= 0) {
            if (arr[r][c] < x) {
                r += 1;
            } else if (arr[r][c] == x) {
                ans_r = r;
                ans_c = c;
                break;
            } else if (arr[r][c] > x) {
                c -= 1;
            }
        }

        if (ans_r == -1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}
