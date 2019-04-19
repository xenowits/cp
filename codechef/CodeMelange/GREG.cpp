#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

// std::vector <int> prime;
// bool is_composite[1000001];
//
// void sieve (long int n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	for (long int i = 2; i <= n; ++i) {
// 		if (!is_composite[i]) prime.push_back (i);
// 		for (long int j = 0; j < prime.size () && i * prime[j] <= n; ++j) {
// 			is_composite[i * prime[j]] = true;
// 			if (i % prime[j] == 0) break;
// 		}
// 	}
// }

void SieveOfEratosthenes(long int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (long int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (long int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    long count = 0;
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          count += 1;
    cout << count;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

// Driver program to test above function
int main()
{
    long n,m;
    cin >> n >> m;
    //sieve(m+n);
    // fori(i,0,prime.size()-1)
    //   cout << prime[i] << " ";
    //cout << prime.size();
    SieveOfEratosthenes(m+n);
    return 0;
}
