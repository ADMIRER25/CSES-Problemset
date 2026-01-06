#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // Unties cout from cin to speed up I/O

// Redirect input/output to files for local debugging
// This code block is ignored by online judges because they define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // Redirect standard input to input.txt
    freopen("output.txt", "w", stdout); // Redirect standard output to output.txt
#endif
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    // cout << sum << " " << endl;
    if (sum % 2 != 0)
        cout << "NO" << endl;
    else
    {
        long long s = sum / 2;
        // cout << s << " " << endl;
        vector<int> first, second;
        for (int i = n; i >= 1; i--)
        {
            if (i <= s)
            {
                s -= i;
                first.push_back(i);
            }
            else
            {
                second.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << first.size() << endl;
        for (int val : first)
            cout << val << " ";
        cout << endl;
        cout << second.size() << endl;
        for (int val : second)
            cout << val << " ";
    }
    return 0;
}