#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 34, 45, 56};
    int count = 0, i;//mistake number one, count and i are integer values 
    // we don't have to initialize them as empty vectors
    
    for (int i = 0; i < vec.size(); i++) //for loop has 3 statements initialization, 
    // end point and increment value
    {
        int j = vec[i];
        if (j % 3 == 0 || j % 5 == 0) //if condition true hone pe jo code rum hoga
        // wo curly braces mein likhna hai
        {
            ++count;
        }
    }

    cout << count; //for loop ke bahar cout krna hai aur tune cout ke symbol << galat lgaya hai

    return 0;
}