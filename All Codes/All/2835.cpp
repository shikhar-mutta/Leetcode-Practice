// Link: https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: We can use a greedy approach to find the minimum number of operations. We will first count the number of elements in the array that are equal to each power of 2. Then, we will iterate through the bits of the target and check if we have enough elements to form the target. If we do not have enough elements, we will try to split larger elements into smaller ones until we have enough. We will keep track of the number of operations and return it at the end.
class Solution
{
public:
    int minOperations(vector<int> &nums, int target)
    {
        vector<long long> cnt(32);

        for (int x : nums)
        {
            cnt[__builtin_ctz(x)]++;
        }

        int ans = 0;

        for (int i = 0; i < 31; i++)
        {
            if ((target >> i) & 1)
            {
                if (cnt[i] > 0)
                {
                    cnt[i]--;
                }
                else
                {
                    int j = i + 1;
                    while (j < 31 && cnt[j] == 0)
                        j++;
                    if (j == 31)
                        return -1;
                    while (j > i)
                    {
                        cnt[j]--;
                        cnt[j - 1] += 2;
                        ans++;
                        j--;
                    }
                    cnt[i]--;
                }
            }
            cnt[i + 1] += cnt[i] / 2;
        }

        return ans;
    }
};
