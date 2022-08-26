// 239. Sliding Window Maximum
// Hard

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the 
// array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104
//     1 <= k <= nums.length

// Naive Approach: Time Complexity: O(N^2) Space Complexity O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        vector<int> ans;
        int n=arr.size()   ;
        for(int i=0; i<=n-k; i++)
        {
            int maxval=-10000;
            for(int j=0; j<k; j++)
            {
                maxval=max(maxval,arr[i+j]);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};

//Optimal Approach: Striver Approach: https://youtu.be/CZQGRp93K4k
// Time Complexity: O(N)
// Space Complexity: O(K)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<arr.size(); i++)
        {
            if(!dq.empty() and dq.front()==i-k)
                dq.pop_front();
            
            while(!dq.empty() and arr[dq.back()]<=arr[i])            
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
