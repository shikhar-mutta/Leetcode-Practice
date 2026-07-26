// Link: https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – single left-to-right pass
// SC: O(1) – in-place modification, no extra data structures
// Approach: Greedy. Scan left to right; when nums[i] and nums[i+1] are
// "almost equal" (|diff| <= 1), we must change one of them. Greedily
// overwrite nums[i+1] with '#' (a sentinel that cannot match any letter),
// effectively skipping it from future comparisons, and increment ans.
// This maximises the distance between changes, minimising total operations.
class Solution
{
public:
    int removeAlmostEqualCharacters(string nums)
    {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) <= 1)
            {
                ans++;
                nums[i + 1] = '#';
            }
        }

        return ans;
    }
};