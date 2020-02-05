//https://ide.geeksforgeeks.org/selKW0A2gW
//https://codeforces.com/problemset/problem/1238/D
//THE CODE IS FOR MODIFIED PROBLEM:
//every character in a good substring must be a part
//of any palindrome in the original string
//FInd the no of such subtrings

#include <bits/stdc++.h>
using namespace std;

#define ll long long int


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    //manacher's algorithm for finding all the subpalindromes
    vector<int> d1(n), d2(n);

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        cout << i << " d1 " << d1[i] << endl;
    }

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
        cout << i << " d2 " << d2[i] << endl;
    }
    //Line sweep algorithm to find lenfth of segment
    //whose answer needs to be found as l*(l-1)/2
    vector<int> ans(n+1,0);
    int left, right;
    for (int i = 0; i < n; i++) {
      if (d1[i]) {
        //if there is a odd length palindrome centered at i
        left = i-d1[i]+1;
        right = i+d1[i]-1;

        if (right-left+1 > 1) {
            cout << i << " odd " << left << " odd " << right << endl;
            ans[left] += 1;
            ans[right+1] -= 1;
        }
      }
      if (d2[i]) {
        //if there is an even length palindrome centered at i
        left = i-d2[i];
        right = i+d2[i]-1;

        if (right-left+1 > 1) {
            cout << i << " even " << left << " even " << right << endl;
            ans[left] += 1;
            ans[right+1] -= 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0)
            ans[i] += ans[i-1];
        cout << i << " " << ans[i] << endl;
    }

    ll finalAns = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] > 0) {
        for (int j = i; j < n; j++) {
          if (ans[j] > 0) {
            cnt += 1;
          } else {
            finalAns += cnt*(cnt-1)/2;
            cnt = 0;
            i = j;
          }
        }
      }
    }
    cout << finalAns << endl;
    return 0;
}
