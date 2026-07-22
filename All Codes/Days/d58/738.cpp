// Link: https://leetcode.com/problems/monotone-increasing-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) and SC: O(log n)
    //   Approach:
    //   1. Convert the number to a string to easily manipulate its digits.
    //   2. Iterate through the string from right to left, checking if the current digit is less than the previous digit.
    //   3. If it is, decrement the previous digit and mark the position where the change occurred.
    //   4. After processing all digits, set all digits to the right of the marked position to '9' to ensure the number is the largest possible monotone increasing number.
    //   5. Convert the string back to an integer and return it.
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        int mark = s.size();
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i - 1] > s[i])
            {
                s[i - 1]--;
                mark = i;
            }
        }
        for (int i = mark; i < (int)s.size(); i++)
            s[i] = '9';
        return stoi(s);
    }
};
