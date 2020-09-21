#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define ll long long

int med(vector<vector<int>> vec, int m, int n)
{
    int maxi = INT16_MIN, mini = INT32_MAX;
    for (int i = 0; i < m; i++)
    {
        mini = min(mini, vec[i][0]);
    }

    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, vec[i][n - 1]);
    }

    int desired = (m * n + 1) / 2; // because m*n is provided as odd all the time.

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            count += upper_bound(vec[i].begin(), vec[i].end(), mid) - vec[i].begin();
        }

        if (count < desired)
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid;
        }
    }

    return mini;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> vec(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> vec[i][j];
            }
        }

        int ans = med(vec, m, n);
        cout << ans << "\n";
    }

    return 0;
}