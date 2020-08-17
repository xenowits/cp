bool repeated(vector<int> &visited) {
    for (int i = 0; i < 256; i += 1) {
        if (visited[i] > 1) {
            return true;
        }
    }
    return false;
}

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length();
    if (n <= 1) {
        return n;
    }

    vector<int> freq(256, false);
    int l = 0, r = 0, ans = 1;
    freq[A[0]] = true;

    //ASSUMING THAT
    //AT THE START OF EACH ITERATION WE HAVE A SUBARRAY
    //WHICH IS FREE OF ANY REPEATED CHARACTER

    while (r < n) {
        r += 1;
        if (r < n)
            freq[A[r]] += 1;
        else
            break;

        bool flag = repeated(freq);

        if (!flag) {
            ans = max(ans, r-l+1);
        } else {
            //repeated characters in l....r
            //shift l so that there are no repeated characters
            while (l < r && repeated(freq)) {
                freq[A[l]] -= 1;
                l += 1;
            }
        }
    }

    return ans;
}
