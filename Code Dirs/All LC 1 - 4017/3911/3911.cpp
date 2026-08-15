// Link: https://leetcode.com/problems/k-th-smallest-remaining-even-integer-in-subarray-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * log(n))  SC: O(n)
// Approach: We can use prefix sum to count the number of even integers in the range [l, r]. We can use binary search to find the k-th smallest remaining even integer in the range [l, r]. We can use prefix sum to count the number of even integers in the range [l, r]. We can use binary search to find the k-th smallest remaining even integer in the range [l, r]. We can use prefix sum to count the number of even integers in the range [l, r]. We can use binary search to find the k-th smallest remaining even integer in the range [l, r]. We can use prefix sum to count the number of even integers in the range [l, r]. We can use binary search to find the k-th smallest remaining even integer in the range [l, r]. We can use prefix sum to count the number of even integers in the range [l, r]. We can use binary search to find the k-th smallest remaining even integer in the range [l, r].
class Solution
{
public:
    vector<int> kthRemainingInteger(vector<int> &nums,
                                    vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] += prefix[i - 1] + ((nums[i - 1] % 2 == 0) ? 1 : 0);
        for (auto &it : queries)
        {
            int l = it[0], r = it[1], k = it[2];
            int lower_cnt = (nums[l] - 1) / 2, upper_cnt = nums[r] / 2,
                remove = prefix[r + 1] - prefix[l];
            // first segment
            if (lower_cnt >= k)
            {
                ans.push_back(2 * k);
                continue;
            }
            // third segment
            if (upper_cnt - remove < k)
            {
                ans.push_back(2 * (k + remove));
                continue;
            }
            // middle segment
            int s = l, e = r;
            while (s <= e)
            {
                int m = s + (e - s) / 2;
                int u = nums[m] / 2, rem = prefix[m + 1] - prefix[l];
                if (u - rem < k)
                    s = m + 1;
                else
                    e = m - 1;
            }
            ans.push_back(2 * (k + (prefix[s] - prefix[l])));
        }
        return ans;
    }
};
