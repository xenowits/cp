//https://www.codechef.com/problems/ECJAN20F

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define fs first
#define sc second

vector<ll> adj[(ll)1e5+7];
vector<ll> tour;
vector<bool> visited((ll)1e5+7,false);
map<ll,ll> start, last;
vector<ll> values((ll)1e6, 0);

class BIT {
	// Implementation of a Binary Indexed Tree (Fennwick Tree)
public:

	BIT(std::vector<ll> list) {
		// Initialize BIT with list in O(n)
		m_array = std::vector<ll>(list.size() + 1, 0);
		for (ll idx = 0; idx < list.size(); idx++) {
			m_array[idx + 1] = list[idx];
		}

		for (ll idx = 1; idx < m_array.size(); idx++) {
			ll idx2 = idx + (idx & -idx);
			if (idx2 < m_array.size()) {
				m_array[idx2] += m_array[idx];
			}
		}
	}

	ll prefix_query(ll idx) const {
		// Computes prefix sum of up to the element at index idx
		ll result = 0;
		for (++idx; idx > 0; idx -= idx & -idx) {
			result += m_array[idx];
		}
		return result;
	}

	ll range_query(ll from_idx, ll to_idx) const {
		// Computes the range sum between two indices (both inclusive)
        if (from_idx == 0)
            return prefix_query(to_idx);
        else
            return prefix_query(to_idx) - prefix_query(from_idx - 1);
	}

	void update(ll idx, ll add) {
		// Add a value to the element at index idx
		for (++idx; idx < m_array.size(); idx += idx & -idx) {
			m_array[idx] += add;
		}
	}

private:
	std::vector<ll> m_array;
};

ll c = 0;

void dfs(ll s) {
    tour.pb(s);
    start[s] = c;
    c += 1;
    visited[s] = true;
    for (auto x : adj[s]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    tour.pb(s);
    last[s] = c;
    c += 1;
}


int main() {
    ll q, n, a, b, x;
    cin >> n >> q;
    for (ll i = 1; i <= n-1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //euler tour aka dfs
    dfs(1);
    // for (auto x : start) {
    //     cout << x.fs << " helo " << x.sc << endl;
    // }
    // for (auto x : last) {
    //     cout << x.fs << " " << x.sc << endl;
    // }
    for (ll i = 1; i <= n; i++) {
        cin >> values[i];
    }
    //Initialise BIT
    vector<ll> detour(tour.size()+5);
    vector<bool> somebol(10007,false);

    for(ll i = 1; i <= tour.size(); i++) {
      if (somebol[values[tour[i]]] == false)
        detour[i] = values[tour[i]];
      else {
          somebol[values[tour[i]]] = true;
          detour[i] = -1*values[tour[i]];
      }
    }
    BIT bit(detour);
    for (ll i = 1; i <= q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            //cout << x << "ehe" << endl;
            //cout << bit.prefix_query(start[x]-1) - values[1];
        } else if (a == 2) {
            cin >> x >> b;
            //add b to node x
            //bit.update(start[x],b);
            //bit.update(last[x],-b);
           //cout << x << " " << b << endl;
        }
    }
    return 0;
}
