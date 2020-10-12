//ojas is an ecological woodcutter, *what the fuck is an ecological woodcutter. if he cuts wood
//he is not ecological bc*.
//we are given an array of n of trees where a[i] denotes the height of each tree.
//Ojas has a chainsaw which is of adjustable height and can go upto infinity (Elon Musk left the chat)
//we are given an integer B which is the amount of height of wood required by our very own mc Ojas.
//find the maximum integer height of the chainsaw that allows him to gather atleast B height of wood.
//BINARY SEARCH OP.

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int solve(vector<int> arr, int n, int height)
{
    int high = arr[n - 1];
    int low = arr[0];

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tempsum = arr[i] - mid;
            if (tempsum > 0)
            {
                sum += tempsum;
            }
        }

        if (sum >= height)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low - 1;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int height;
        cin >> height;

        int ans = solve(arr, n, height);

        cout << ans << "\n";
    }

    return 0;
}