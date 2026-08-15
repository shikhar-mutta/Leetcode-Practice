// Link: https://leetcode.com/problems/check-good-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: sum digits and sum squared digits, check the difference.
class Solution
{
public:
    bool checkGoodInteger(int n)
    {
        int digitSum = 0, squareSum = 0;
        for (char c : to_string(n))
        {
            int d = c - '0';
            digitSum += d;
            squareSum += d * d;
        }
        return squareSum - digitSum >= 50;
    }
};
