#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

const int ALPHABET_SIZE = 26;

struct TrieNode
{
  struct TrieNode *children[ALPHABET_SIZE];
  int cnt;
  bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
  struct TrieNode *pNode = new TrieNode;

  pNode->isEndOfWord = false;
  pNode->cnt = 0;
  fori(i,0,ALPHABET_SIZE-1)
  {
    pNode->children[i] = NULL;
  }
  return pNode;
}

void insert(struct TrieNode *root, string key, int hoho)
{
  //cout << "hoho " << hoho << endl;
  struct TrieNode *pCrawl = root;
  for(int i  = 0 ; i < key.length(); ++i)
  {
    int index = key[i] - 'a';
    if (!pCrawl->children[index])
    {
        pCrawl->children[index] = getNode();
    }
    pCrawl = pCrawl->children[index];
    if (pCrawl->cnt == 0)
      pCrawl->cnt = 1;
    else
      pCrawl->cnt += 1;
  }

  pCrawl->isEndOfWord = true;

}

bool search(struct TrieNode *root, string key)
{
  struct TrieNode *pCrawl = root;
  for(int i = 0 ; i < key.length(); ++i)
  {
    int index = key[i]-'a';
    if (!pCrawl->children[index])
      return false;
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int searchInt(struct TrieNode *root, string key, int hoho)
{
  struct TrieNode *pCrawl = root;
  for(int i = 0 ; i < key.length(); ++i)
  {
    int index = key[i]-'a';
    if (!pCrawl->children[index])
      return 0;
    else
    {
        pCrawl = pCrawl->children[index];
    }
  }
  if (pCrawl != NULL)
  {
    return pCrawl->cnt;
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  struct TrieNode *root = getNode();
  root->cnt = 0;
  fori(i,1,n)
  {
    string s1,s2;
    cin >> s1 >> s2;
    if (s1 == "add")
    {
      insert(root,s2,i);
    }
    if (s1 == "find")
    {
      cout << searchInt(root,s2,i) << endl;
    }
  }

  return 0;
}
