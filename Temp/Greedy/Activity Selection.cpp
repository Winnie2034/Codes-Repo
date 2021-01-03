/* You are given n activities
with their starting and finishing time. we need to find the maximum number of
activities that can be performed by a single person.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

//Below is the recursive solution
void recurActivity(vector<int> start, vector<int> finish, int selected, int size)
{
    //first is always selected.
    int next = selected + 1;
    while (next <= size && start[next] < finish[selected])
    {
        next += 1;
    }

    if (next <= size)
    {
        ans.push_back(selected);
        recurActivity(start, finish, next, size);
    }
    else
    {
        return;
    }
}

//below is the iterative solution
vector<int> iterativeActivity(vector<int> start, vector<int> finish, int selected, int size)
{
    int k = 0;
    vector<int> ans = {0};
    for (int i = 1; i < size; i++)
    {
        if (start[i] >= finish[k])
        {
            ans.push_back(i);
            k = i;
        }
    }

    return ans;
}

//below is the solution using STL
vector<pair<int, int>> stlActivity(vector<int> start, vector<int> finish)
{
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //pushing pairs in the queue
    for (int i = 0; i < start.size(); i++)
    {
        pq.push(make_pair(finish[i], start[i]));
    }

    auto it = pq.top();
    int st = it.second;
    int fn = it.first;
    pq.pop();
    ans.push_back(make_pair(st, fn));

    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();

        if (itr.second >= fn)
        {
            st = itr.second;
            fn = itr.first;
            ans.push_back(make_pair(st, fn));
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> start(n);
        vector<int> finish(n);

        for (int i = 0; i < n; i++)
        {
            cin >> start[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> finish[i];
        }

        vector<pair<int, int>> an = stlActivity(start, finish);
        // vector<int> an = iterativeActivity(start, finish, 0, n);
        for (int i = 0; i < an.size(); i++)
        {
            cout << "{" << an[i].first << ", " << an[i].second << "}" << endl;
        }
        cout << "\n";
    }

    return 0;
}