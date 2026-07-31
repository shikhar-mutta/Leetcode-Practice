// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: We can use a sliding window approach to find the maximum length of increasing subarrays. We keep track of the length of the current increasing subarray and the length of the previous increasing subarray. When we encounter a non-increasing element, we update the maximum length of increasing subarrays by taking the maximum of the current length divided by 2 and the minimum of the current length and the previous length. We then reset the current length to 1 and update the previous length to the current length. Finally, we return the maximum length of increasing subarrays found.
class Solution
{
public:
    static int maxIncreasingSubarrays(vector<int> &nums)
    {
        const int n = nums.size();
        int len = 1, prev = 0, k = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                len++;
            else
            {
                k = max({k, len / 2, min(len, prev)});
                prev = len;
                len = 1;
            }
        }
        return max({k, len / 2, min(len, prev)});
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
