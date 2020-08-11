#include <bits/stdc++.h>
using namespace std;

#define FIO                          \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long

int main()
{
    FIO;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n > 0)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }

        cout << ans << '\n';
    }
}