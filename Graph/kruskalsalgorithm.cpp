// Kruskal’s Minimum Spanning Tree Algorithm 
// Problem Statement

// You have been given a connected undirected weighted graph. Your task is to find the weight of the minimum spanning tree 
// of the given graph.
// A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the 
// vertices together, without any cycles, and with the minimum possible total edge weight. A spanning tree’s weight is the 
// sum of weights given to each edge of the spanning tree.
// Input Format:

// The first line contains an integer ‘T’ denoting the number of test cases. Then each test case follows.

// The first input line of each test case contains two integers ‘N’ and ‘M’ denoting the number of nodes and edges in the 
// graph, respectively.

// Each of the next ‘M’ lines contains three space integers ‘U’, ‘V’, and ‘W’. There is an undirected edge between node 
// ‘U’ and ‘V’ of weight ‘W’.

// Output Format:

// For each test case, return the weight of the minimum spanning tree of the given graph.

// Note:

// You don't have to print the expected output, it has already been taken care of. Just implement the given function.

// Constraints :

// 1 <= T <= 50
// 1 <= N <= 10000
// 1 <= M <= 10000
// 1 <= W <= 1000
// 1 <= U, V <= N

// Time limit: 1 sec

// Sample Input 1 :

// 2
// 5 6
// 1 2 6
// 2 3 5
// 3 4 4
// 1 4 1
// 1 3 2
// 3 5 3
// 2 1
// 1 2 4

// Sample output 1 :

// 11
// 4

// Explanation of Sample output 1 :

// In test case 1, the graph is:

// Example

// The minimum spanning tree of the graph is:

// Example

// And its weight is 1 + 2 + 5 + 3 = 11.

// In test case 2, the graph has only one edge. So the minimum spanning will be the graph itself. And its weight is 4.

// Sample Input 2:

// 2
// 3 3
// 1 2 1
// 2 3 2
// 3 1 3
// 4 3
// 1 2 4
// 2 3 5
// 3 4 1

// Sample Output 2:

// 3
// 10

// Explanation of Sample Output 2:

// In test case 1, the weight of the minimum spanning tree will be 3 by considering the 1-2 (weight 1) and 2-3 edge 
// (weight 2).

// In test case 2, the weight of the minimum spanning tree will be 10 as we have to consider all the edges to make 
// the tree connected.

//Solution using Disjoint Sets
#include<algorithm>
bool compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int findparent(int u, vector<int> &parent)
{
    if(u==parent[u])
        return u;
    else
        return parent[u]=findparent(parent[u], parent);
}

void _union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) 
{
    sort(graph.begin(),graph.end(), compare);
    int cost=0;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=1; i<=n; i++)
        parent[i]=i;
    
    for(auto i: graph)
    {
        int u=i[0];
        int v=i[1];
        int wt=i[2];
        u=findparent(u,parent);
        v=findparent(v,parent);
        if(u!=v)
        {
            cost+=wt;
            _union(u,v,parent, rank);
        }
    }   
    return cost;
}
