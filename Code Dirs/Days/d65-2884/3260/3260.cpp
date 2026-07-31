// Link: https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^n) where n is the number of digits in the palindrome
// SC: O(n) where n is the number of digits in the palindrome
// Approach: The problem requires us to find the largest palindrome of length n that is divisible by k. We can start by constructing a palindrome of length n with all digits as '9'. Then, we can check if this palindrome is divisible by k. If it is not, we can systematically change the center digit(s) of the palindrome from '9' downwards until we find a palindrome that is divisible by k. We need to handle different cases based on the value of k, as certain values of k impose specific constraints on the digits of the palindrome (e.g., even digits for divisibility by 2, last digit being 0 or 5 for divisibility by 5, etc.).
class Solution
{
private:
    // Helper function to check if a large string number is divisible by k
    bool isDivisible(const std::string &s, int k)
    {
        int remainder = 0;
        for (char c : s)
        {
            remainder = (remainder * 10 + (c - '0')) % k;
        }
        return remainder == 0;
    }

public:
    string largestPalindrome(int n, int k)
    {
        // Base structure: Start with all '9's
        std::string ans(n, '9');

        // Case 1: k = 1, 3, 9
        // A string of all 9s is automatically divisible by 1, 3, and 9.
        if (k == 1 || k == 3 || k == 9)
        {
            return ans;
        }

        // Case 2: k = 2
        // Must end in an even digit. To maximize, outer digits are '8'.
        if (k == 2)
        {
            ans[0] = '8';
            ans[n - 1] = '8';
            return ans;
        }

        // Case 3: k = 5
        // Must end in 0 or 5. Since leading zeros aren't allowed, outer digits
        // are '5'.
        if (k == 5)
        {
            ans[0] = '5';
            ans[n - 1] = '5';
            return ans;
        }

        // Case 4: k = 4
        // Last two digits must form a multiple of 4. To maximize, ends are
        // "88".
        if (k == 4)
        {
            if (n <= 4)
            {
                return std::string(n, '8');
            }
            ans[0] = '8';
            ans[1] = '8';
            ans[n - 2] = '8';
            ans[n - 1] = '8';
            return ans;
        }

        // Case 5: k = 8
        // Last three digits must form a multiple of 8. To maximize, ends are
        // "888".
        if (k == 8)
        {
            if (n <= 6)
            {
                return std::string(n, '8');
            }
            ans[0] = '8';
            ans[1] = '8';
            ans[2] = '8';
            ans[n - 3] = '8';
            ans[n - 2] = '8';
            ans[n - 1] = '8';
            return ans;
        }

        // Case 6: k = 6
        // Must be even (starts/ends with 8) and digit sum must be divisible
        // by 3.
        if (k == 6)
        {
            if (n == 1)
                return "6";
            if (n == 2)
                return "66";

            ans[0] = '8';
            ans[n - 1] = '8';

            // Greedily change the center digit(s) from '9' downwards
            if (n % 2 == 1)
            { // Odd length: 1 center element
                for (char c = '9'; c >= '0'; --c)
                {
                    ans[n / 2] = c;
                    if (isDivisible(ans, 3))
                        return ans;
                }
            }
            else
            { // Even length: 2 center elements
                for (char c = '9'; c >= '0'; --c)
                {
                    ans[(n / 2) - 1] = c;
                    ans[n / 2] = c;
                    if (isDivisible(ans, 3))
                        return ans;
                }
            }
        }

        // Case 7: k = 7
        // Start with all '9's and systematically change the center element(s)
        if (k == 7)
        {
            if (n % 2 == 1)
            { // Odd length
                for (char c = '9'; c >= '0'; --c)
                {
                    ans[n / 2] = c;
                    if (isDivisible(ans, 7))
                        return ans;
                }
            }
            else
            { // Even length
                for (char c = '9'; c >= '0'; --c)
                {
                    ans[(n / 2) - 1] = c;
                    ans[n / 2] = c;
                    if (isDivisible(ans, 7))
                        return ans;
                }
            }
        }

        return ans;
    }
};
