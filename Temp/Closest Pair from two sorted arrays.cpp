/* You are given two arrays in ascending order and a number 'x'
    write an algorithm to find a pair whose sum is closest to the number x
    the pair has element from each of the array
*/
#include <bits/stdc++.h>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

void solve(vector<int> arr1, vector<int> arr2, int x)
{
    //the idea is to maintain a variable diff for storing the minimum difference
    //obtained till the iterated arrays.
    int n1 = arr1.size();
    int n2 = arr2.size();
    int diff = INT_MAX;
    int i1, i2;
    int l = 0;
    int r = n2 - 1;
    while (l < n1 && r >= 0)
    {
        int sum = arr1[l] + arr2[r];
        if (abs(sum - x) < diff)
        {
            i1 = l;
            i2 = r;
            diff = abs(sum - x);
        }
        if (sum > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    cout << arr1[i1] << " " << arr2[i2];
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vector<int> arr1(n1);
        vector<int> arr2(n2);
        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }
        int x;
        cin >> x;
        solve(arr1, arr2, x);
    }   

    return 0;
}
