#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int func(int x)
{
    int hi = x, lo = 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int temp = mid * mid;
        if (temp > x)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return lo - 1;
}

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int ans = func(n);
        cout << ans << "\n";
    }

    return 0;
}
