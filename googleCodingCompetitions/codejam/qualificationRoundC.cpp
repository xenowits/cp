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
	
	int t, t_count = 1;
	cin >> t;
	while (t_count <= t) {
		string str, ans = "";
		cin >> str;
		//we construct the maximum length string 
		//we achieve above by: for each digit d construct (((...d times...)))
		//and gradually cancel consecutive ")("
		int n = str.length();
//		fori(i,0,n-1) {
//			string temp;
//			fori(j,1,str[i]-'0') {
//				temp.pb('(');
//			}
//			temp.pb(str[i]);
//			fori(j,1,str[i]-'0') {
//				temp.pb(')');
//			}
//			ans += temp;		
//		}
		fori(i,0,n-1) {
			string temp;
			if (i == 0) {
				fori(j,1,str[i]-'0') {
                                	temp.pb('(');
                        	}
			}
			temp.pb(str[i]);
			if (i == n-1) {
				fori(j,1,str[i]-'0') {
					temp.pb(')');
				}
			}
			if (i+1 < n && str[i] <= str[i+1]) {
				//ex 2 4 ---> 2))((((4 ---> 2((4
				fori(j,1,str[i+1]-str[i]) {
                               		temp.pb('(');
                        	}					
			} else if (i+1 < n && str[i] > str[i+1]){
				//ex 4 2 ---> 4))))((2 ---> 4))2
				fori(j,1,str[i]-str[i+1]) {
					temp.pb(')');
				}
			}		
			ans += temp;
		}	
		cout << "Case #" << t_count << ": " << ans << endl;
		t_count += 1;
	}	
		
	return 0;
}
