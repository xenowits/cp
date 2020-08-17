class Solution {
public:

    long long binpow(long long a, long long b) {
        long long res = 1, mod = 1e9+7;

        while (b > 0) {
            if (b&1) {
                res = (res*a)%mod;
            }

            a = (a*a)%mod;
            b = b>>1;
        }

        return res%mod;
    }

    void Swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

int PARTITION(vector<int> &v, int p, int r) {
	int x = v[r];
	int i = p-1;

	for (int j = p; j <= r-1; j += 1) {
		if (v[j] <= x) {
			i += 1;
			Swap(v[i], v[j]);
		}
	}

	swap(v[i+1], v[r]);
	return i+1;
}

    void QUICKSORT(vector<int> &v, int p, int r) {
    	if (p < r) {
    		int q = PARTITION(v, p, r);
    		QUICKSORT(v, p, q-1);
    		QUICKSORT(v, q+1, r);
    	}
    }

    void MERGE(vector<int> &v, int p, int q, int r) {
        int len1 = q-p+1;
        int len2 = r-q;

        vector<int> left(len1+1), right(len2+1);

        for (int i = 0; i < len1; i += 1) {
            left[i] = v[p+i];
        }
        left[len1] = INT_MAX;

        for (int i = 0; i < len2; i += 1) {
            right[i] = v[q+i+1];
        }
        right[len2] = INT_MAX;

        //actual merge happens here
        int i = 0, j = 0;
        for (int k = p; k <= r; k += 1) {
            if (left[i] <= right[j]) {
                v[k] = left[i];
                i += 1;
            } else {
                v[k] = right[j];
                j += 1;
            }
        }
    }

    void MERGESORT(vector<int> &v, int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            MERGESORT(v, p, q);
            MERGESORT(v, q+1, r);
            MERGE(v, p, q, r);
        }
    }

    long long int sumSubseqWidths(vector<int>& A) {
        //heavy analysis yields a simple formula
        //this reduces the algorithm running time
        //to linear

        long long ans = 0;
        int mod = 1e9+7;

        int n = A.size();

        // sort(A.begin(), A.end());
        // QUICKSORT(A, 0, n-1);
        MERGESORT(A, 0, n-1);

        for (int i = 0; i < n; i += 1) {
            long long int x = binpow(2, i), y = binpow(2, n-i-1);

            ans = (ans + (A[i]*(x - y))%mod)%mod;
        }

        return ans%mod;
    }
};
