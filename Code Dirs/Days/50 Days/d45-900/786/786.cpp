// Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlog(max-min)), SC: O(1).
    // Approach: Use binary search to find the k-th smallest prime fraction. The idea is to maintain a range [lo, hi] and repeatedly narrow it down based on the count of fractions less than or equal to mid. We also keep track of the largest fraction found that is less than or equal to mid.
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        double lo = 0, hi = 1;
        while (true)
        {
            double mid = (lo + hi) / 2;
            int cnt = 0, p = 0, q = 1;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                while (j < n && arr[i] > mid * arr[j])
                    j++;
                cnt += n - j;
                if (j < n && (long long)p * arr[j] < (long long)arr[i] * q)
                {
                    p = arr[i];
                    q = arr[j];
                }
            }
            if (cnt == k)
                return {p, q};
            else if (cnt < k)
                lo = mid;
            else
                hi = mid;
        }
    }
};
