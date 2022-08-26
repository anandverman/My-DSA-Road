// 460. LFU Cache
// Hard

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

//     LFUCache(int capacity) Initializes the object with the capacity of the data structure.
//     int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
//     void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
//     When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting 
//     a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently 
//     used key would be invalidated.

// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the 
// smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter 
// for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

 

// Constraints:

//     0 <= capacity <= 104
//     0 <= key <= 105
//     0 <= value <= 109
//     At most 2 * 105 calls will be made to get and put.

// Optimal Code:

class Node
{
public:    
    int key,value,freq;
    Node *next,*prev;
    Node(int k, int v)
    {
        key=k;
        value=v;
        freq=1;
    }
};

class List
{
public:    
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int size;
    List()
    {
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addNode(Node* neww)
    {
        Node *tmp=head->next;
        tmp->prev=neww;
        head->next=neww;
        neww->prev=head;
        neww->next=tmp;
        size++;
    }
    
    void delNode(Node *del)
    {
        Node* delprev=del->prev;
        Node* delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int,List*> freqList;      
    //map for maintaining lists of different frequencies by providing direct access to list by the frequency of nodes in the list
    unordered_map<int,Node*> keyNode;       //map for direct access to nodes by their keys
    int cachesize, minfreq, currsize;    
    
    LFUCache(int capacity) 
    {
        cachesize=capacity;
        minfreq=0;
        currsize=0;
    }
    
    void updatefreqList(Node * node)   //function to update the node's freq and its location in the lists of freqList map or the cache
    {
        // keyNode.erase(node->key);       //erase the node from the keyNode map its key (not needed as node is not being removed from the cache)
        freqList[node->freq]-> delNode(node);       //remove node from its list with current frequency in freqList map
        
        if(node->freq == minfreq and freqList[node->freq]->size ==0)        //check if node has frequncy as minfreq and size of the list with minfreq after removing the node is 0
            minfreq++;              //increment minfreq as there is no node with current minfreq
        
        List* nextHighfreq = new List();        //create new list name nexHighfreqq
        if(freqList.find(node->freq+1) != freqList.end())       //check if there is a list with freq one greater than current frequency of node
        {
            nextHighfreq = freqList[node->freq+1];      //if list exist, update nextHighfreq to point to the list with the one greater frequency
        }
        
        node->freq+= 1;         //update the freq of the node as it(the node) was accessed
        nextHighfreq->addNode(node);        //add the node to front of the list with new frequency.
        freqList[node->freq]= nextHighfreq;     //update the existing list with new frequency in freqList map
        // keyNode[node->key]= node;       //reinsert the node in keyNode map.
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end())      //check if node with given key exists in keyNode map or cache, and if found do:
        {
            Node* node = keyNode[key];      //create pointer to the node with given key named node
            int val= node->value;       //get value of the node with given key
            updatefreqList(node);       //update the freqListmap and freq of node as freq of node is increased as it is accessed
            return val;
        }
        return -1;      //node with given key is not found in cache so return -1
    }
    
    void put(int key, int value) 
    {   
        if(cachesize==0)     //if cachesize is 0 it cannot hold anything
            return;
        
        if(keyNode.find(key)!=keyNode.end())    //check of node with given key exists, if it does update its value and freq and freqListmap.
        {
            Node* node=keyNode[key];    //create pointer to node with given key
            node->value=value;          //update the value of the node
            updatefreqList(node);       //update the freq of given node and freqListmap
        }        
        else
        {
            if(currsize ==cachesize)        //check if cache is already filled, remove least frequently used node
            {
                List* list = freqList[minfreq];     //go to list with min frequency
                keyNode.erase(list->tail->prev->key);       //remove the mapping of last node with min frequency i.e. least used node with minimum frequency
                freqList[minfreq]->delNode(list->tail->prev);      //remove the least used node with minimum frequency
                currsize--;     //decrement current cache size
            }
            
            currsize++;     //change size of cache as new node will be added
            
            //Following code adds new node with given key,value to cache
            
            minfreq =1;        //minimum value of frequency is 1 for new node
            
            List* listfreq =new List();     //create a new empty list pointed by listfreq
            if(freqList.find(minfreq)!= freqList.end())     //check of list with minfreq exists
            {
                listfreq= freqList[minfreq];        //update listfreq to point to list with minfreq i.e. 1
            }
            Node* node = new Node(key, value);      //Create a new node with given key,value and freq 1
            listfreq->addNode(node);        //add the new node to front of list with freq 1
            keyNode[key]= node;         //map node with key in keyNode map
            freqList[minfreq]= listfreq;        //update list with minfreq in freqList map
        }        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */