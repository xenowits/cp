//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	fori(i,0,n-1) {
		cin >> arr[i];
	}

	//the array is k-sorted i.e. the elements are at most k distance away from its sorted position
	
	//create a min-heap
	priority_queue<int, vector<int>, greater<int> > pq;
	fori(i,0,k) {
		pq.push(arr[i]);
	}
	int i = 0;
	while (i < (n-k-1)) {
		cout << pq.top() << " ";
		pq.pop();
		pq.push(arr[k+1+i]);
		i += 1;		
	}
	//cout << "i am out" << endl;
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}	

	return 0;
}
