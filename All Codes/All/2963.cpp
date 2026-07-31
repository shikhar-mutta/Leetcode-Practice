// Link: https://leetcode.com/problems/count-the-number-of-good-partitions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use a greedy approach to count the number of good partitions. We first create a map to store the last index of each unique number in the nums array. Then, we iterate through the nums array and keep track of the maximum last index of the current segment. Whenever we reach an index greater than the maximum last index, we can create a new partition and multiply the result by 2 (since we can either include or exclude the current segment). Finally, we return the total count of good partitions modulo 1e9 + 7.
class Solution
{
public:
    int mod = 1e9 + 7;
    int numberOfGoodPartitions(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> lastindex;
        for (int i = 0; i < n; i++)
        {
            lastindex[nums[i]] = i;
        }
        int i = 0;
        int j = 0;
        int res = 1;
        j = max(j, lastindex[nums[0]]);
        while (i < n)
        {
            if (i > j)
            {
                res = (res * 2) % mod;
            }
            j = max(j, lastindex[nums[i]]);
            i++;
        }
        return res;
    }
};
