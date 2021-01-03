/*
normal insertion sort takes O(n) comparisons in the worst case 
it can be reduced to O(log n) by using the binary search
to determine the position of the element in the sorted array before replacing it. 
the algorithm will have a complexity of O(n^2) because of the series of swaps but the
comparisons will be less
 */

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int _binarySearch(vector<int> arr, int low, int high, int x)
{
    //base case: high and low are same or high < low
    if (low >= high)
    {
        return (x > arr[low]) ? low + 1 : low;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (x < arr[mid])
    {
        return _binarySearch(arr, low, mid - 1, x);
    }
    return _binarySearch(arr, mid + 1, high, x);
}

void _binaryInsertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        int pos = _binarySearch(arr, 0, i - 1, key);

        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
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

        _binaryInsertionSort(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    return 0;
}