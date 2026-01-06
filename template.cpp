#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
ll sumOfDigits(ll n)
{
    ll sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
vector<ll> sieve(ll n)
{
    vector<ll> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}
ll binaryExponentiation(ll x, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            b = b / 2;
            x = (x * x) % MOD;
        }
        else
        {
            ans = (ans * x) % MOD;
            b -= 1;
        }
    }
    return ans;
}
void Solution()
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
       // ll t;
       // cin >> t;
       // while (t--)
    Solution();
    return 0;
}