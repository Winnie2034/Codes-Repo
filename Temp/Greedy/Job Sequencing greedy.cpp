/* 
Given an array of jobs where every job has a deadline and associated profit if
the job is finished before deadline.
Each job takes single unit of time, so the minimum possible deadline for any job is 1
Maximize the total profit if only one job can be scheduled at a time.
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

class Job
{
public:
    char job;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

void jobsequencing(vector<Job> arr, int size)
{
    sort(arr.begin(), arr.end(), compare);
    // cout << arr[1].profit;

    vector<char> result(size, 'X');

    // cout << size;/
    vector<bool> slot(size, false);

    for (int i = 0; i < size; i++)
    {
        for (int j = min(size, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                slot[j] = true;
                result[j] = arr[i].job;
                break;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {

    // }

    vector<Job> arr = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = arr.size();
    jobsequencing(arr, n);

    return 0;
}