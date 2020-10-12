/*
You are given an array a[0...n] where each element is "at most" k away from its
target position,
sort the array that takes O(n logk) time.

the below algorithm works as a charm!!
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

//we will use the concept of min heap(priority queue)
//create a min heap of size k+1 and put first k+1 elements in it from the array.
//loop from k+1 to n and each time extract one element from the queue and
//replace it with element at index "index"

void sort(vector<int> &arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q(arr.begin(), arr.begin() + k + 1);
    //the purpose of adding greater to the priority queue is to create a min heap
    //priority queue instead of max heap which is the default behaviour of the priority queue

    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = q.top();
        q.pop();
        q.push(arr[i]);
    }

    //after the above loop ends there is a possibility that the queue is still not empty

    while (!q.empty())
    {
        arr[index++] = q.top();
        q.pop();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, n, k);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

//voila !! done and dusted.