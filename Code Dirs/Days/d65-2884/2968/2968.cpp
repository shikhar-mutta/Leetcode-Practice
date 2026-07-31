// Link: https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//  Approach: We can use a two-pointer approach to find the maximum frequency score. We first sort the nums array and create a prefix sum array. Then, we iterate through the nums array using two pointers, l and r, where l is the left pointer and r is the right pointer. For each r, we calculate the cost to make all elements in the range [l, r] equal to nums[r] using the prefix sum array. If the cost is less than or equal to k, we update the answer with the length of the current range (r - l + 1). If the cost is greater than k, we increment the left pointer l until the cost is less than or equal to k. Finally, we return the maximum frequency score found during the iteration.
class Solution
{
public:
    int maxFrequencyScore(vector<int> &nums, long long k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        auto cost = [&](int l, int r) -> long long
        {
            int mid = (l + r) / 2;
            long long val = nums[mid];
            long long leftSum = val * (mid - l) - (prefix[mid] - prefix[l]);
            long long rightSum =
                (prefix[r + 1] - prefix[mid + 1]) - val * (r - mid);
            return leftSum + rightSum;
        };

        int l = 0, ans = 1;
        for (int r = 0; r < n; r++)
        {
            while (cost(l, r) > k)
                l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
