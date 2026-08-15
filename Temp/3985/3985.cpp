// Link: https://leetcode.com/problems/palindromic-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: We can use Manacher's algorithm to find the longest palindromic substring in O(n) time. We can use two arrays d1 and d2 to store the lengths of the longest palindromic substrings centered at each index. We can then use a prefix sum array to find the sum of the elements in the longest palindromic substring. We can iterate through the array and for each index, we can find the longest palindromic substring centered at that index and update the answer accordingly.
class Solution
{
public:
    long long getSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> d1(n), d2(n);

        // Odd
        for (int l = 0, r = -1, i = 0; i < n; i++)
        {
            int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
                k++;
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }

        // Even
        for (int l = 0, r = -1, i = 0; i < n; i++)
        {
            int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
            while (i - k - 1 >= 0 && i + k < n &&
                   nums[i - k - 1] == nums[i + k])
                k++;
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }

        vector<long long> pref(n);
        pref[0] = (long long)nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + (long long)nums[i];
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int r1 = d1[i];
            int l = i - r1 + 1, r = i + r1 - 1;
            ans = max(ans, pref[r] - (l == 0 ? 0 : pref[l - 1]));
            int r2 = d2[i];
            if (r2 == 0)
                continue;
            l = i - r2;
            r = i + r2 - 1;
            ans = max(ans, pref[r] - (l == 0 ? 0 : pref[l - 1]));
        }
        return ans;
    }
};
