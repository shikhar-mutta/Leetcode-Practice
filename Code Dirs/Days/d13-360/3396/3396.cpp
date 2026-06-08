// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minimumOperations(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        for (int num : nums)
            freq[num]++;

        int operations = 0;

        int n = nums.size(), i = 0, cnt;
        while (n > i)
        {
            bool allDistinct = true;
            for (auto f : freq)
                if (f > 1)
                {
                    operations++;
                    allDistinct = false;
                    break;
                }

            if (allDistinct)
            {
                break;
            }
            cnt = 0;
            while (cnt < 3 && n > i)
            {
                freq[nums[i]]--;
                i++;
                cnt++;
            }
        }
        return operations;
    }
};
