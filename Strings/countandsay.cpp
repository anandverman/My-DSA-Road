// 38. Count and Say
// Medium

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

//     countAndSay(1) = "1"
//     countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different 
//     digit string.

// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains 
// exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every 
// said digit.

// For example, the saying and conversion for digit string "3322251":

// Given a positive integer n, return the nth term of the count-and-say sequence.

 

// Example 1:

// Input: n = 1
// Output: "1"
// Explanation: This is the base case.

// Example 2:

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

// Constraints:

//     1 <= n <= 30

//Recursive Solution
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s=countAndSay(n-1);
        int len=s.length();
        int i=0;
        string ret="";
        while(i<len)
        {
            char ch=s[i];
            int freq=1;
            while(i+1<len and s[i+1]==ch)
            {
                freq++;
                i++;
            }            
            ret+=(48+freq);
            ret+=ch;
            i++;
        }
        return ret;
    }
};

//Iterative Solution
class Solution {
public:
    string countAndSay(int n) 
    {
        if(n == 1) return "1";
        if(n==2) return "11";
        
        string str = "11";
        
        for(int i = 3 ; i<= n ; i++)
        {
            
            str += '$';
            int len = str.length();
            string tmp = "";
            int cnt = 1;
            
            for(int j = 1 ;j<len;++j)
            {
                
                if(str[j]!=str[j-1])
                {
                    tmp += cnt +'0';
                    
                    tmp += str[j-1];
                    
                    cnt=1;
                }
                else
                {
                    cnt++;
                }
            }    
            str = tmp;
        }
        return str;
    }
};