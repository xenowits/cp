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
#define fs first
#define sc second

class Node{
public:
  int data;
  Node* next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void push(int x, Node** head)
{
  if (*head == NULL)
  {
    *head = new Node(x);
    return;
  }
  Node* temp = *head;
  while (temp->next != NULL)
    temp = temp->next;
  Node* tp = new Node(x);
  temp->next = tp;
}

void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void aUtil(Node** a, Node** c, Node** prev)
{
  Node* tp = new Node((*a)->data);
  *a = (*a)->next;
  if (*prev != NULL)
    (*prev)->next = tp;
  else
    *c = tp;
  *prev = tp;
}

void bUtil(Node** b, Node** c, Node** prev)
{
  Node* tp = new Node((*b)->data);
  *b = (*b)->next;
  if (*prev != NULL)
    (*prev)->next = tp;
  else
    *c = tp;
  *prev = tp;
}

Node* sortedMerge(Node* a, Node* b)
{
  Node *prev = NULL, *c = NULL;
  while (a != NULL && b != NULL)
  {
    if (a->data <= b->data)
    {
      aUtil(&a,&c,&prev);
    }
    else
    {
      bUtil(&b,&c,&prev);
    }
  }
  if (a != NULL)
  {
    while(a != NULL)
    {
      aUtil(&a,&c,&prev);
    }
  }
  if (b != NULL)
  {
    bUtil(&b,&c,&prev);
  }
  return c;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //linked list 1a and 2b

  Node* a = NULL;
  push(12,&a);
  push(32,&a);
  push(72,&a);
  push(100,&a);

  Node* b = NULL;
  push(14,&b);
  push(30,&b);
  push(32,&b);
  push(73,&b);

  print(a);
  print(b);

  cout << endl;

  print(sortedMerge(a,b));

  return 0;
}
