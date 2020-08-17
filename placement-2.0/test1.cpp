#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sansaXor function below.
int sansaXor(vector<int> arr) {
    int ans = 0;
    long long n = arr.size();

    for (long long int i = 0; i < n; i += 1) {
        if (((n-i)*(i+1)) %2 == 1) {
            ans ^= arr[i];
        }
    }

    return ans;
}

int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int ans = 0;
    int n = c.size();
    int cnt = 1;
    for (int t = 0; t < n; t += k) {
        int sum_tmp = 0;
        for (int i = t; i < t+k && i < n; i += 1) {
            sum_tmp += c[i];
        }
        ans += (cnt)*sum_tmp;
        // cout << ans << endl;
        cnt += 1;
    }

    return ans;
}

string highestValuePalindrome(string s, int n, int k) {
    int diffs = 0;
    vector<bool> problemo(n, false);
    for (int i = 0; i < n/2; i += 1) {
        if (s[i] != s[n-1-i]) {
            diffs += 1;
            problemo[i] = true;
            char ch = max(s[i], s[n-1-i]);
            s[i] = ch;
            s[n-1-i] = ch;
        }
    }

    if (k < diffs) {
        return "-1";
    }

    // cout << "diffs " << diffs << endl;
    k -= diffs;

    //we have already created a PALINDROME
    //do greedy stuff here
    int i = 0;
    while (k >= 1 && i < n/2) {
        if (s[i] != '9') {
            s[i] = '9';
            s[n-1-i] = '9';
            if (problemo[i] == true)
                k -= 1;
            else
                k -= 2;
        }
        i += 1;
    }

    if (k >= 1 && n%2 == 1) {
        s[i] = '9';
    }

    return s;
}

int main() {
    // vector<int> arr = {1, 3, 5, 7, 9};
    // cout << getMinimumCost(3, arr) << endl;
    // cout << sansaXor(arr) << endl;
    string s = "3943";
    cout << highestValuePalindrome(s, 4, 1) << endl;
    return 0;
}
