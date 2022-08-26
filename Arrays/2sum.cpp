// 1. Two Sum
// Easy

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

 

// Constraints:

//     2 <= nums.length <= 104
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109
//     Only one valid answer exists.

 
// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

//Approach 1: Brute Force 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
            if(not res.empty())
                break;
        }
        return res;
    }
    
};

//Approach 2: Optimal Approach: TC: O(nlogn+2n) SC: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res,copy;
        copy=nums;
        sort(copy.begin(),copy.end());
        int left=0,right=copy.size()-1;
        while(left<right)
        {
            if(copy[left]+copy[right]==target)
            {
                left=copy[left];
                right=copy[right];
                break;
            }
            else if(copy[left]+copy[right]>target)
                right--;
            else
                left++;
        }       
        
        
        for(int i=0;i<nums.size();i++)
        { 
            if(nums[i]==left)             
                res.push_back(i);
            else if(nums[i]==right)
                res.push_back(i);
            if(res.size()==2)
                break;
        }
        return res;
    }
    
};