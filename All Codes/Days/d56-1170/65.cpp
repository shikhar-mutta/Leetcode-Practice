// Link: https://leetcode.com/problems/valid-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string
    // SC: O(1) as we are using constant space
    // Approach:
    //    1. Initialize three boolean variables: seenDigit, seenDot, and seenExp to keep track of whether we have seen a digit, a dot, or an exponent in the string.
    //    2. Iterate through each character in the input string.
    //    3. If the character is a digit, set seenDigit to true.
    //    4. If the character is a '+' or '-', check if it is at the beginning of the string or immediately after an 'e' or 'E'. If not, return false.
    //    5. If the character is a dot, check if we have already seen a dot or an exponent. If so, return false. Otherwise, set seenDot to true.
    //    6. If the character is an 'e' or 'E', check if we have already seen an exponent or if we haven't seen a digit yet. If either condition is true, return false. Otherwise, set seenExp to true and reset seenDigit to false.
    //    7. If the character is none of the above, return false.
    bool isNumber(string s)
    {
        bool seenDigit = false, seenDot = false, seenExp = false;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (isdigit(c))
                seenDigit = true;
            else if (c == '+' || c == '-')
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.')
            {
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E')
            {
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                seenDigit = false;
            }
            else
                return false;
        }
        return seenDigit;
    }
};
