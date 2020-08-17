#include <bits/stdc++.h>
using namespace std;

const int ALBHABET_SIZE = 26;

struct TrieNode {
    //Array of TrieNode pointers - 26 pointers ejecting from the node
    TrieNode* children[ALBHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNode() {
    TrieNode* temp = new TrieNode;
    temp->isEndOfWord = false;

    for (int i = 0; i < ALBHABET_SIZE; i += 1) {
        temp->children[i] = NULL;
    }

    return temp;
}

void insert(TrieNode* root, string key) {
    TrieNode* p = root;
    int n = key.length();

    for (int i = 0; i < n; i += 1) {
        int indx = key[i] - 'a';

        if (!p->children[indx]) {
            p->children[indx] = getNode();
        }

        p = p->children[indx];
    }

    p->isEndOfWord = true;
}

bool searchKey (TrieNode* root, string key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    //We must reach END of TRIE & IT MUST NOT BE NULL
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    vector<string> v(n);
	    TrieNode* root = getNode();

	    for (int i = 0; i < n; i += 1) {
	        cin >> v[i];
	        insert(root, v[i]);
	    }

	    string sts;
	    cin >> sts;

	    cout << searchKey(root, sts) << endl;
	}
	return 0;
}
