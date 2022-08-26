// 146. LRU Cache
// Medium

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

//     LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
//     add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
//     evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

 

// Constraints:

//     1 <= capacity <= 3000
//     0 <= key <= 104
//     0 <= value <= 105
//     At most 2 * 105 calls will be made to get and put.

// Code:
// Time Complexity:O(N)
// Space Complexity:O(1)
class Node
{
public:    
    int value,key;
    Node *prev,*next;
    Node(int ke,int val)
    {
        key=ke;
        value=val;
        prev=next=NULL;
    }
};

class LRUCache {
public:
    
    Node *head=new Node(-1,-1), *tail=new Node(-1,-1);
    int maxsize;
    unordered_map<int,Node*> umap;
    
    LRUCache(int capacity) 
    {
        maxsize=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
        void addNode(Node* neww)
        {
            Node *tmp=head->next;
            head->next=neww;
            tmp->prev=neww;
            neww->prev=head;
            neww->next=tmp;
        }
        
        void delNode(Node* del)
        {
            Node* delprev=del->prev;
            Node* delnext=del->next;
            delprev->next=delnext;
            delnext->prev=delprev;        
        }
    
    int get(int key) 
    {
        if(umap.find(key)!=umap.end())
        {
            Node* resnode=umap[key];
            delNode(resnode);
            addNode(resnode);
            return resnode->value;
        }
        else
            return -1;
    }
    
    void put(int key, int val) 
    {
        if(umap.find(key)!=umap.end())
        {            
            Node *old=umap[key];
            umap.erase(key);
            delNode(old);
        }
        
        if(umap.size()==maxsize)
        {
            umap.erase(tail->prev->key);
            delNode(tail->prev);
        } 
        
        addNode(new Node(key,val));
        umap[key]=head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */