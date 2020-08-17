#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
    //use stack : opposite to span-stock problem
    stack<int> stk_left, stk_right;
    int left[n], right[n];

    // memset(arr, 0, n*sizeof(left[0]));
    // memset(arr, 0, n*sizeof(right[0]));

    stk_left.push(0);
    left[0] = 1;
    for (int i = 1; i < n; i += 1) {
        //first pop out all elements from
        //the top which are greater than arr[i]
        while (!stk_left.empty() && (arr[stk_left.top()] >= arr[i])) {
            stk_left.pop();
        }

        if (stk_left.empty()) {
            left[i] = i+1;
        } else {
            left[i] = i - stk_left.top();
        }

        stk_left.push(i);
    }

    stk_right.push(n-1);
    right[n-1] = 1;
    for (int i = n-2; i >= 0; i -= 1) {
        while (!stk_right.empty() && (arr[stk_right.top()] >= arr[i])) {
            stk_right.pop();
        }

        if (stk_right.empty()) {
            right[i] = n-i;
        } else {
            right[i] = stk_right.top()-i;
        }

        stk_right.push(i);
    }

    //after processing both right-wise and left-wise

    //calculate for each tower : maximum area

    int ans = -1e6;

    for (int i = 0; i < n; i += 1) {
        cout << i << " " << left[i] << " " << arr[i] << " " << right[i] << endl;
        ans = max(ans, arr[i]*(right[i] + left[i] - 1));
    }

    return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for (int i = 0 ; i < n; i += 1) {
	        cin >> arr[i];
	    }
	    cout << solve(arr, n) << endl;
	}
	return 0;
}
