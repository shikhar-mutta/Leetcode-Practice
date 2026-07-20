// Link: https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(N)
    // Approach:
    // 1. We can use a hash map to store the remainder and its corresponding index in the fractional part of the result.
    // 2. We can then perform long division to calculate the fractional part of the result. If we encounter a remainder that we have seen before, we know that the fractional part is repeating, and we can insert parentheses around the repeating part.
    // 3. We can continue this process until the remainder becomes 0 or we encounter a repeating remainder.
    // 4. Finally, we can concatenate the integer part and the fractional part to get the final result.
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0)
            return result;
        string frac;
        unordered_map<long long, int> seen;
        while (rem != 0)
        {
            if (seen.count(rem))
            {
                frac.insert(seen[rem], "(");
                frac += ")";
                break;
            }
            seen[rem] = frac.size();
            rem *= 10;
            frac += to_string(rem / den);
            rem %= den;
        }
        result += "." + frac;
        return result;
    }
};
