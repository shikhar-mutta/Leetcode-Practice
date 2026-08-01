// Link: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: Convert nums to a new array of 1, 0, -1 based on whether the next element is greater than, equal to, or less than the current element. Then use KMP algorithm to find the number of occurrences of the pattern in the new array.
class Solution
{
private:
    int kmpSearch(vector<int> &s, vector<int> &goal)
    {
        int pre = 0;
        int suf = 1;
        vector<int> lps(goal.size(), 0);

        while (suf < goal.size())
        {
            if (goal[pre] == goal[suf])
            {
                pre++;
                lps[suf] = pre;
                suf++;
            }
            else
            {
                if (pre == 0)
                {
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }

        int ans = 0;

        int i = 0, j = 0;
        while (i < s.size())
        {
            if (s[i] == goal[j])
            {
                i++;
                j++;

                if (j == goal.size())
                {
                    ans++;
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j == 0)
                    i++;
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return ans;
    }

public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        vector<int> numbuilder(nums.size() - 1, 0);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                numbuilder[i] = 1;
            else if (nums[i + 1] == nums[i])
                numbuilder[i] = 0;
            else
                numbuilder[i] = -1;
        }

        return kmpSearch(numbuilder, pattern);
    }
};