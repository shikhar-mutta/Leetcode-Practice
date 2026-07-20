// Link: https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(n) + O(k) + O(n-k) = O(n)
    // SC: O(n)
    // Approach:
    // 1. Calculate the total points if we choose all tasks with technique2.
    // 2. Calculate the difference between technique1 and technique2 for each task.
    // 3. Sort the differences in descending order and choose the top k differences to maximize the points.
    // 4. Add the remaining positive differences to the total points.
    long long maxPoints(vector<int> &technique1, vector<int> &technique2,
                        int k)
    {
        vector<int> diffs;
        diffs.reserve(technique1.size());

        long long max_points = 0;
        for (int i = 0; i < technique1.size(); ++i)
        {
            max_points += technique2[i];
            diffs.push_back(technique1[i] - technique2[i]);
        }

        if (k > 0)
        {
            nth_element(diffs.begin(), diffs.begin() + k, diffs.end(), greater<int>{});
        }

        for (int i = 0; i < k; ++i)
        {
            max_points += diffs[i];
        }

        for (int i = k; i < diffs.size(); ++i)
        {
            if (diffs[i] > 0)
            {
                max_points += diffs[i];
            }
        }

        return max_points;
    }
};
