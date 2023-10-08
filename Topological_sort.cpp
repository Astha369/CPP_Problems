// Qn)Given a graph, find the topological order for the given graph.

// Topological sort: The linear ordering of nodes/vertices such that if there 
// exists an edge between 2 nodes u,v then ‘u’ appears before ‘v’.
// Example:
// 4 3
// 1 2
// 2 3 
// 1 4

// Output-
// 1 2 4 3

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N+1, 0); 
	    for(int i = 1;i<=N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 1;i<=N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};
int main()
{
        int n,edges;
        cin>>n>>edges;
    	vector<int> adj[n+1];
    	for(int i=0;i<edges;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }

    	Solution obj;
    	vector<int> v=obj.topo(n, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    return 0;
}