// Link: https://leetcode.com/problems/largest-multiple-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of digits
    // SC: O(1)
    // Approach:
    //  1. Count the frequency of each digit in the input vector.
    //  2. Calculate the sum of all digits.
    //  3. If the sum is divisible by 3, return the digits in descending order.
    //  4. If the sum is not divisible by 3, remove the smallest digit(s) to make the sum divisible by 3.
    //  5. Return the digits in descending order, or "0" if the result is empty or starts with '0'.
    string largestMultipleOfThree(vector<int> &digits)
    {
        string ans;
        vector<int> mod1{1, 4, 7, 2, 5, 8};
        vector<int> mod2{2, 5, 8, 1, 4, 7};
        vector<int> count(10);
        int sum = accumulate(digits.begin(), digits.end(), 0);

        for (const int digit : digits)
            ++count[digit];

        while (sum % 3 != 0)
            for (int i : sum % 3 == 1 ? mod1 : mod2)
                if (count[i])
                {
                    --count[i];
                    sum -= i;
                    break;
                }

        for (int digit = 9; digit >= 0; --digit)
            ans += string(count[digit], '0' + digit);

        return ans.size() && ans[0] == '0' ? "0" : ans;
    }
};