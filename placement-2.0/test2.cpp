#include <bits/stdc++.h>

using namespace std;

int main() {

	if (INT_MIN - (long long int)-1e9 > 0) {
		cout << "INt min bada h" << endl;
	} else {
		cout << "int min chota h" << endl;
	}
	cout << (int)-1e9 << endl;

	int arr[4] = {1,2,3,4};
	int *n = new int[5];
	// n = arr;
	for (int i =0; i < 4; i += 1) {
		// cout << n[i] << " ";
		n[i] = i*5;
	}
	// 
	// n[2] = 85;
	// n[3] = 34;
	for (int i = 0; i < 4; i += 1) {
		cout << arr[i] << " " << n[i] << endl;
	}
	cout << endl;


	return 0;
}
