#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    
    FIO;
    
    int N, X, Y;
    int ans = INT_MAX;
    cin >> N >> X >> Y;
    vector<vector<int>> contest(N);
    vector<int> wormV;
    vector<int> wormW;
    
    
    for(int i = 0 ; i < N ; i++){
       int a, b;
       cin>>a>>b;
       contest[i].push_back(a);
       contest[i].push_back(b);
    }
    
    for(int i = 0 ; i < X ; i++){
        int x;
        cin>>x;
        wormV.push_back(x);
    }
    
    for(int i = 0 ; i < Y ; i++){
        int x;
        cin>>x;
        wormW.push_back(x);
    }
    sort(wormV.begin(), wormV.end());
    sort(wormW.begin(), wormW.end());
    
    // cout<<wormV[0]<<" "<<wormW[0];
    
    for(int i = 0 ; i < N ; i++){
        
        
        auto it1 = upper_bound(wormV.begin(),wormV.end(),contest[i][0])-1;
		auto it2 = lower_bound(wormW.begin(), wormW.end(),contest[i][1]);
		  if(it1 != wormV.end() && it2 != wormW.end()){
			auto x = *it2 - *it1 +1;
			ans = min(ans,x);
		}
    }
    
    cout << ans << "\n";
    
	// your code goes here
	return 0;
}
