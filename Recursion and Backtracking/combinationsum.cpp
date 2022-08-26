// 39. Combination Sum
// Medium

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:

// Input: candidates = [2], target = 1
// Output: []

 

// Constraints:

//     1 <= candidates.length <= 30
//     1 <= candidates[i] <= 200
//     All elements of candidates are distinct.
//     1 <= target <= 500

//Solution using recursion:
class Solution {
public:
    void recursion(vector<int> &arr, vector<vector<int>> &ans, vector<int> cur, int ptr, int target)
    {
        if(target<0 or ptr==arr.size())
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(cur);
            return;
        }
        recursion(arr,ans,cur,ptr+1,target);
        cur.push_back(arr[ptr]);
        recursion(arr,ans,cur,ptr,target-arr[ptr]);      
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        vector<vector<int>> ans;
        recursion(candidates,ans,cur,0,target);
        return ans;
    }
};
