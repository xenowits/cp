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


int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int n = str.size();
        set<int> myset;
        myset.insert(str[0]);

        map<char,int> mymap;
        mymap[str[0]] = 0;
        map<int,bool> chess;

        chess[0]=true;
        int current = 0;
        bool flag = true;

        for(int i = 1; i < n; i++) {

            if(myset.find(str[i])==myset.end()) {

                if(chess[current+1] == false){
                    current+=1;
                    chess[current]=true;
                    mymap[str[i]]=current;
                    myset.insert(str[i]);
                } else if(chess[current-1] == false) {
                    current-=1;
                    chess[current]=true;
                    mymap[str[i]]=current;
                    myset.insert(str[i]);
                } else {
                    flag = false;
                    break;
                }
            }
            else
            {
                int temp = mymap[str[i]];
                if(abs(temp-current)<=1){
                    current = temp;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        } else
          {
            cout<<"YES"<<endl;
            for(int i=0;i<26;i++){
                if(myset.find(i+'a')==myset.end()){
                    mymap[i+'a']=100;
                }
            }
            pair<int,char>newarr[26];
            int total = 0;
            for(auto i:mymap){
                newarr[total] = mk(i.second,i.first);
                total++;
            }
            sort(newarr,newarr+26);
            for(int i=0;i<26;i++){
                cout<<newarr[i].second;
            }
            cout<<endl;
        }
      }
return 0;
}
