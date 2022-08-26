// Problem Statement
// A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to 
// vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. 
// Topological Sorting for a graph is not possible if the graph is not a DAG.
// Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. 
// Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

// Note:

// 1. It is guaranteed that the given graph is DAG.
// 2. There will be no multiple edges and self-loops in the given DAG.
// 3. There can be multiple correct solutions, you can find any one of them. 
// 4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.

// Input format:

// The first line of input contains an integer ‘T’ denoting the number of test cases. The description of  ‘T’ test cases follows.

// The first line of each test case contains two space-separated integers ‘V’, ‘E’, representing the number vertices 
// and edges in the graph respectively.

// Then ‘E’ lines follow,  each containing 2 space-separated integers ‘u’, ‘v’ representing that there is a directed 
// edge from vertex ‘u’ to vertex ‘v’

// Output format :

// For each test case, return an array representing the topological sort of the vertices of the given DAG.

// Note :

// You do not need to print anything. It has already been taken care of. Just implement the given function.

// Constraints:

// 1 <= T <= 50
// 1 <= V <= 10^4
// 0 <= E <= 10^4
// 0 <= u, v < V 

// Where ‘T’ is the total number of test cases, ‘V’ is the number of vertices, ‘E’ is the number of edges, and ‘u’ and ‘v’ 
// both represent the vertex of a given graph.

// Time limit: 2 sec

// Sample Input 1:

// 2
// 2 1
// 1 0
// 3 2
// 0 1
// 0 2

// Sample Output 1:

// 1 0
// 0 2 1

// Explanation of Sample Input 1:

// Test case 1:
// The number of vertices ‘V’ = 2 and number of edges ‘E’ = 1.
// The graph is shown in the picture: 

// alt text

// The topological sorting of this graph should be {1, 0}  as there is a directed edge from vertex 1 to vertex 0, thus 1 
// should come before 0 according to the given definition of topological sorting.

// Test case 2:
// The number of vertices ‘V’ = 3 and number of edges ‘E’ = 2.
// The graph is shown in the picture:

// alt text

// As there are two directed edges starting from 0, so 0 should come before 1 and 2 in topological sorting. 
// Thus the topological sorting of this graph should be {0, 2, 1} or {0, 1, 2}

// Sample Input 2:

// 2
// 1 0
// 4 4
// 0 1
// 0 3
// 1 2
// 3 2

// Sample Output 2:

// 0
// 0 1 3 2

// Explanation of Sample Input 2:

// Test case 1:   
// There is only a single vertex in the graph that is 0, so its topological sort will be {0}.

// Test case 2:
// See problem statement for its explanation

//Using DFS:
#include<queue>
#include<algorithm>

void dfs(int node, vector<int> adjlist[], bool visited[], vector<int> &ans)
{
    visited[node]=true;
    for(int nbr: adjlist[node])
    {
        if(visited[nbr]==false)
            dfs(nbr, adjlist, visited, ans);
    }
    ans.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;        //stack can also be used
    vector<int> adjlist[v];
    bool visited[v]={false};
    for(int i=0; i<e; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i=0; i<v; i++)
    {
        if(visited[i]==false)
            dfs(i, adjlist, visited, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Using BFS:
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> adjlist[v];
    int indegree[v]={0};
    for(int i=0; i<e; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0; i<v; i++)
        if(indegree[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(int nbr:adjlist[node])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
                q.push(nbr);
        }
    }
    return ans;
}