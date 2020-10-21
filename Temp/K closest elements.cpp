/*
Given a sorted array and a value 'x', find the 'k' closest elements to x in the array.
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

void printArray(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findNearest(vector<int> arr, int low, int high, int x) //to find the crossover point.
{
    //base cases
    if (arr[high] <= x) // the crossover point will lie after the high index
    {
        return high;
    }
    else if (arr[low] > x) //the crossover point will lie before the low index.
    {
        return low;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] <= x && arr[mid + 1] > x)
    {
        return mid;
    }

    if (arr[mid] < x)
    { //crossover can be ahead of mid
        return findNearest(arr, mid + 1, high, x);
    }

    return findNearest(arr, low, mid - 1, x);
}

vector<int> solve(vector<int> arr, int n, int x, int k)
{
    //now that we have the crossover point we will now iterate through the whole array
    //and keeping the record of count and keep adding the number to the array which is nearer
    // to the number x
    vector<int> ans;
    int l = findNearest(arr, 0, n - 1, x);
    int h = l + 1;

    if (arr[l] == x)
    {
        l--;
    }

    int count = 0;

    while (l >= 0 && h < n && count < k)
    {
        if (x - arr[l] < arr[h] - x)
        {
            ans.push_back(arr[l--]);
        }
        else
        {
            ans.push_back(arr[h++]);
        }
        count++;
    }

    while (count < k && l >= 0)
    {
        ans.push_back(arr[l--]);
        count++;
    }
    while (count < k && h < n)
    {
        ans.push_back(arr[h++]);
        count++;
    }
    sort(ans.begin(), ans.end());
    return ans;
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

        int x, k;
        cin >> x >> k;

        vector<int> ans = solve(arr, n, x, k);

        // cout << ans[0];
        printArray(ans);
    }
    return 0;
}