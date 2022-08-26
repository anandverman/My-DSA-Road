// 3. Longest Substring Without Repeating Characters
// Medium

// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.

//Approach 1 Naive Approach (BruteForce): Make all Subarray and count each subarray with unique characters occuring once.
//Striver's solution (needs fixing)
#include<bits/stdc++.h>

using namespace std;

int solve(string str) {
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

// Solution 2: Optimised  Approach 1

// Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point
// of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and 
// check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead 
// so as to delete the duplicate elements.

//My Solution:TC:O(2n), SC:O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_set<int> set;
        int l=0;
        for(int r=0;r<s.length();r++)
        {
            if(set.find(s[r])!=set.end()) //If duplicate letter found
            {
                while(l<r and set.find(s[r])!=set.end())
                {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

// Solution 3: Optimised  Approach 2

// Approach: In this approach, we will make a map that will take care of counting the elements and 
// maintaining the frequency of each and every element as a unity by taking the latest index of every element.

//My Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<int,int> set;//can use <char,int> type also
        int l=0;
        for(int r=0;r<s.length();r++)
        {
            if(set.find(s[r])!=set.end() and l<r) //If duplicate letter found
            {                
                    l=max(l,set[s[r]]+1);
            }
            set[s[r]]=r;;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

//Striver Solution
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};