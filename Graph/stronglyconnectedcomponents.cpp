//Also known as kosaraju's algorithm
// Problem Statement
// Difficulty: HARD
// You are given an unweighted directed graph of 'V' vertices and 'E' edges. Your task is to print all the 
// strongly connected components (SCCs) present in the graph.

// Input format:

// The very first line of input contains an integer ‘T’ denoting the number of test cases.
// The first line of every test case contains two space-separated integers ‘V’ and ‘E’ denoting the number of vertices and 
// the number of edges present in the graph. 
// The next ‘E’ lines contain two space-separated integers ‘a’ and ‘b’ denoting a directed edge from vertex ‘a’ to ‘b’.

// Note:
// Use zero-based indexing for the vertices.

// Output format:

// For each test case, print space-separated vertices present in the strongly connected components of the graph, print the 
// output for one SCC on each line.
// The order of sequence does not matter.

// Note:

// You do not need to print anything, it has already been taken care of. Just implement the given function.

// Constraints:
// 1 <= 'T' <= 300 
// 1 <= 'V' <= 2000
// 'V' - 1 <= 'E' <= 2000
// 0 <= 'a, b' < 'V'

// Time Limit: 1 sec

// Sample Input 1:

// 1
// 5 6
// 0 1
// 1 2
// 1 4
// 2 3
// 3 2
// 4 0

// Sample Output 1:

// 0 1 4 
// 2 3 

// Explanation for Sample Input 1:

// For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as 
// shown in the image below.

// sample graph 1
// Sample Input 2:

// 2
// 1 0
// 4 4
// 0 1
// 1 2
// 2 3
// 3 1

// Sample Output 2:

// 0
// 0
// 1 2 3

// Explanation for Sample Input 2:

// For the first test case, the graph has 1 node(0) but there are no edges, therefore only 1 SCC exists and that is {0}.

// For the second test case, one SCC is {0} and the other is {1, 2, 3}. Therefore the answer is 0, 1 2 3

//Solution: Using topological sort of original graph and traversing transpose graph in order in topological sort.
#include<stack>
void topodfs(vector<int> adjlist[], stack<int> &st, int visited[], int node)
{
    visited[node]=1;
    for(int nbr: adjlist[node])
    {
        if(visited[nbr]==0)
            topodfs(adjlist, st, visited, nbr);
    }
    st.push(node);
}

void dfstranspose(vector<int> transpose[], vector<int> &component, int visited[], int node)
{
    visited[node]=2;
    component.push_back(node);
    for(int nbr: transpose[node])
    {
        if(visited[nbr]==1)
            dfstranspose(transpose, component, visited, nbr);
    }
}    
    
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adjlist[n];
    vector<int> transpose[n];
    for(int i=0; i<edges.size(); i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
        transpose[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    stack<int> st;
    int visited[n]={0};
    
    for( int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            topodfs(adjlist, st, visited, i);
        }
    }
    
    while(!st.empty())
    {
        int node=st.top();
        vector<int> component;
        if(visited[node]==1)
        {
            dfstranspose(transpose, component, visited, node);
        }
        st.pop();
        if(component.size()!=0)
            ans.push_back(component);
    }
    return ans;
}