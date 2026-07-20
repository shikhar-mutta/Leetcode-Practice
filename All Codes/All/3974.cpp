// Link: https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + k)
    // SC: O(n)
    // Approach:
    //  1. Find the maximum element in the array.
    //  2. Create a frequency array to count the occurrences of each element.
    //  3. Iterate from the maximum element down to 0, and for each element
    //     that has a non-zero frequency, add its value multiplied by the appropriate multiplier to the total sum until we have selected k elements.
    //  4. Return the total sum.
    long long maxSum(vector<int> &nums, int k, int mul)
    {
        int n = nums.size();
        int m = mul;
        int mx = 0;
        int i = 0;
        while (i < n)
        {
            if (nums[i] > mx)
                mx = nums[i];
            i++;
        }
        vector<int> f(mx + 1, 0);
        i = 0;
        while (i < n)
        {
            f[nums[i]]++;
            i++;
        }
        long long a = 0;
        int p = 0;
        int v = mx;
        while (p < k && v >= 0)
        {
            if (f[v] > 0)
            {
                int c = f[v];
                int t = c;
                if (p + t > k)
                    t = k - p;
                int j = 0;
                while (j < t)
                {
                    int q = m - p;
                    if (q < 1)
                        q = 1;
                    a += (long long)v * q;
                    p++;
                    j++;
                }
            }
            v--;
        }
        return a;
    }
};