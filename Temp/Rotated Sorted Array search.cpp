#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int b_search(vector<int> arr, int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (key < arr[mid])
    {
        return b_search(arr, low, mid - 1, key);
    }

    return b_search(arr, mid + 1, high, key);
}
int find_pivot(vector<int> arr, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    if (high == low)
    {
        return low;
    }
    int mid = low + (high - low) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    if (mid > low && arr[mid] < arr[mid - 1])
    {
        return (mid - 1);
    }
    if (arr[low] >= arr[mid])
    {
        return find_pivot(arr, low, mid - 1);
    }
    return find_pivot(arr, mid + 1, high);
}

int find_key(vector<int> arr, int n, int key)
{
    int pivot = find_pivot(arr, 0, n - 1);

    if (pivot == -1)
    {
        return -1;
    }

    if (arr[pivot] == key)
    {
        return key;
    }

    if (key < arr[0])
    {
        return b_search(arr, pivot + 1, n - 1, key);
    }

    return b_search(arr, 0, pivot - 1, key);
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

        int ans = find_key(arr, n, key);

        cout << ans << "\n";
    }

    return 0;
}