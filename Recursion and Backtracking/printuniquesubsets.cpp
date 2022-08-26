// 90. Subsets II
// Medium

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

 

// Constraints:

//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10

//Solution using Recursion

class Solution {
public:
    void subsets(vector<int> &arr, set<vector<int>> &ans, vector<int> cur, int ptr)
    {
        if(ptr==arr.size())
        {
            sort(cur.begin(),cur.end());
            ans.insert(cur);
            return;
        }
        subsets(arr,ans,cur,ptr+1);
        cur.push_back(arr[ptr]);
        subsets(arr,ans,cur,ptr+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> ans;
        vector<int>cur;
        subsets(nums,ans,cur,0);
        vector<vector<int>> res;
        for(auto i:ans)
            res.push_back(i);
        return res;
    }
};