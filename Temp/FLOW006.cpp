#include<bits/stdc++.h>
using namespace std;

#define ll      long long
#define FIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


void solve(){
    int n;
    cin>>n;

    int ans = 0;
    while(n>0){
        ans += n%10;
        n /= 10;
    }

    cout<<ans<<"\n";
}

int main() {
    FIO;
    ll t;
    cin>>t;

    while(t--){
        solve();
    }


    return 0;
}