// Link: https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: try both alternating targets (even indices want parity k,
//  odd indices want the opposite) — count mismatches for each. For a
//  mismatched element, nudging it by +-1 costs the required single
//  operation and we choose the direction toward the array's original
//  min/max to shrink the eventual spread (push the global min up, the
//  global max down; interior values direction doesn't matter for the
//  bound). Pick the target with fewer operations, tie-broken by the
//  smaller resulting max-min.
class Solution
{
public:
    vector<int> makeParityAlternating(vector<int> &nums)
    {
        vector<int> solution;
        int evenFirstMinOps = 0;
        int oddFirstMinOps = 0;
        int evenFirstMax = INT_MIN;
        int evenFirstMin = INT_MAX;
        int oddFirstMax = INT_MIN;
        int oddFirstMin = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            bool isEven = (nums[i] % 2 == 0);
            if (i % 2 == 0)
            {
                if (isEven)
                {
                    evenFirstMax = max(evenFirstMax, nums[i]);
                    evenFirstMin = min(evenFirstMin, nums[i]);
                    oddFirstMax = max(oddFirstMax, nums[i] - 1);
                    oddFirstMin = min(oddFirstMin, nums[i] + 1);
                    oddFirstMinOps++;
                }
                else
                {
                    evenFirstMax = max(evenFirstMax, nums[i] - 1);
                    evenFirstMin = min(evenFirstMin, nums[i] + 1);
                    oddFirstMax = max(oddFirstMax, nums[i]);
                    oddFirstMin = min(oddFirstMin, nums[i]);
                    evenFirstMinOps++;
                }
            }
            else
            {
                if (isEven)
                {
                    evenFirstMax = max(evenFirstMax, nums[i] - 1);
                    evenFirstMin = min(evenFirstMin, nums[i] + 1);
                    oddFirstMax = max(oddFirstMax, nums[i]);
                    oddFirstMin = min(oddFirstMin, nums[i]);
                    evenFirstMinOps++;
                }
                else
                {
                    evenFirstMax = max(evenFirstMax, nums[i]);
                    evenFirstMin = min(evenFirstMin, nums[i]);
                    oddFirstMax = max(oddFirstMax, nums[i] - 1);
                    oddFirstMin = min(oddFirstMin, nums[i] + 1);
                    oddFirstMinOps++;
                }
            }
        }

        solution.push_back(min(evenFirstMinOps, oddFirstMinOps));

        int evenFirstDiff = evenFirstMax - evenFirstMin;
        int oddFirstDiff = oddFirstMax - oddFirstMin;

        if (evenFirstMinOps > oddFirstMinOps)
        {
            solution.push_back(oddFirstDiff);
        }
        else if (evenFirstMinOps < oddFirstMinOps)
        {
            solution.push_back(evenFirstDiff);
        }
        else
        {
            solution.push_back(min(evenFirstDiff, oddFirstDiff));
        }

        if (nums.size() > 1)
        {
            solution[1] = max(solution[1], 1);
        }

        return solution;
    }
};