#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define FOR(i,n) for(ull (i)=0;(i)<(n);((i)++))

int main() {
    ull iArr[26][26][4]={}, iLen, iCum;
    string iString; cin >> iString;
    iLen=iCum=0;
    //while(iString[++iLen]){}
    iLen = iString.length();
    FOR(m,iLen){
        char i = iString[m]-'a';
        FOR(j,26){
            iArr[i][j][3]+=iArr[i][j][2]%1000000007;
            iArr[j][i][2]+=iArr[j][i][1]%1000000007;
            iArr[j][i][1]+=iArr[j][i][0]%1000000007;
            iArr[i][j][0]++;
        }
    }

    FOR(i,26){
        FOR(j,26){
            iCum+=iArr[i][j][3];
        }
    }
    cout << iCum%1000000007;
    return 0;
}
