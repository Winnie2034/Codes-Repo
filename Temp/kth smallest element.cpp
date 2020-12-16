/*
This algorithms picks out the kth smallest element from the unsorted array.
This can be realted with the program written to print the k smallest element from array.

thus using the min heap we will have first k elements in ascending order.
Then we can print the k-1 th element.

This method hereby does the same using the quicksort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int partititon_(vector<int> arr, int l, int r)
{
    int pivot = r;
    int index = l;
    for (int i = l; i < r - 1; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            swap(arr[index++], arr[i]);
        }
    }

    swap(arr[pivot], arr[index]);
    return index;
}

int find_kth_element(vector<int> arr, int l, int r, int k)
{
    //base condition : this function will work only if k lies in between l and r.
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partititon_(arr, l, r);

        if (pos - l == k - 1)//position of pos with respect to the start pointer should be equal to k - 1
        {
            return arr[pos];
        }
        if (pos - l > k - 1)
        {
            return find_kth_element(arr, l, pos - 1, k);
        }
        return find_kth_element(arr, pos + 1, r, k - pos + l - 1);
        //subtract the number of elements occuring before k i.e. pos - l + 1 from k
    }

    //return int max if more k is greater than the number of elements in array
    return INT_MAX;
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

        int k;
        cin >> k;
        int ans = find_kth_element(arr, 0, n - 1, k);
        cout << ans << "\n";
    }

    return 0;
}