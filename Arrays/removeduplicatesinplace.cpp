// 26. Remove Duplicates from Sorted Array
// Easy

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element 
// appears only once. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed 
// in the first part of the array nums. More formally, if there are k elements after removing the duplicates, 
// then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).


// Constraints:

//     1 <= nums.length <= 3 * 104
//     -100 <= nums[i] <= 100
//     nums is sorted in non-decreasing order.

// Approach 1: BruteForce

//     Declare a HashSet.
//     Run a for loop from starting to the end.
//     Put every element of the array in the set.
//     Store size of the set in a variable K.
//     Now put all elements of the set in the array from the starting of the array.
//     Return K.

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 

int removeDuplicates(int arr[]) {
  set < int > set;
  for (int i = 0; i < 7; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

// Approach 2: Optimized Approach using two pointers

// Time complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0,k=1,n=nums.size();
        while(k!=n)
        {
            if(nums[i]!=nums[k])
                nums[++i]=nums[k];
            k++;
        }
        return i+1;
    }
};