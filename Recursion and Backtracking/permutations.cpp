// 46. Permutations
// Medium

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

 

// Constraints:

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.

//Solution using recursion and backtracking

class Solution {
public:
    void permutate(vector<int> &arr, int ptr, vector<vector<int>> &res)
    {
        if(ptr==arr.size())
        {
            res.push_back(arr);
            return;
        }
        for(int i=ptr;i<arr.size();i++)
        {
            swap(arr[i],arr[ptr]);
            permutate(arr,ptr+1,res);
            swap(arr[i],arr[ptr]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        permutate(nums, 0, res);
        return res;
    }
};