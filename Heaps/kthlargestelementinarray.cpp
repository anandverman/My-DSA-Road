// 215. Kth Largest Element in an Array
// Medium

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

 

// Constraints:

//     1 <= k <= nums.length <= 104
//     -104 <= nums[i] <= 104

// Code:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> heap(nums.begin(),nums.end());
        while(--k)
        {
            heap.pop();
        }
        return heap.top();
    }
};

// OR

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

// OR

//Solution:
// Time complexity: O(n) , where n = size of the array
// Space complexity: O(1) 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1, res;
        while(true) {
            int index = partition(nums, left, right);
            if(index==k-1) {
                res = nums[index]; break;
            }
            if(index<k-1) {
                left = index+1;
            }
            else if(index>k-1) {
                right = index-1;
            }
        }
        return res;
    }
    
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left], l = left+1, r = right;
        while(l<=r) {
            if(nums[l]<pivot && nums[r]>pivot) {
                swap(nums[l], nums[r]);
                l++; r--;
            }
            if(nums[l]>=pivot) {
                l++;
            }
            if(nums[r]<=pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};