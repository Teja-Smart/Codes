#include <bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
    Input:
        n (2e5)
        A tree 
        and online queries where a vertex becomes active forming an active tree
        and return sum of edges in the perfect matching among active.
        For few queries return all indicies in perfect matching.

*/

// Small Observatins
/*
    

*/

/*

    Assume initially all edges are green.
    
    When a vertex gets added 
    all the edges that are above it gets flipped

    in perfect matching if u remove any vertex only one odd component must be formed.

    Every vertex has at most 1 odd subtree child and total even <=> Perfect Matching.

    For every odd subtree v, e = {v, p[v]} is matching edge.

    so finding perfect matching if it exists in O(n) is easy 

    Finding is there is perfect matching and returning sum of indices is left.

    Using HLD we can flip all the edges in the path above and update the sum of red indices
    accordingly. But is it required? as still we should find if it is a perfect matching.
    Can we maintain for each segment in HLD, number of vertices that have odd 

    lets look at vertices that have 

    total = even and n 


*/

// Claims on algo   
/*  
    

*/


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

}