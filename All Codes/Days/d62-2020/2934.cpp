// Link: https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – two linear passes via check(), one for each last-pair scenario
// SC: O(1) – no extra data structures
// Approach: The last elements (nums1[n-1], nums2[n-1]) must be the maximums.
// Try two cases: keep last pair as-is, or swap the last pair (cost +1).
// For each case, scan all i < n-1: if nums1[i]<=last1 && nums2[i]<=last2 →
// no swap needed; if nums2[i]<=last1 && nums1[i]<=last2 → swap at i (cost +1);
// else → impossible (return INT_MAX). Answer = min of both cases, -1 if both
// are INT_MAX.
class Solution
{
public:
    int check(vector<int> &nums1, vector<int> &nums2, int last1, int last2)
    {
        int cnt = 0;
        int n = nums1.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums1[i] <= last1 && nums2[i] <= last2)
            {
                continue;
            }
            else if (nums2[i] <= last1 && nums1[i] <= last2)
            {
                cnt++;
            }
            else
            {
                return INT_MAX;
            }
        }

        return cnt;
    }

    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        int ans = check(nums1, nums2, nums1[n - 1], nums2[n - 1]);

        int t = check(nums1, nums2, nums2[n - 1], nums1[n - 1]);
        if (t != INT_MAX)
            ans = min(ans, t + 1);

        return ans == INT_MAX ? -1 : ans;
    }
};