// Link: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        // Check each number in the range [left, right]
        for (int n = left; n <= right; n++)
        {
            bool covered = false;
            for (auto &r : ranges)
                if (r[0] <= n && n <= r[1])
                { // If n is covered by the current range, mark it as covered and break out of the loop
                    covered = true;
                    break;
                }
            if (!covered)
                return false;
        }
        return true;
    }
};
