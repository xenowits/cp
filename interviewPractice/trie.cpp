#include <iostream>
#include<vector>

using namespace std;

class Node{
public:
  Node *children[26];
  bool isword;
};

Node* getNode()
{
  Node *node = new Node;
  node->isword = false;
  for(int i = 0 ; i < 26; ++i)
    node->children[i] = NULL;
  return node;
}

void insert(Node **root,string s)
{
  Node *temp = *root;
  for(int i = 0 ; i < s.length(); ++i)
  {
    int indx = s[i]-'a';
    if (!temp->children[indx])
    {
      temp->children[indx] = getNode();
    }
    temp = temp->children[indx];
  }
  temp->isword = 1;
}

bool search(Node **root, string s)
{
  Node *temp = *root;
  for (int i = 0 ; i < s.length(); ++i)
  {
    int indx = s[i]-'a';
    if (!temp->children[indx] || temp->children[indx] == NULL)
      return 0;
    temp = temp->children[indx];
  }
  return temp->isword;
}

int main()
{
  Node *root = getNode();
  insert(&root,"gulab");
  insert(&root,"abhishek");
  if (search(&root, "abhishek"))
    cout << "ha gulab to h" << endl;
  else
    cout << "sala ye kaha ka h" << endl;
}
