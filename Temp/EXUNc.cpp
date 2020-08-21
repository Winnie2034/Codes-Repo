#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

set<int> s;

int findAns(int x){
    auto it = s.upper_bound(x);
    it--;
    return(*it);
}

void remove(int x){
    s.erase(x);
}


int main() {
    FIO;
    int n, q;
    cin>>n>>q;
    
    vector<int> arr(n+1);
    
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
    }
    
    s.insert(1);
    
    for(int i = 2 ; i <= n ; i++){
        if(arr[i] % arr[i-1] == 0){
            continue;
        }
        s.insert(i);
    }
    
    
    while(q--){
        int type, index;
        cin>>type>>index;
        
        if(type == 1){
            cin>>arr[index];
            
            if(index > 1){
                if(findAns(index) == index && arr[index]%arr[index-1] == 0){
                    remove(index);
                }
                else if(findAns(index) < index && arr[index]%arr[index-1] != 0){
                    s.insert(index);
                }
            }
            
            if(index < n){
                if(findAns(index + 1) > index && arr[index+1]%arr[index] == 0){
                    remove(index+1);
                }
                
                else if(findAns(index+1) <= index && arr[index+1]%arr[index] != 0){
                    s.insert(index+1);
                }
            }
            
        }
        
        else{
            cout<<findAns(index)<<"\n";
        }
        
    }
    
    
	// your code goes here
	return 0;
}
