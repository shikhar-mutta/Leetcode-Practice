// Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + k) where n is the size of nums1 and nums2 and k is the sum of k1 and k2.
    // SC: O(n) where n is the size of nums1 and nums2.
    // Approach:
    // 1. We will create a vector diff to store the absolute difference between nums1 and nums2.
    // 2. We will create a vector buckets to store the frequency of each difference.
    // 3. We will iterate through the buckets from the maximum difference to 1 and reduce the frequency of each difference by the minimum of the frequency and k.
    // 4. We will calculate the sum of squares of the remaining differences and return it.
    // 5. If k is greater than the sum of frequencies, we will return 0.
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size();

        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxi = *max_element(diff.begin(), diff.end());

        vector<int> buckets(maxi + 1, 0); //{freq -> no of such freq}

        for (int i = 0; i < n; i++)
        {
            buckets[diff[i]]++;
        }

        int k = k1 + k2;

        // it over frequency
        for (int i = maxi; i > 0; i--)
        {
            if (buckets[i] > 0)
            {
                int minus = min(buckets[i], k);

                buckets[i] -= minus;
                buckets[i - 1] += minus;
                k -= minus;
            }
        }

        long long ans = 0;

        for (long long i = maxi; i > 0; i--)
        {
            // freq * (element * element)
            ans += 1LL * (buckets[i]) * (i * i);
        }

        return ans;
    }
};
