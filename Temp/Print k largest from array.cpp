#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

class minHeap
{
    int *arr;
    int size;

public:
    minHeap(int *input, int size);
    void heapify(int i);
    void buildHeap();
};

void minHeap::heapify(int i)
{
    if (i >= size / 2)
    {
        return;
    }

    int smallest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    smallest = arr[left] < arr[i] ? left : i;

    if (right < size)
    {
        smallest = arr[right] < arr[smallest] ? right : smallest;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}

void minHeap::buildHeap()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

//constructor
minHeap::minHeap(int *input, int size)
{
    this->arr = input;
    this->size = size;

    buildHeap();
}

void findKlargest(int *arr, int n, int k)
{
    minHeap *m = new minHeap(arr, k);

    for (int i = k; i < n; i++)
    {
        if (arr[i] < arr[0])
        {
            continue;
        }
        else
        {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int k;
        cin >> k;
        findKlargest(arr, n, k);
    }

    return 0;
}