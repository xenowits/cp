
#include <cstdio>
#include <cstring>

struct Node
{
	int k;
	Node* cs[26];
};

Node t;
int k;
int c;
char bs[26];

void put(Node& n, char* s)
{
	if (s[0] == '\0')
		return;

	if (n.cs[s[0] - 'a'] == NULL)
	{
		int newK = n.k + (bs[s[0] - 'a'] == '0' ? 1 : 0);
		if (newK <= k)
		{
			n.cs[s[0] - 'a'] = new Node();
			n.cs[s[0] - 'a']->k = newK;
			put(*(n.cs[s[0] - 'a']), s + 1);
			c++;
		}
	}

	else
	{
		if (n.cs[s[0] - 'a']->k <= k)
		{
			put(*(n.cs[s[0] - 'a']), s + 1);
		}
	}
}

int main()
{
	char s[1501];
	int n;

	scanf("%s %s %d", s, bs, &k);
	n = strlen(s);

	for (int i = 0; i < n; ++i)
	{
		put(t, s+i);
	}

	printf("%d\n", c);

	return 0;
}
