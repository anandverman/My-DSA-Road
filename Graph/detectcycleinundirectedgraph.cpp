// Problem Statement

// You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
// Your task is to find if the graph contains a cycle or not.
// A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

// Note:

// 1. There are no parallel edges between two vertices.

// 2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

// 3. The graph can be disconnected.

// For Example :

// Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
// Output: Yes

// Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and 
// vertex 1 and 3. So, there exists a cycle in the graph. 

// Input Format:
// The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the 
// test cases follow.
// The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the total number 
// of vertices and edges, respectively.
// The next ‘M’ lines contain two single space-separated integers representing an edge of the graph.

// Output Format:
// For each test case, the only line of output will return “Yes” if there exists a cycle in the graph. Else print “No”.

// Note:
// You are not required to print the expected output, it has already been taken care of. Just implement the function.

// Constraints:

// 1 <= T <= 10
// 1 <= N <= 5000
// 0 <= M <= min(5000, (N * (N - 1)) / 2)
// 1 <= edges[i][0] <= N 
// 1 <= edges[i][1] <= N 

// Time Limit: 1 sec 

// Sample Input 1:

// 1
// 3 2
// 1 2
// 2 3

// Sample output 1:
// No


// Sample Input 2:
// 2
// 4 0 
// 4 3
// 1 4
// 4 3
// 3 1

// Sample output 2:
// No
// Yes

//Using BFS:
#include<queue>
bool hascycleBFS(int node, bool visited[], vector<int> adjlist[])
{
    queue<pair<int, int>> q;
    visited[node]=true;
    q.push({node, -1});
    while(!q.empty())
    {
        int curr=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(int nbr: adjlist[curr])
        {
            if(visited[nbr]==false)
            {
                visited[nbr]=true;
                q.push({nbr, curr});
            }
            else if(nbr!=parent)
                return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adjlist[n];
    for(int i=0; i<m; i++)
    {
        adjlist[edges[i][0]-1].push_back(edges[i][1]-1);
        adjlist[edges[i][1]-1].push_back(edges[i][0]-1);
    }
    bool visited[n]={false};
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            if(hascycleBFS(i, visited, adjlist))
                return "Yes";
        }
    }
    return "No";
}

//Using DFS:
bool hascycleDFS(pair<int, int> dual, bool visited[], vector<int> adjlist[])
{
    int node=dual.first;
    int parent=dual.second;
    visited[node]=true;
    for(int nbr: adjlist[node])
    {
        if(visited[nbr]==false)
        {
            if(hascycleDFS({nbr,node}, visited, adjlist))
                return true;
        }
        else if(nbr!=parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adjlist[n];
    for(int i=0; i<m; i++)
    {
        adjlist[edges[i][0]-1].push_back(edges[i][1]-1);
        adjlist[edges[i][1]-1].push_back(edges[i][0]-1);
    }
    bool visited[n]={false};
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            if(hascycleDFS({i,-1}, visited, adjlist))
                return "Yes";
        }
    }
    return "No";
}
