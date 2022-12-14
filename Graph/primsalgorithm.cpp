// Prim's MST 
// Problem Statement
// You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is 
// given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed 
// to return the minimum spanning tree where you need to return weight for each edge in the MST.
// Input Format :

// The first line of input contains an integer 'T' representing the number of the test case. Then the test cases are as follows.

// The first line of each test case argument given is an integer ‘N’ representing the number of nodes in the graph.

// The second line of each test case contains a given integer ‘M’ representing the number of edges. 

// The next ‘M’ lines in each test case contain a matrix ‘E’ of size M x 2 which represents the ‘M’ edges such that there is an 
// edge directed from node E[i][0] to node E[i][1].

// Output Format :

// For each test case, print the minimum spanning tree in the form of edges and their weights which are included in the MST.

// Note :

// You do not need to print anything; It has already been taken care of. 

// Constraints :

// 1 ≤ T ≤ 5
// 2 <= N <= 100
// 1 <= M <= min(1000, N(N - 1) / 2)
// 1 <= E[i][0], E[i][1] <= N


// Time Limit: 1 sec

// Sample Input 1 :

// 1
// 5 14
// 1 2 2
// 1 4 6
// 2 1 2
// 2 3 3
// 2 4 8
// 2 5 5
// 3 2 3
// 3 5 7
// 4 1 6
// 4 2 8
// 4 5 9
// 5 2 5
// 5 3 7
// 5 4 9

// Sample Output 1 :

// 1 2 2
// 1 4 6
// 2 3 3
// 2 5 5

// Explanation of Input 1 :

// The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with
//  weight 3 and (2,5) with weight 5.

// Sample Input 2 :

// 1
// 5 15
// 1 2 21
// 1 4 16
// 2 1 12
// 2 3 13
// 2 4 18
// 2 5 15
// 3 2 13
// 3 5 17
// 4 1 16
// 4 2 18
// 4 5 19
// 5 1 18
// 5 2 15
// 5 3 17
// 5 4 19

// Sample Output 2 :

// 1 2 12
// 1 4 16
// 2 3 13
// 2 5 15

// Explanation of Input 2 :

// The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 12, (1,4) with weight 16, (2,3) with
//  weight 13 and (2,5) with weight 15.

//Solution
//Unoptimized Version
#include<climits>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adjlist[n+1];
    for(int i=0; i<m; i++)
    {
        adjlist[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adjlist[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    bool mstvisit[n+1];
    int key[n+1], parent[n+1];
    for(int i=1; i<=n; i++)
    {
        mstvisit[i]=false;
        key[i]=INT_MAX;
        parent[i]=-1;
    }
    key[1]=0;
    
    for(int i=1; i<=n; i++)
    {
        int minkey=INT_MAX, minnode;
        for(int node=1; node<=n; node++)
            if(mstvisit[node]==false and key[node]<minkey)
            {
                minnode=node;
                minkey=key[node];
            }
        mstvisit[minnode]=true;
        for(auto pairs:adjlist[minnode])
        {
            int nbr=pairs.first;
            int nbrdist=pairs.second;
            if(mstvisit[nbr]==false and nbrdist<key[nbr])
            {
                parent[nbr]=minnode;
                key[nbr]=nbrdist;
            }
        }        
    }
    
    vector<pair<pair<int,int>,int>> ans;
    for(int node=2; node<=n; node++)
    {
        ans.push_back({{parent[node],node},key[node]});
    }
    return ans;
}

//Optimized Version
#include<climits>
#include<queue>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adjlist[n+1];
    for(int i=0; i<m; i++)
    {
        adjlist[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adjlist[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    bool mstvisit[n+1];
    int key[n+1], parent[n+1];
    for(int i=1; i<=n; i++)
    {
        mstvisit[i]=false;
        key[i]=INT_MAX;
        parent[i]=-1;
    }
    key[1]=0;
//  minimum priority queue to store (dist/key,node)pair of unvisited node
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int minkey=pq.top().first, minnode=pq.top().second;
        pq.pop();
        
        mstvisit[minnode]=true;
        
        for(auto pairs:adjlist[minnode])
        {
            int nbr=pairs.first;
            int nbrdist=pairs.second;
            if(mstvisit[nbr]==false and nbrdist<key[nbr])
            {
                parent[nbr]=minnode;
                key[nbr]=nbrdist;
                pq.push({key[nbr],nbr});
            }
        }        
    }
    
    vector<pair<pair<int,int>,int>> ans;
    for(int node=2; node<=n; node++)
    {
        ans.push_back({{parent[node],node},key[node]});
    }
    return ans;
}


