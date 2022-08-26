// 5. Longest Palindromic Substring
// Medium

// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

 

// Constraints:

//     1 <= s.length <= 1000
//     s consist of only digits and English letters.

// Without Dynamic Programming.
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.length(),anslen=0;
        string ans;
        int start;
        for(int i=0; i<n; i++)
        {
            int left=i;
            int right=i;
            while(left>=0 and right<n and s[left]==s[right])
            {
                int len= right-left+1;
                if(len > anslen)
                {
                    anslen=len;
                    start=left;
                }
                left--;
                right++;
            }

            
            left=i;
            right=i+1;
            while(left>=0 and right<n and s[left]==s[right])
            {
                int len= right-left + 1;
                if(len > anslen)
                {
                    anslen=len;
                    start=left;
                }
                left--;
                right++;
            }
        }
        ans=s.substr(start,anslen);
        return ans;
    }
};

//Solution: Using Dynamic Programming (GFG) https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/.

class Solution {
public:
    string longestPalindrome(string str) 
    {
        string ans;
         int n = str.size();

            // table[i][j] will be false if substring
            // str[i..j] is not palindrome.
            // Else table[i][j] will be true
            bool table[n][n];

            memset(table, 0, sizeof(table));

            // All substrings of length 1
            // are palindromes
            int maxLength = 1;

            for (int i = 0; i < n; ++i)
                table[i][i] = true; //set diagonals true

            // check for sub-string of length 2.
            int start = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (str[i] == str[i + 1]) {
                    table[i][i + 1] = true;
                    start = i;
                    maxLength = 2;
                }
            }

            // Check for lengths greater than 2.
            // k is length of substring
            for (int k = 3; k <= n; ++k) {
                // Fix the starting index
                for (int i = 0; i < n - k + 1; ++i) {
                    // Get the ending index of substring from
                    // starting index i and length k
                    int j = i + k - 1;

                    // checking for sub-string from ith index to
                    // jth index iff str[i+1] to str[j-1] is a
                    // palindrome
                    if (table[i + 1][j - 1] && str[i] == str[j]) {
                        table[i][j] = true;

                        if (k > maxLength) {
                            start = i;
                            maxLength = k;
                        }
                    }
                }
            }

        for(int i=start; i<start+maxLength; i++)
            ans+=str[i];
        return ans;
    }
};