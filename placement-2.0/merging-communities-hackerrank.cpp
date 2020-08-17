#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_set(int x, vector<int> &parent) {
    //Path compression
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find_set(parent[x], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    int x = find_set(a, parent);
    int y = find_set(b, parent);

    if (x != y) {
        //union by size
        if (size[x] < size[y]) {
            swap(x, y);
        }
        //x is made the parent of y
        size[x] += size[y];
        parent[y] = x;
    }
}

void make_set(int n, vector<int> &parent) {
    //Run make_set on all the nodes
    for (int i = 1; i <= n; i += 1) {
        parent[i] = i;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, -1), size(n+1, 1);

    make_set(n, parent);

    //Now carry out the queries
    while (q--) {
        char ch;
        cin >> ch;
        if (ch == 'Q') {
            int a;
            cin >> a;
            int representative = find_set(a, parent);
            cout << size[representative] << endl;
        } else if (ch == 'M') {
            int a, b;
            cin >> a >> b;
            union_sets(a, b, parent, size);
        }
    }

    return 0;
}
