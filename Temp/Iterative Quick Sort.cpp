/*

How can the recursive quick sort be optimised?
1. The recursive implementation uses last index as pivot which may cause troubles when the array
is already sorted. This problem can be solved by choosing pivot as the middle element of the array
or the median of the first mid and last element of the array

2. To reduce the recursion depth use a tail recursion call for the half created initially

3. Insertion sort can be used for smaller subarrays.
(on a length less than a thresold t determined experimentally)


The below code uses a stack to implement quicksort for storing values of high and low for the subarrays.
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

//the partition function for sorting remains same for both the interative method and recursive method
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int index = low;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index], arr[high]);
    return index;
}

void iterativeQuicksort(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;
    stack<int> st;
    st.push(low);
    st.push(high);

    while (!st.empty())
    {
        high = st.top();
        st.pop();
        low = st.top();
        st.pop();

        int p = partition(arr, low, high);

        if (p - 1 > low)
        {
            st.push(low);
            st.push(p - 1);
        }
        if (p + 1 < high)
        {
            st.push(p + 1);
            st.push(high);
        }
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
        iterativeQuicksort(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}