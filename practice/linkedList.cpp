#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

class Node{
public:
  int data;
  Node* next;
  Node(int param)
  {
    data = param;
    next = NULL;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Node *head = new Node(0);
  Node *temp = head;
  fori(i,1,10)
  {
    Node *new_node = new Node(i*i);
    temp->next = new_node;
    temp = new_node;
  }
  while (head != NULL)
  {
    cout << head->data << endl;
    head = head->next;
  }
  return 0;
}
