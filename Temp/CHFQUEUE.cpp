#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9 + 7;

int main() {
    FIO;
    
    int n, k;
    
    cin >> n >> k;
    vector<int> inp(n);
    stack<int> indx;
    ll ans = 1;
    
    for(int i = 0 ; i < n ; i++){
        cin >> inp[i];
    }
    
    indx.push(0);
    for(int i = 1 ; i < n ; i++){
        
        if(indx.empty()) {
            indx.push(i);
            continue;
        }
        while(!indx.empty() && inp[indx.top()] > inp[i]) {
            ans = (ans * (i - indx.top() + 1)) % MOD;
            indx.pop();
        }
        
        indx.push(i);
    }
    
    cout << ans << "\n";
    
	// your code goes here
	return 0;
}
