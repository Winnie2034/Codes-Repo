//we are given an array of length n with n boards to paint of different units length
//also we have k painters who take exactly one unit of time to paint
//one unit of board we need to find the minimum time that is required to paint
//the whole array given the constraint that a painter can only paint consecutive boards
//or a single board at once i.e. he can paint {2,3,4} or {2} only but not {2,3,5}, also 2 painters
//cannot share a same board

#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int solve(int k, vector<int> boards)
{
    int n = boards.size();
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += boards[i];
    }
    int low = boards[n - 1];

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int numpaint = 1; //because at least one painter is requried to paint the boards. 
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += boards[i];
            if (temp > mid)
            {
                temp = boards[i];
                numpaint++;
            }
        }

        if (numpaint <= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        int numberOfPainters;
        int sizeVector;
        cin >> numberOfPainters >> sizeVector;

        vector<int> boards(sizeVector);

        for (int i = 0; i < sizeVector; i++)
        {
            cin >> boards[i];
        }

        sort(boards.begin(), boards.end());

        int ans = solve(numberOfPainters, boards);

        cout << ans << "\n";
    }

    return 0;
}
