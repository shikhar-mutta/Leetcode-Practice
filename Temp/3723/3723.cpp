// Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(num) SC: O(num)
// Approach: infeasible if 9*num < sum. Otherwise, since squaring
// rewards concentrating value into fewer large digits, use as many 9s
// as possible: k = sum/9 nines, then one digit for the remainder
// sum%9 (if nonzero), then pad with 0s to reach `num` digits. This
// greedy digit sequence (9s, remainder, 0s) is simultaneously the
// max-score AND the largest arrangement of that digit multiset.
class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if ((long long)num * 9 < sum)
            return "";
        int k = sum / 9;
        int rem = sum % 9;
        string result(k, '9');
        if (rem > 0)
            result += (char)('0' + rem);
        result += string(num - (int)result.size(), '0');
        return result;
    }
};
