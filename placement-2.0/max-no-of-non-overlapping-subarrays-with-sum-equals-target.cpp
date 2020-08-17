#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &nums, vector<int> &prefix, int target) {
	if (i > j) {
		return 0;
	}

	if (i == j) {
		if (nums[i] == target) {
			return 1;
		}
		return 0;
	}

	int total_sum = (i == 0 ? prefix[j] : prefix[j] - prefix[i-1]);
	int max_left_right = 0;

	for (int k = i+1; k <= j; k += 1) {
		max_left_right = max(max_left_right, solve(i, k-1, nums, prefix, target) + solve(k, j, nums, prefix, target));
	}

	if (total_sum == target) {
		return max(1, max_left_right);
	}

	return max_left_right;
}

int maxNonOverlapping(vector<int>& nums, int target) {
	int n = nums.size();
	int ans = 0;

	vector<int> prefix(100005, 0);

	for (int i = 0; i < n; i += 1) {
		if (i == 0) {
			prefix[i] = nums[i];
		} else {
			prefix[i] = (prefix[i-1] + nums[i]);
		}
	}

	return solve(0, n-1, nums, prefix, target);
}

int main() {
	vector<int> nums = {-2,6,6,3,5,4,1,2,8};
	int target = 10;
	cout << maxNonOverlapping(nums, target) << endl;
	return 0;
}
