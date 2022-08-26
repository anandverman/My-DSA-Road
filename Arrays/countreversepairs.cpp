// 493. Reverse Pairs
// Hard

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2

// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     -231 <= nums[i] <= 231 - 1

//Approach 1: Brute Force gives TLE on large arrays
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size(),c=0;
            for(int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++)
                {
                    if((long long)nums[i]>(long long)2*nums[j])
                        c++;
                }
        return c;
    }
};

//Approach 2: Optimized Approach using Merge Sort
class Solution {
public:
    
    int merge(vector<int> &nums, int left, int mid, int right)
    {
        int count=0;
        int i=left;
        int j=mid+1;
        vector<int> t;
        for(;i<=mid;i++){
            while(j<=right and (long long)nums[i]>(long long)2*nums[j])
                j++;
            count+=j-(mid+1);
        }
        i=left;
        j=mid+1;
        while(i<=mid and j<=right)
        {
            if(nums[i]<nums[j])         
                t.push_back(nums[i++]);
            else
                t.push_back(nums[j++]);
        }
        while(i<=mid)
            t.push_back(nums[i++]);
        while(j<=right)
            t.push_back(nums[j++]);
        for(i=left;i<=right;i++)
            nums[i]=t[i-left];
        return count;
    }
    
    int mergsort(vector<int> &nums, int left, int right)
    {
        int count=0,mid;
        if(left>=right)
            return 0;
        {
            mid=(left+right)/2;
            count+=mergsort(nums,left,mid);
            count+=mergsort(nums,mid+1,right);
            count+=merge(nums,left,mid,right);         
        }
        return count;
    }
    int reversePairs(vector<int>& nums) 
    {
        return mergsort(nums,0,nums.size()-1);
    }
};