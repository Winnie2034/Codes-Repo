#include<bits/stdc++.h>
using namespace std;

#define ll      long long
#define FIO     ios_base::sync_with_sdio(0); cin.tie(0); cout.tie(0)

int main() {
    int n;
    cin>>n;
    vector<ll> vec;
    for(int i = 0 ; i<n ; i++){
        ll t;
        cin>>t;
        vec.push_back(t);
    }
    
    sort(vec.begin(), vec.end());
    
    ll ans = -1;
    for(int i = 0 ; i<n ; i++){
        ans = max(ans, vec[i]*(n-i));
    }
    
    
    cout<<ans<<"\n";

	return 0;
}
