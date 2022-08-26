// 152. Maximum Product Subarray
// Medium

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, 
// and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -10 <= nums[i] <= 10
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// 152. Maximum Product Subarray
// Medium

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and 
// return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -10 <= nums[i] <= 10
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//Solution 1 TC: O(n), SC: O(n) 
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans=nums[0], prod1=ans, prod2=ans;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)
                swap(prod1,prod2);
            prod1=max(nums[i], prod1*nums[i]);
            prod2=min(nums[i], prod2*nums[i]);
            ans=max(ans,prod1);
        }
        return ans;
    }
};

// or

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans=nums[0], prod1=nums[0], prod2=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            int tmp=max({nums[i], prod1*nums[i], prod2*nums[i]});
            prod2=min({nums[i], prod1*nums[i], prod2*nums[i]});
            prod1=tmp;
            ans=max(ans,prod1);
        }
        return ans;
    }
};

//Solution 2 TC: O(n), SC: O(2n)==O(n)  
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxleft=INT_MIN;
        int maxright=INT_MIN;
        bool zero=false;
        int prod=1;
        for(auto i:nums)
        {
            prod*=i;
            if(i==0)
            {
                zero=true;
                prod=1;
                continue;
            }
            maxleft=max(maxleft, prod);
        }
        prod=1;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            prod*=nums[i];
            if(nums[i]==0)
            {
                zero=true;
                prod=1;
                continue;
            }
            maxright=max(maxright, prod);
        }
        if(zero)
            return  max(max(maxleft,maxright), 0);
        return max(maxleft,maxright);
    }
};