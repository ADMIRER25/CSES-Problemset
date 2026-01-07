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
ll n;
vector<ll> w;
ll t = 0;
ll mini = INT_MAX;
void solve(ll ind, ll sum)
{
    if (ind >= w.size())
        return;

    ll rest = t - (sum + w[ind]);
    ll diff = abs((sum + w[ind]) - rest);
    mini = min(mini, diff);
    solve(ind + 1, sum + w[ind]);

    rest = t - sum;
    diff = abs(sum - rest);
    mini = min(mini, diff);
    solve(ind + 1, sum);
}
void Solution()
{
    cin >> n;
    if (n == 1)
    {
        int val;
        cin >> val;
        cout << val << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        w.pb(val);
        t += val;
    }
    int sum = 0;
    solve(0, sum);
    cout << mini << endl;
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