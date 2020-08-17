#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, vector<int> > mp;
	mp["abhishek"] = {1,3,6};
	for (auto x : mp) {
		cout << x.first << endl;
		for (auto ele : x.second) {
			cout << ele << " ";
		}
		cout << endl;
	}
}
