#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

void first(vector<int> arr, int low, int high, int key, vector<int> &ans)
{
    if (high < low)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] < arr[mid]) && arr[mid] == key)
    {
        ans[0] = mid;
    }
    else if (key > arr[mid])
    {
        first(arr, mid + 1, high, key, ans);
    }
    else
    {
        first(arr, 0, mid - 1, key, ans);
    }
}

void second(vector<int> arr, int low, int high, int key, vector<int> &ans)
{
    if (high < low)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    if ((mid == arr.size() - 1 || arr[mid] < arr[mid + 1]) && arr[mid] == key)
    {
        ans[1] = mid;
    }
    else if (key > arr[mid])
    {
        second(arr, mid + 1, high, key, ans);
    }
    else
    {
        second(arr, low, mid - 1, key, ans);
    }
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

        int key;
        cin >> key;
        vector<int> ans{-1, -1};

        first(arr, 0, n - 1, key, ans);
        second(arr, 0, n - 1, key, ans);

        cout << "[" << ans[0] << ", " << ans[1] << "]\n";
    }

    return 0;
}