// Link: https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n)
    // SC: O(n)
    //  Approach:
    //  1. Group the numbers based on their modulo k value.
    //  2. For each group, use dynamic programming to count the number of beautiful subsets
    //     a. Let f be the number of beautiful subsets that do not include the current number.
    //     b. Let g be the number of beautiful subsets that include the current number
    //     c. If the current number is not adjacent to the previous number, we can include it in the beautiful subset, so we update f and g accordingly.
    //     d. If the current number is adjacent to the previous number, we cannot include it in the beautiful subset, so we update f and g accordingly.
    //  3. Multiply the number of beautiful subsets from each group to get the total number of beautiful subsets.
    //  4. Subtract 1 from the final result to exclude the empty subset.
    //  5. Return the final result.
    int beautifulSubsets(vector<int> &nums, int k)
    {
        map<int, map<int, int>> groups;
        for (int x : nums)
            groups[x % k][x]++;

        long long result = 1;
        for (auto &[mod, vals] : groups)
        {
            long long f = 1, g = 1;
            int prevVal = INT_MIN;
            for (auto &[v, c] : vals)
            {
                long long ways = (1LL << c) - 1;
                long long newF, newG;
                if (prevVal != INT_MIN && v - prevVal == k)
                {
                    newF = f + ways * g;
                    newG = f;
                }
                else
                {
                    newF = f * (1 + ways);
                    newG = f;
                }
                f = newF;
                g = newG;
                prevVal = v;
            }
            result *= f;
        }
        return (int)(result - 1);
    }
};
