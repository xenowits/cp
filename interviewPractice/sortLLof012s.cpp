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
#define f first
#define s second

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

void countAndModify(Node** nd, vector<ll> &v)
{
  Node* node = *nd;
  while(node != NULL)
  {
    v[node->data] += 1;
    node = node->next;
  }
  ll i = 0;
  //cout << v[0] << " " << v[1] << " " << v[2] << endl;
  node = *nd;
  while (node != NULL)
  {
    if (v[i] > 0)
    {
      node->data = i;
      v[i] -= 1;
      node = node->next;
    }
    else
      i+=1;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll> v(3,0);

  Node* a = NULL;

  push(1,&a);
  push(2,&a);
  push(0,&a);
  push(1,&a);
  push(0,&a);
  push(1,&a);

  print(a);

  countAndModify(&a,v);

  print(a);

  return 0;
}
