#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
    /*
        x*1 + y*2=a--> m
    0,0 ----------->a,b
        x*2 + y*1=b--> n

        m*2-n : 3*y = (2*a)-b >= 0 and this part should be a whole numebr for that it has to te divisible by 3.
        x = a-2*y >= 0.
        because x and y are whole numebers
    */
    ll a, b;
    cin >> a >> b;
    if (2 * a - b >= 0 && (2 * a - b) % 3 == 0)
    {
        ll y = (2 * a - b) / 3;
        ll x = a - 2 * y;
        if (x >= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ll t;
    cin >> t;
    while (t--)
        Solution();
    return 0;
}