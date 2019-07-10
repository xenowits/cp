#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

class BIT {
	// Implementation of a Binary Indexed Tree (Fennwick Tree)
public:
	/*BIT(std::vector<int> list) {
		// Initialize BIT with list in O(n*log(n))
		m_array = std::vector<int>(list.size() + 1, 0);
		for (int idx = 0; idx < list.size(); idx++) {
			update(idx, list[idx]);
		}
	}*/

	// BIT(ll n) {
	// 	// Initialize BIT with list in O(n)
	// 	// m_array = std::vector<int>(list.size() + 1, 0);
	// 	// for (int idx = 0; idx < list.size(); idx++) {
	// 	// 	m_array[idx + 1] = list[idx];
	// 	// }
	// 	m_array = std::vector<int> (n+1,0);
	// 	// for (int idx = 1; idx < m_array.size(); idx++) {
	// 	// 	int idx2 = idx + (idx & -idx);
	// 	// 	if (idx2 < m_array.size()) {
	// 	// 		m_array[idx2] += m_array[idx];
	// 	// 	}
	// 	// }
	// }
	BIT (ll n)
	{
		m_array = std::vector<int> (n+1,0);
		// for(int indx = 1; indx <= n; ++indx)
		// 	m_array[indx] = 0;
	}
	int prefix_query(int idx) const {
		// Computes prefix sum of up to the element at index idx
		int result = 0;
		for (++idx; idx > 0; idx -= idx & -idx) {
			result += m_array[idx];
		}
		return result;
	}

	int range_query(int from_idx, int to_idx) const {
		// Computes the range sum between two indices (both inclusive)
        if (from_idx == 0)
            return prefix_query(to_idx);
        else
            return prefix_query(to_idx) - prefix_query(from_idx - 1);
	}

	void update(int idx, int add) {
		// Add a value to the element at index idx
		for (++idx; idx < m_array.size(); idx += idx & -idx) {
			m_array[idx] += add;
		}
	}

private:
	std::vector<int> m_array;
};

void print(BIT const& bit, int length) {
	std::cout << "Index: ";
	for (int idx = 0; idx < length; ++idx)
		std::cout << std::setw(2) << idx << " ";
	std::cout << std::endl;
	std::cout << "Array: ";
	for (int idx = 0; idx < length; ++idx)
		std::cout << std::setw(2) << bit.range_query(idx, idx) << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Prefix sum of first 13 elements: \t" << bit.prefix_query(12) << std::endl;
	std::cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << std::endl;
	std::cout << "Range sum from index 1 to index 5: \t" << bit.range_query(1, 5) << std::endl;
	std::cout << std::endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> v(n);
	fori(i,0,n-1)
		cin >> v[i];
	BIT bit(n);
	vector<ll> l(n), r(n);
	unordered_map<ll,ll> umap1,umap2;
	fori(i,0,n-1)
	{
		if (i == 0)
		{
			umap1[v[i]] += 1;
			l[i] = 1;
		}
		else
		{
			umap1[v[i]] += 1;
			l[i] = umap1[v[i]];
		}
	}
	ford(i,n-1,0)
	{
		if (i == n-1)
		{
			umap2[v[i]] += 1;
			r[i] = 1;
		}
		else
		{
			umap2[v[i]] += 1;
			r[i] = umap2[v[i]];
		}
	}
	// fori(i,0,n-1)
	// {
	// 	cout << l[i] << " " << r[i] << endl;
	// }
	// code for main algorithm and elegant data structure
	ll ans = 0;
	ford(i,n-1,0)
	{
		if (i < n-1)
		{
			ll temp = bit.range_query(1,l[i]-1);
			ans += temp;
			//cout << l[i] << " " << i << " " << temp << endl;
			bit.update(r[i],1);
		}
		else
		{
			bit.update(r[i],1);
			//cout << l[i] << " " << r[i] << " oji" << endl;
		}
	}
	cout << ans << endl;
  return 0;
}
