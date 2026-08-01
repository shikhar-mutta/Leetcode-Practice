// Link: https://leetcode.com/problems/sum-of-sortable-integers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * d(n))  SC: O(n)
// Approach: k is sortable iff it divides n and every consecutive length-k
// block, viewed circularly, is "rotate-to-sorted" (at most one descent
// including the wraparound) AND every element before a block is <= every
// element from that block onward (so sorting each block independently and
// concatenating gives a fully sorted array). Precompute running max
// (prefix), running min from the right (suffix), and a prefix count of
// descents to check both conditions in O(1) per block.
class Solution
{
public:
    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = max(prefix[i], (long long)nums[i]);

        vector<long long> suffix(n + 1, LLONG_MAX);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = min(suffix[i + 1], (long long)nums[i]);

        vector<int> prefix2(n, 0);
        for (int i = 0; i + 1 < n; i++)
            prefix2[i + 1] = prefix2[i] + (nums[i] > nums[i + 1] ? 1 : 0);

        auto check = [&](int k)
        {
            if (n % k != 0)
                return false;
            for (int i = 0; i < n; i += k)
            {
                if (prefix[i] > suffix[i])
                    return false;
                int internalDescents = prefix2[i + k - 1] - prefix2[i];
                int wrap = (nums[i + k - 1] > nums[i]) ? 1 : 0;
                if (internalDescents + wrap > 1)
                    return false;
            }
            return true;
        };

        long long result = 0;
        for (int k = 1; k <= n; k++)
            if (check(k))
                result += k;
        return (int)result;
    }
};
