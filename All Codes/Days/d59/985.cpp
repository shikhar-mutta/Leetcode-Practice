// Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the size of nums and m is the size of queries.
    // SC: O(1) as we are using constant space.
    // Approach:
    //   1. We will first calculate the sum of even numbers in the nums array.
    //   2. Then for each query, we will check if the original number at the index is even or odd and if the value to be added is even or odd.
    //   3. Based on the above checks, we will update the sum of even numbers accordingly.
    //   4. Finally, we will return the sum of even numbers after each query.
    vector<int> sumEvenAfterQueries(vector<int> &nums,
                                    vector<vector<int>> &queries)
    {
        int n = nums.size();

        int sum = 0;
        for (int i : nums)
            if (i % 2 == 0)
                sum += i;

        vector<int> ans;
        for (auto &query : queries)
        {
            int val = query[0], idx = query[1];

            int original = nums[idx];
            if (original % 2 == 0 && val % 2 == 0)
            {
                sum += val;
            }
            else if (original % 2 != 0 && val % 2 != 0)
            {
                sum += original + val;
            }
            else if (original % 2 == 0 && val % 2 != 0)
            {
                sum -= original;
            }
            ans.push_back(sum);
            nums[idx] += val;
        }

        return ans;
    }
};