#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int main()
{

    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        int ans = 0;
        cin >> n >> k;
        int a;
        // vector<int> vec(n);

        // for(int i = 0; i < n ; i++){
        //     cin>>vec[i];
        // }

        vector<vector<int>> adj(k, vector<int>{});

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            adj[a - 1].push_back(i);
        }

        for (int i = 0; i < k; i++)
        {
            int l = -1;
            if (adj[i].empty())
            {
                ans = n;
                break;
            }
            else
            {
                for (int j = 0; j < adj[i].size(); j++)
                {
                    if (adj[i][j] - l - 1 > ans)
                    {
                        ans = adj[i][j] - l - 1;
                    }
                    l = adj[i][j];
                }

                if (n - l - 1 > ans)
                {
                    ans = n - l - 1;
                }
            }
        }

        cout << ans << "\n";
    }
    // your code goes here
    return 0;
}
