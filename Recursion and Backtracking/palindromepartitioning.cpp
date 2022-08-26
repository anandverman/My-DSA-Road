// 131. Palindrome Partitioning
// Medium

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:

// Input: s = "a"
// Output: [["a"]]

 

// Constraints:

//     1 <= s.length <= 16
//     s contains only lowercase English letters.

//Optimized Solution
class Solution {
public:
    
    bool ispalindrome(string s,int start,int end)
    {
        while (start < end) 
        {
          if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    
    void recursion(string s, int ptr, vector<vector<string>> &ans, vector<string> &cur)
    {
        if(ptr==s.length())
        {
            ans.push_back(cur);
            return;
        }
        for( int i=ptr; i<s.length(); i++)
        {
            if(ispalindrome(s,ptr,i))
            {                
                cur.push_back(s.substr(ptr,i-ptr+1));
                recursion(s,i+1,ans,cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        recursion(s,0,ans,cur);
        return ans; 
    }
};