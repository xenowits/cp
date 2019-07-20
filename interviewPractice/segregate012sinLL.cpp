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

void segregate(Node** head)
{
  Node* node = *head;
  queue<int> odd, even;
  while (node != NULL)
  {
    if ((node->data)&1)
      odd.push(node->data);
    else
      even.push(node->data);
    node = node->next;
  }
  node = *head;

  while (!even.empty())
  {
    int s = even.front();
    even.pop();
    node->data = s;
    node = node->next;
  }

  while (!odd.empty())
  {
    int s = odd.front();
    odd.pop();
    node->data = s;
    node = node->next;
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node* a = NULL;

  push(17,&a);
  push(15,&a);
  push(8,&a);
  push(12,&a);
  push(10,&a);
  push(5,&a);
  push(4,&a);
  push(1,&a);
  push(7,&a);
  push(6,&a);

  print(a);

  segregate(&a);

  print(a);

  return 0;
}
