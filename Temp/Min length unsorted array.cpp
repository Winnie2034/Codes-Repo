/*

given an unsorted array a[0..n-1] of size n, find the minimum length subarray arr[s...e] 
such that sorting this subarray makes the whole array sorted.

*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

void solve(vector<int> arr, int n)
{
    int i, j;

    //finding start and end of the unsorted subarray in arr
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
    }

    if (i == n - 1)
    {
        cout << "Sorted"
             << "\n";
        return;
    }

    for (j = n - 1; j >= 1; j--)
    {
        if (arr[j] < arr[j - 1])
        {
            break;
        }
    }

    int max = arr[i], min = arr[i];

    //find maximum and minimum element in the range of subarray

    for (int k = i + 1; k <= j; k++)
    {
        if (arr[k] < min)
        {
            min = arr[j];
        }
        if (arr[k] > max)
        {
            max = arr[k];
        }
    }

    //find if any element in range 0 to i is greater than the smallest element from the subarray
    //which means that the smaller element must come before the greater element from 0 to i

    for (int k = 0; k < i; k++)
    {
        if (arr[k] > min)
        {
            i = k;
            break;
        }
    }

    //similarly for range j+1 to n-1 we need to find if any element is smaller than the maximum
    //element in the subarray
    //make sure to start with the end because we want the last element in the range j+1 to n-1
    //which is less than the maximum element in the subarray

    for (int k = n - 1; k >= j + 1; k--)
    {
        if (arr[k] < max)
        {
            j = k;
            break;
        }
    }

    for (int k = i; k <= j; k++)
    {
        cout << arr[k] << " ";
    }
    // cout << "\n";
    cout << "\nThis array needs to be sorted to make the whole array sorted!\n";
    return;
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
        solve(arr, n);
    }

    return 0;
}
