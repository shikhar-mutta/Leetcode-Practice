// Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of digits in the input number.
// SC: O(n) where n is the number of digits in the input number.
// Approach:
//   1. We will convert the input number to a string.
//   2. We will create two strings, hi and lo, which will represent the highest and lowest numbers we can get by changing the digits of the input number.
//   3. We will iterate through the digits of the input number and for each digit, we will check if it is not '9'. If it is not '9', we will replace all occurrences of that digit in the hi string with '9' and break the loop.
//   4. We will iterate through the digits of the input number again and for each digit, we will check if it is not '0' or '1'. If it is not '0' or '1', we will replace all occurrences of that digit in the lo string with '0' and break the loop. If the first digit is not '1', we will replace all occurrences of the first digit in the lo string with '1' and break the loop.
//   5. Finally, we will return the difference between the integer values of the hi and lo strings.
class Solution
{
public:
    int maxDiff(int num)
    {
        string s = to_string(num);

        string hi = s;
        for (char c : s)
        {
            if (c != '9')
            {
                replace(hi.begin(), hi.end(), c, '9');
                break;
            }
        }

        string lo = s;
        if (s[0] != '1')
        {
            replace(lo.begin(), lo.end(), s[0], '1');
        }
        else
        {
            for (int i = 1; i < s.size(); ++i)
            {
                if (s[i] != '0' && s[i] != '1')
                {
                    replace(lo.begin(), lo.end(), s[i], '0');
                    break;
                }
            }
        }

        return stoi(hi) - stoi(lo);
    }
};
