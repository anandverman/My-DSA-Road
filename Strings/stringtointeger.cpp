// 8. String to Integer (atoi)
// Medium

// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

//     Read in and ignore any leading whitespace.
//     Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either.
//     This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
//     Read in next the characters until the next non-digit character or the end of the input is reached.
//     The rest of the string is ignored.
//     Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. 
//     Change the sign as necessary (from step 2).
//     If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it 
//     remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 
//     should be clamped to 231 - 1.

//     Return the integer as the final result.

// Note:

//     Only the space character ' ' is considered a whitespace character.
//     Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

 

// Example 1:

// Input: s = "42"
// Output: 42
// Explanation: The underlined characters are what is read in, the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^
// The parsed integer is 42.
// Since 42 is in the range [-231, 231 - 1], the final result is 42.

// Example 2:

// Input: s = "   -42"
// Output: -42
// Explanation:
// Step 1: "   -42" (leading whitespace is read and ignored)
//             ^
// Step 2: "   -42" ('-' is read, so the result should be negative)
//              ^
// Step 3: "   -42" ("42" is read in)
//                ^
// The parsed integer is -42.
// Since -42 is in the range [-231, 231 - 1], the final result is -42.

// Example 3:

// Input: s = "4193 with words"
// Output: 4193
// Explanation:
// Step 1: "4193 with words" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
//              ^
// The parsed integer is 4193.
// Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

 

// Constraints:

//     0 <= s.length <= 200
//     s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

//Solution:
class Solution {
public:
    long long toint(char ch)
    {
        switch(ch)
        {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;              
        }           
        return -1;
    }
    
    bool isnum(char ch)
    {
        if(ch>='0' and ch<='9')
            return true;
        return false;
    }
    
    int myAtoi(string s) {
        int n=s.length();
        long long val=0,sign=1;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ' or s[i]=='-' or s[i]=='+' or isnum(s[i]))
            {
                if(s[i]=='+' or s[i]=='-')
                {
                    if(!isnum(s[i+1]))
                        break;       
                    if(s[i]=='-')   
                        sign=-1;                        
                }

                if(isnum(s[i]))
                {
                    val=val*10+toint(s[i]);
                    if(val>INT_MAX)
                    {
                        if(sign<0)
                            return INT_MIN;
                        return INT_MAX;
                    }

                }
                if(isnum(s[i]) and !isnum(s[i+1]))
                    break;
            }
            else 
                break;
        }
        val*=sign;
        return val;
    }
};