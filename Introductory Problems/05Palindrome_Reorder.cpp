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
    string str;
    cin >> str;
    int freq[26] = {0};
    for (char ch : str)
        freq[ch - 'A']++;
    string ans = "";
    int cnt = 0;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        int f = freq[i];
        if(f == 0) continue;
        if (f % 2 != 0)
        {
            cnt++;
            ch = char(65 + i);
        }
        else
        {
            char t = char(65 + i);
            int half = f/2;
            ans.append(half,t);
        }
    }
    if (str.length() % 2 != 0)
    {
        if (cnt == 1)
        {
            string reversed(ans.rbegin(), ans.rend());
            ans.append(freq[ch-'A'],ch);
            ans += reversed;
        }
        else
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    else
    {
        if (cnt == 0)
        {
            string reversed(ans.rbegin(), ans.rend());
            ans += reversed;
        }
        else
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    cout << ans << endl;
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