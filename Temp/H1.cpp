#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int ,int>> swaps = {make_pair(0,1),make_pair(0,3),make_pair(1,2),make_pair(1,4),make_pair(2,5),make_pair(3,4),make_pair(3,6),make_pair(4,5),make_pair(4,7),make_pair(5,8),make_pair(6,7),make_pair(7,8)};
//for understandability we store the matrix as a string and store the pairs of indices which are potential edges i.e., adjacent to each other
vector<int> primes = {2,3,5,7,11,13,17};
void bfs(string input,unordered_map<string,int> &visited)
{
    queue<string> que;
    visited[input] = 1;
    que.push(input);
    while(!que.empty())
    {
      
        string temp = que.front();
        que.pop();
        for(int i=0;i<swaps.size();i++)
        {
            
            string k = temp;
            
            int t = (k[swaps[i].first] - '0') + (k[swaps[i].second] - '0');
            
            if(find(primes.begin(),primes.end(),t) != primes.end())
                {
                   
                    char l = k[swaps[i].first];
                    k[swaps[i].first] = k[swaps[i].second];
                    k[swaps[i].second] = l;
                    
                   
                    if(!visited.count(k))
                    {   
                        visited[k] = visited[temp] + 1;
                        que.push(k);
                    }
                    
                    
                }
                
        }
    }
    
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;//number of test cases
	unordered_map<string,int> visited;
	bfs("123456789",visited);//we start from goal state find the shortest distance to all states reachable
	while(t--)
	{
	
	string goal = "";
	for(int i=0;i<9;i++)
	  {
	      char c;
	      cin>>c;
	      goal += c;
	  }
	
	cout<<(visited[goal] - 1)<<endl;
	}
	return 0;
}
