//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[27];

void graphClear() {
  fori(i,0,25) {
    adj[i].clear();
  }
}

bool dfs(int v, vector<bool> &visited, int parent) {
  visited[v] = true;
  // cout << (char)(v+'a') << " ";
  for (auto x : adj[v]) {
    if (!visited[x]) {
      if (dfs(x,visited,v)) {
        return true;
      }
    }
    else if (x != parent) {
      return true;
    }
  }

  return false;
}

bool isCyclic(vector<bool> &visited) {
    fori(i,0,25) {
      if (!visited[i] && adj[i].size() > 0) {
        if (dfs(i,visited,-1))
          return true;
      }
    }
    return false;
}

bool degreeCheck() {
  fori(i,0,25) {
    if (adj[i].size() > 2) {
      return true;
    }
  }
  return false;
}

void realDfs(int u, vector<int> &ans, vector<bool> &visited) {
  visited[u] = true;
  ans.pb(u);
  for (auto x : adj[u]) {
    if (!visited[x])
      realDfs(x,ans,visited);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
      cout << "YES" <<  endl;
      for(char ch = 'a'; ch <= 'z'; ch++) {
        cout << ch;
      }
      cout << endl;
      continue;
    }
    fori(i,0,n-1) {
      int ch = s[i]-'a';
      int ch1, ch2;
      if (i == 0) {
        ch1 = s[i+1]-'a';
        bool found = false;
        for(int x : adj[ch]) {
          if (x == ch1) {
            found = true;
            break;
          }
        }
        if (!found){
          adj[ch].pb(ch1);
        }
      } else if (i == n-1) {
        ch2 = s[i-1]-'a';
        bool found = false;
        for(int x : adj[ch]) {
          if (x == ch2) {
            found = true;
            break;
          }
        }
        if (!found){
          adj[ch].pb(ch2);
        }
      } else {
        ch1 = s[i+1]-'a';
        ch2 = s[i-1]-'a';
        bool found = false;
        for(int x : adj[ch]) {
          if (x == ch1) {
            found = true;
            break;
          }
        }
        if (!found){
          adj[ch].pb(ch1);
        }
        found = false;
        for(int x : adj[ch]) {
          if (x == ch1) {
            found = true;
            break;
          }
        }
        if (!found){
          adj[ch].pb(ch2);
        }
      }
    }
    //graph constructed
    //check for cycles
    vector<bool> visited(27,false);
    //count no of good vertices
    int hello = 0;
    fori(i,0,25) {
      if (adj[i].size() == 1) {
        hello = i;
        break;
        // cout << i << " fdf ";
      }
    }
    // cout << endl;
    if (isCyclic(visited)) {
      cout << "NO" << endl;
    } else if (degreeCheck()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<int> ans;
      vector<bool> visited(27,false);
      realDfs(hello,ans,visited);
      vector<bool> counter(27,false);
      for(int abc : ans) {
        counter[abc] = true;
        cout << (char)(abc+'a');
      }
      fori(i,0,25) {
        if (!counter[i]) {
          cout << (char)(i+'a');
        }
      }
      cout << endl;
    }
    graphClear();
  }
	return 0;
}
