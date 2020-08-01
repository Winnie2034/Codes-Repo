#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x;
    cin>>x;
    while(x!=42)
    {
        cout<<x<<endl;
        cin>>x;
    }
    return 0;
}