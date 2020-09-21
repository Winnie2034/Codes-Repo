//we are given an array of n books where the i'th book has arr[i] pages
//we are also given the number of students m. we need to distribute the books to students such that
// the maximum number of books allocated to each student is minimum possible and return that minimum value
//under the given constraint that each student must be allocated at least one book and 
//no 2 students share a common book. also, the allocation should be done in a contiguous manner.


#include <bits/stdc++.h>

using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

bool canSolve(vector<int> arr, int n, int m, int currentmid)
{
    int curr_sum = 0;
    int students = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > currentmid)
        {
            return false;
        }
        if (curr_sum + arr[i] > currentmid)
        {
            students++;
            curr_sum = arr[i];
            if (students > m)
            {
                return false;
            }
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return true;
}
int solve(vector<int> arr, int n, int m)
{
    if(m > n){
        return -1;
    }
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        hi += arr[i];   
    }

    int lo = 0;
    int result = INT16_MAX;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (canSolve(arr, n, m, mid))
        {
            result = min(result, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return result;
}

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;

        int ans = solve(arr, n, m);

        cout << ans << "\n";
    }

    return 0;
}