// Link: https://leetcode.com/problems/minimum-stability-factor-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n): We are using a sparse table to preprocess the GCD of all subarrays of the input array. The preprocessing takes O(n log n) time.
// SC: O(n log n): We are using a sparse table to store the GCD of all subarrays of the input array. The sparse table takes O(n log n) space.
// Approach: We can use a sparse table to preprocess the GCD of all subarrays of the input array. We can then use binary search to find the maximum length of a subarray that can be made stable by changing at most maxC elements. We can check if a subarray is stable by checking if its GCD is greater than or equal to 2. If it is, we can change at most maxC elements to make it stable. If we can make the subarray stable, we can continue searching for longer subarrays. If we cannot make the subarray stable, we need to search for shorter subarrays.
const int N = 1e5 + 1;
const int LOG = 18;
int st[N][LOG];
class Solution
{
public:
    int minStable(vector<int> &nums, int maxC)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }
        for (int i = 1; i < LOG; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k = j + (1 << i) - 1;
                if (k >= n)
                    break;
                st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }

        int p = 1, q = n, r;
        while (p <= q)
        {
            r = (p + q) / 2;

            bool check = true;
            int cnt = maxC;
            for (int left = 0; left <= n - r; left++)
            {
                int right = left + r - 1;
                int pwr = 31 - __builtin_clz(r);
                if (__gcd(st[left][pwr], st[right - (1 << pwr) + 1][pwr]) >=
                    2)
                {
                    if (cnt > 0)
                    {
                        cnt--;
                        left += r - 1;
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (check)
                q = r - 1;
            else
                p = r + 1;
        }
        return q;
    }
};
