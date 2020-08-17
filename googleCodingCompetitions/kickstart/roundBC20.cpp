//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000000
#define MAXN 400005
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

struct vars {
	ll N, S, E, W;
	ll exp;
	vars() : N(0), S(0), E(0), W(0), exp(-1) {
	}
};

string convertToStandardForm(string s) {

	//put ^ character after every digit
	//also put * between consecutive characters(NEWS)
	
	string temp_str;
	int n = s.length();

	fori(i,0,n-1) {

		temp_str += s[i];
		
		if (s[i] >= '2' && s[i] <= '9') {
			temp_str += '^';
		}
		
		if (i+1 < n && (s[i] == ')' || ( s[i] >= 'A' && s[i] <= 'Z') ) && (s[i+1] != '(' && s[i+1] != ')')) {
			temp_str += '*';
		}
	}

	return temp_str;	
}

string infixToPostfix(string s) {
	stack<char> stk;
	int n = s.length();
	string ans;

	fori(i,0,n-1) {
		if ((s[i] >= '2' && s[i] <= '9') || ( s[i] >= 'A' && s[i] <= 'Z') ) {

			ans += s[i];

		} else if (s[i] == '*') {

			while (!stk.empty()) {
				ans += stk.top();
				stk.pop();
			}
			stk.push(s[i]);

		} else if (s[i] == '^' || s[i] == '(') {
			stk.push(s[i]);
		} else if (s[i] == ')') {
			while (stk.top() != '(') {
				ans += stk.top();
				stk.pop();	
			}
			stk.pop();
		}
	}

	while (!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}

	return ans;
}

vars evaluateExp(string s) {

	stack<vars> stk;
	
	int n = s.length();
	
	fori(i,0,n-1) {
		if (s[i] != '^' && s[i] != '*') {
			//it is not an operator
			vars temp;
			if (s[i] >= '2' && s[i] <= '9') {
				temp.exp = s[i]-'0';
			} else {
				switch (s[i]) {
					case 'N': temp.N = 1; break;
					case 'S': temp.S = 1; break;
					case 'E': temp.E = 1; break;
					case 'W': temp.W = 1; break;
				}
			}
			stk.push(temp);
		} else {
			//operator here, let's operate
			vars x = stk.top();	stk.pop();
			vars y = stk.top(); 	stk.pop();
			vars z;

			if (s[i] == '^') {
				ll power = y.exp;
				z.N = (x.N)*power;
				z.S = (x.S)*power;
				z.E = (x.E)*power;
				z.W = (x.W)*power;	
			} else if (s[i] == '*') {
				z.N = x.N+y.N;
				z.S = x.S+y.S;
				z.E = x.E+y.E;
				z.W = x.W+y.W;
			}
			stk.push(z);
		}
	}
	return stk.top();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, t_count = 1;
	cin >> t;
	
	while (t_count <= t) {
		string str, str1, str2;
		cin >> str;

		//first convert to a form that can be evaluated: standard form
		str1 = convertToStandardForm(str);
	       	cout << str1 << endl;

		//convert to postfix expression
		str2 = infixToPostfix(str1);
		cout << str2 << endl;
		
		vars ans = evaluateExp(str2);
		cout << ans.N << " " << ans.S << " " << ans.E << " " << ans.W << " " << ans. exp << endl;

		ll x_ans = (1+ans.E - ans.W)%mod;
		ll y_ans = (1+ans.S - ans.N)%mod;
		
		if (x_ans == 0) {
			x_ans = mod;
		}
		if (y_ans == 0) {
			y_ans = mod;
		}

		cout << "Case #" << t_count << ": " << x_ans << " " << y_ans << endl;
		t_count += 1;
	}

	return 0;
}

