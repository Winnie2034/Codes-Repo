/*
this sorting is used to sort the numbers lying in the range between 1 to n^2
e.g. 170, 45, 75, 90, 802, 24, 2, 66
this sorting algorithm uses the counting sort as the subroutine.

starting from the least significant bit to the most significant bit we will count sort the numbers
bit by bit.

let d be the digits of to be sorted. Radix sort takes O(d*(n+b)) time where b is the base for representing
numbers here the base is taken as 10.
And d be the number of digits in the input integers. Thus if k is the maximum
value then d will be log(k) with the base b. Hence overall time will be O(log k * (n+b)) with base as b

This complexity look more than tha complexity of comparison based sorting algorithms. 
now we are sorting numbers in range b/w 1 and n^2 thus k has a maximum value of n^c for some constant
c. This makes the complexity as O(log n * (n+b)) with base b. This time stil appears more.
Now if we take the base as n, the complexity reduces to O(2n) thus reducing it to linear time.

Thus if we can sort numbers b/w 1 to n^c if the numbers are represented in base n.
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

//because here we already have the range of numbers as any significant digit will be between 0-9
//we don't have to find the range of the numbers and we can directly set the count array to the size of 10
void CountingSort(vector<int> &arr, int n, int exp)
{
    vector<int> output(n);
    vector<int> count(10, 0);

    //now we will extract the significant bits based on the value of the exponent and sort the numbers.
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) //This is to be remembered as the forward loop won't work here.
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    arr = output;
}

void radixsort(vector<int> &arr, int n)
{
    int Max = *max_element(arr.begin(), arr.end());
    //max element returns the iterator pointing to the maximum element in the array.
    //deferencing the iterator gives us the value at the iterator.

    for (int exp = 1; Max / exp > 0; exp *= 10)//we don't have to run the loop after we have scanned
    //all the digits of the maximum element.
    {
        CountingSort(arr, n, exp);
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

        radixsort(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}