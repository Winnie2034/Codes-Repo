#include <bits/stdc++.h>
using namespace std;
#define FIO                          \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> attack(102);
        vector<int> defense(102);

        for (int i = 1; i <= n; i++)
        {
            cin >> attack[i];
        }
        attack[0] = attack[n];
        attack[n + 1] = attack[1];

        for (int i = 1; i <= n; i++)
        {
            cin >> defense[i];
        }
        defense[0] = defense[n];
        defense[n + 1] = defense[1];

        int ansdef = -1;

        for (int i = 1; i <= n; i++)
        {
            if (defense[i] > attack[i + 1] + attack[i - 1])
            {
                ansdef = defense[i];
                break;
            }
        }

        cout << ansdef << '\n';
    }

    return 0;
}