#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int arr[32][4];
		Solution (int n) {
			for (int i = 0; i < 32; i += 1) {
				cout << arr[i][0] << endl;
			}
		}

		void f() {
			int arr[12];
			for (int i = 0; i < 12; i += 1) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main() {
	Solution a(32);
	a.f();
	return 0;
}
