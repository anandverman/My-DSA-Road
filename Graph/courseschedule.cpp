// 207. Course Schedule

// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array 
// prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is 
// impossible.

 

// Constraints:

//     1 <= numCourses <= 2000
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     All the pairs prerequisites[i] are unique.

//This problem Leetcode version of Detect cycle in a directed graph.

//Using BFS
class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjlist[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        int count=0;
        while(!q.empty())
        {
            count++;
            int node=q.front();
            q.pop();
            for(int nbr: adjlist[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        if(count==numCourses)
            return true;            
        return false;
    }
};

// Using DFS:
class Solution {
public:
    bool hascycle(int node, vector<bool> &visited, vector<bool> &dfsvisited, vector<list<int>> &adjlist)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto nbr: adjlist[node])
        {
            if(visited[nbr]==false)
            {
                if(hascycle(nbr, visited, dfsvisited, adjlist))
                    return true;
            }
            else if(dfsvisited[nbr]==true)
                return true;
        }
        dfsvisited[node]=false;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adjlist(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> dfsvisited(numCourses, false);
        int parent=-1;
        for(int i=0; i<numCourses; i++)
        {
            if(visited[i]==false)
                if(hascycle(i, visited, dfsvisited,  adjlist))
                    return false;
        }
        return true;
    }
};