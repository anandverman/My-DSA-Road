// 75. Sort Colors
// Medium

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

 

// Constraints:

//     n == nums.length
//     1 <= n <= 300
//     nums[i] is either 0, 1, or 2.

//Basic approach: any sorting algorithm. Best O(nlogn) 

//Intermediate approach: Count Frequency of 0,1 and 2s. O(n)+O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                a++;
            if(nums[i]==1)
                b++;
            if(nums[i]==2)
                c++;        
        }
        int l=0;
        for(int i=0;i<a;i++)
            nums[l++]=0;
        for(int i=0;i<b;i++)
            nums[l++]=1;
        for(int i=0;i<c;i++)
            nums[l++]=2;
    }
};

//Advance Approach O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int lo=0,mid=0,hi=nums.size()-1;
        while(mid<=hi)
        {    
            if(nums[mid]==0)
            {
                swap(nums[lo],nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
        
    }
};