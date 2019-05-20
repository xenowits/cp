#include<bits/stdc++.h>
using namespace std;
#define MAX     100000

set<int> alive, goingToDie, nextToDie;
int height[MAX+5];
const int inf = 1000000000;

void printSet(set<int> s)
{
  for(auto x : s)
    cout << height[x] << " ";
  cout << endl;
}

int main()
{
    int i, j, k, v, n, day = 0;

    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &height[i]);

    height[0] = inf;
    for(i = 1; i <= n; i++)
    {
        alive.insert(i);
        if(height[i] > height[i-1]) goingToDie.insert(i);
    }
    printSet(alive);
    printSet(goingToDie);
    while(goingToDie.size())
    {
        day++;

        for(auto x : goingToDie)
            alive.erase(x);

        nextToDie.clear();
        for(auto x : goingToDie)
        {
            auto itr = alive.lower_bound(x);
            cout << *itr << " sb thik" << endl;
            // cout << height[*itr] << " " << height[*previous] << endl;
            if(itr == alive.begin() || itr == alive.end()) continue;

            auto previous = itr;
            previous--;
            if(height[*itr] > height[*previous]) nextToDie.insert(*itr);
        }

        goingToDie = nextToDie;
    }

    printf("%d\n", day);
    return 0;
}
