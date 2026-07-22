// Link: https://leetcode.com/problems/maximum-swap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of digits in the number, as we iterate through the digits twice (once to record the last occurrence of each digit and once to find the swap).
    // SC: O(n) where n is the number of digits in the number, as we store the last occurrence of each digit in a vector of size 10 (for digits 0-9).
    //   Approach:
    //   1. Convert the number to a string to easily access its digits.
    //   2. Create a vector to store the last occurrence index of each digit (0-9).
    //   3. Iterate through the digits of the number. For each digit, check if there is a larger digit that occurs later in the number.
    //   4. If such a larger digit is found, swap the current digit with the last occurrence of that larger digit and return the new number.
    //   5. If no swap is made after checking all digits, return the original number as it is already the largest possible.
    //   6. The function returns the maximum number that can be obtained by swapping two digits at most once.
    int maximumSwap(int num)
    {
        string s = to_string(num);
        vector<int> last(10, -1);
        for (int i = 0; i < (int)s.size(); i++)
            last[s[i] - '0'] = i;
        for (int i = 0; i < (int)s.size(); i++)
        {
            for (int d = 9; d > s[i] - '0'; d--)
            {
                if (last[d] > i)
                {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
