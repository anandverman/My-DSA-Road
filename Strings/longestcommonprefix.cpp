// 14. Longest Common Prefix
// Easy

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

 

// Constraints:

//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//     strs[i] consists of only lowercase English letters.

//Solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1)
            return strs[0];
        string ans="";
        int flag=0;
        for(int k=0; k<strs[0].size(); k++)
        {
            for(int i=0;i<n-1;i++)
            {
                if(strs[i][k]==strs[i+1][k])
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                ans+=strs[0][k];
            else
                return ans;
        }
        return ans;
    }
};