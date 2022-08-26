// 133. Clone Graph
// Medium

// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, 
// the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of 
// neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to 
// the cloned graph.

// Example 1:

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

// Example 2:

// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does 
// not have any neighbors.

// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.

 

// Constraints:

//     The number of nodes in the graph is in the range [0, 100].
//     1 <= Node.val <= 100
//     Node.val is unique for each node.
//     There are no repeated edges and no self-loops in the graph.
//     The Graph is connected and all nodes can be visited starting from the given node.

//My Solution: Using BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*, Node*> nodemap;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty())       //Using BFS to create copy of each node
        {
            Node* root=q.front();
            Node* copy=new Node(root->val);
            nodemap[root]=copy;
            q.pop();
            for(auto nbr:root->neighbors)
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        for(auto i:visited)     //Traverse each node and add neighbors to copy of each node.
        {
            Node* root=i.first;
            Node* copy=nodemap[root];
            for(auto nbr: root->neighbors)
            {
                copy->neighbors.push_back(nodemap[nbr]);
            }
        }
        return nodemap[node];
    }
};

//Using BFS:

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node) return NULL;
        
        map<Node*, Node*> oldNewMap;    //map for node and its copy.
        queue<Node*> q;
        Node *newNode, *newNeighbor;
        
        q.push(node);
        
        while(!q.empty()) 
        {
            Node* cur=q.front(); 
            q.pop();
            if(oldNewMap.find(cur) == oldNewMap.end())      //if copy of node not found in map
            {
                newNode=new Node(cur->val);     //  create copy of node
                oldNewMap[cur]=newNode;         //  update map and add copy of node
            }
            else 
            {
                newNode=oldNewMap[cur];         //copy already exits
            }
            
            for(auto nbr :cur->neighbors)       //  for neighbors of current node
            {        
                if(oldNewMap.find(nbr)==oldNewMap.end())    //if copy of neighbour does not exit in map
                {
                    newNeighbor = new Node(nbr->val);         //create copy of neighbor
                    oldNewMap[nbr]=newNeighbor;             //update nbr's newly create copy in map
                    q.push(nbr);                      
                }
                else {
                    newNeighbor = oldNewMap[nbr];       //newneighbor = copy of nbr from map
                }
                (newNode->neighbors).push_back(newNeighbor);    //add newneighbour to neighbors of copy of cur
            }
        }
        return oldNewMap[node];     
    }
};

//Using DFS:
class Solution {
    Node* clonegrph(Node* curr, unordered_map<Node*, Node*>&mp)
    {
        vector<Node*> neighbour;
        Node* clone = new Node(curr->val);
        mp[curr] = clone;
        for(auto x: curr->neighbors)
        {
            if(mp.find(x)!=mp.end())
            {
                neighbour.push_back(mp[x]);
            }
            else
            {
                neighbour.push_back(clonegrph(x,mp));
            }
        }
        clone->neighbors = neighbour;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*, Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return clonegrph(node,mp);
    }
};