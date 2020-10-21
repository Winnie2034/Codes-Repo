#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

//simplest algo after each pass we have maximum element
//from the remaining array in the end or for every i , i elements from the last are sorted.
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Selection sort: maintains two subarrays of the array to be sorted, one on the left which is sorted,
//one in the right which is unsorted
//for every iteration minimum element from the unsorted array is picked and is placed into the sorted array
void selectionSort(vector<int> &arr, int n)
{
    int min_indx;
    for (int i = 0; i < n - 1; i++)
    {
        min_indx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_indx])
            {
                min_indx = j;
            }
        }
        swap(arr[min_indx], arr[i]);
    }
}

//Insertion sort: maintains 2 subarrays but unlike selection sort it picks up the element from the unsorted array and places it at
//the correct position in the sorted array, works as if we are sorting playing cards in the deck.
void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

//Merge Sort: Divide and conquer algorithm, works in NlogN time. Comprises of two functions, first one splits, creates 2 arrays
//left and right one and passes them to the second function which merges the 2 arrays.
//same complexity in all 3, average, worst or best cases.
void merge(vector<int> &arr, int low, int high, int mid)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void split(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        split(arr, low, mid);
        split(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

//Heap sort: similar to selection sort the only difference is that in selection sort
// the smallest element is found and is put in the front of the array whereas in this heap sort
// the largest element is found and replaced by the last index of the array and calling it recursively
// by reducing the size of the array.

//heapify to construct or rearrange the heap

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; //denotes the left element of root
    int r = 2 * i + 2; //denotes the right element of the root

    //if left child is bigger
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    //if right child is bigger
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    //recursively calling heapify to heapify the affected subtree

    if (largest != i)
    {
        swap(arr[largest], arr[i]);

        heapify(arr, n, largest);
    }
}

void heapsort(vector<int> &arr, int n)
{
    //build the heap or rearranging the array
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    //now that the array has the largest element at the root node that is at index 0
    //we will swap the 0th element with the one at the last index and call heapify on
    //the array with one size shorter.
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        //after this the n-1 element is sorted and for the rest heapify is called.
        heapify(arr, i, 0);
    }
}

/*

Quick Sort: also a divide and conquer algorithm that works similar to merge sort 
it picks up an element as pivot and then partitions the array around that pivot.
the key process is the partition() method as it picks up the pivot and sorts in the following manner

all elements smaller than the pivot are placed before pivot while all the other greater than
the pivot are placed after the pivot.

selection of pivot can be done in the following ways:
1. select the last element as the pivot. (we'll follow this approach)
2. select the first element as pivot.
3. pick a random element as pivot.
4. pick the median as the pivot.

*/

int partitionfunc(vector<int> &arr, int low, int high)
{
    //last element as pivot
    int pivot = arr[high];

    int i = low; //increments as we swap

    for (int j = low; j < high; j++) //j < high because "high" contains the pivot itself
    //keep in mind that j should start from low and not 0
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int pi = partitionfunc(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

/*
Counting Sort: only used when given data lies in a particular range
complexity is O(n+k) where n is the size of array and k is the range of the elements.

*/

void countingsort(vector<int> &arr, int n)
{
    int Min = *min_element(arr.begin(), arr.end());
    int Max = *max_element(arr.begin(), arr.end());
    int r = Max - Min + 1;
    vector<int> count(r, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - Min]++;
    }
    for (int i = 1; i < r; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        output[count[arr[i] - Min] - 1] = arr[i];
        --count[arr[i] - Min];
    }
    // For Stable algorithm
    // for (i = sizeof(arr)-1; i>=0; --i)
    // {
    //     output[count[arr[i]]-1] = arr[i];
    //     --count[arr[i]];
    // }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        countingsort(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}