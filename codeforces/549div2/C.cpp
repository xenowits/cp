#include <bits/stdc++.h>
using namespace std;

int parent[111111];
bool disrespectParent[111111];
bool getRespect[111111];

//boolean array are initialised to false when declared globally
//but if they are declared in local scope, they contain garbage values

int main() {
    int n;
    bool someoneDead = false;
    cin >> n;

    for(int i=1;i<=n;i++) cin >> parent[i] >> disrespectParent[i];

    for(int i=1;i<=n;i++) {
        if(!disrespectParent[i]) {
            getRespect[parent[i]] = true;
        }
    }

    for(int i=1;i<=n;i++) {
        if(disrespectParent[i] && !getRespect[i]) {
            someoneDead = true;
            cout << i << ' ';
        }
    }

    if(someoneDead) {
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
