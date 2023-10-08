// Find if Parent are Same or not by using DSU.
    

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<ll>
class DisjointSet {
    vll rank, parent, size;
public:
    DisjointSet(ll n) {
        rank.resize(n + 1, 0ll);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 1;
        }
    }

    ll findUPar(ll node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else{
            parent[ulp_v] = ulp_u;
            if(rank[ulp_v] == rank[ulp_u]) rank[ulp_u]++;
        }
    }

    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    DisjointSet dsu(8);
    dsu.unionByRank(1,2);
    dsu.unionByRank(3,4);
    dsu.unionByRank(4,5);
    dsu.unionByRank(3,6);
    dsu.unionByRank(5,7);
    if(dsu.findUPar(2)==dsu.findUPar(7)){
        cout<<"Same Parent"<<endl;
    }else{
        cout<<"Different Parent"<<endl;
    }
    //Ouptut - Different Parent 
    dsu.unionByRank(1,4);
    if(dsu.findUPar(2)==dsu.findUPar(7)){
        cout<<"Same Parent"<<endl;
    }else{
        cout<<"Different Parent"<<endl;
    }
    // Output - Same Parent
    return 0;
}