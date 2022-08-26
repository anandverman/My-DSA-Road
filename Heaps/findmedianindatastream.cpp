// 295. Find Median from Data Stream
// Hard

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value 
// and the median is the mean of the two middle values.

//     For example, for arr = [2,3,4], the median is 3.
//     For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

// Implement the MedianFinder class:

//     MedianFinder() initializes the MedianFinder object.
//     void addNum(int num) adds the integer num from the data stream to the data structure.
//     double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

 

// Constraints:

//     -105 <= num <= 105
//     There will be at least one element in the data structure before calling findMedian.
//     At most 5 * 104 calls will be made to addNum and findMedian.


// Code:
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> right; // contains all bigger elements is a minheap
    priority_queue<int> left; // contains all smaller elements is a maxheap
    MedianFinder() {
        
    }
//     We make sure that 1 of the following conditions is always true:
//     left.size() == right.size()
//     right.size() - 1 = left.size()

    void addNum(int num) {
        if(right.size() == left.size())
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() 
    {
        if(right.empty())
            return 0;
        else if(right.size() == left.size())
            return (left.top() + right.top()) / 2.0;
        else 
            return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */