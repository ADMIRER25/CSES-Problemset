#include <bits/stdc++.h>
using namespace std;

long long solve(int k)
{
    // total number of cells.
    long long cell = k * k;

    // total number of ways of chossing 2 cells from k^2 cells. K^2C2
    long long ways = (cell * (cell - 1)) / 2;

    // for each 2x3 cell has two unsafe position and for 3x2 cell 2 unsafe posistion. so we have to find in kxk matrix how many 2x3 and 3x2 cell are available just subtract them from total number of ways.
    long long unsafe = 2 * (k - 1) * (k - 2) < 0 ? 0 : 2 * (2 * (k - 1) * (k - 2));
    long long safe = ways - unsafe;
    return safe;
}
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << solve(i) << endl;
    }
    return 0;
}