#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

class Node{
public:
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void push(Node *head,int x)
{
  Node *node = head;
  while (node->next != NULL)
    node = node->next;
  Node *temp = new Node(x);
  node->next = temp;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node *head = new Node(5);
  push(head,15);
  push(head,10);
  // linked list traversal
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }
  cout << "traversing reversed linked list be like" << endl;
  //code for reversing linked list
  Node *prv = NULL, *nxt = NULL, *curr = head;
  while (curr != NULL)
  {
      nxt = curr->next;
      curr->next = prv;
      prv = curr;
      curr = nxt;
  }
  head = prv;
  temp = head;
  while (temp != NULL)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }
  ///code for reversing and printing ll done
  /// code for reversing ll in groups of K

  return 0;
}
