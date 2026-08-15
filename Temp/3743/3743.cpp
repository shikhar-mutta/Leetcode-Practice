// Link: https://leetcode.com/problems/maximize-cyclic-partition-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(n)
//  Approach: partition the cyclic array into at most k contiguous (wrap-allowed) subarrays maximizing the sum of (max-min) per subarray. Fix the
//  cyclic cut at the index of the global minimum (or right after it) so the array can be unrolled linearly, then each subarray's range = max-min decomposes into a sum of (peak - valley) moves, which is exactly "Best Time to Buy and Sell Stock IV" with at most k transactions on the unrolled values; take the better of starting the unroll at the min or right after it.
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

class Solution
{
    using i64 = long long;

    static constexpr i64 NEG = -(1LL << 60);
    static constexpr i64 PACK_BASE = 1024;
    static constexpr i64 PACK_MASK = PACK_BASE - 1;

    static i64 exactLinear(const vector<int> &nums, int start, int k,
                           array<i64, 2002> &work)
    {
        const int n = static_cast<int>(nums.size());
        const int width = n + 1;

        fill_n(work.data(), width, 0LL);

        int previous = 0;
        int current = width;

        for (int transaction = 0; transaction < k; ++transaction)
        {
            work[current] = 0;

            i64 low = NEG;
            i64 high = NEG;
            int j = 0;

            for (int i = start; i < n; ++i, ++j)
            {
                const i64 x = nums[i];
                const i64 old = work[previous + j];

                low = max(low, old - x);
                high = max(high, old + x);

                work[current + j + 1] =
                    max(work[current + j], max(low + x, high - x));
            }

            for (int i = 0; i < start; ++i, ++j)
            {
                const i64 x = nums[i];
                const i64 old = work[previous + j];

                low = max(low, old - x);
                high = max(high, old + x);

                work[current + j + 1] =
                    max(work[current + j], max(low + x, high - x));
            }

            swap(previous, current);
        }

        return work[previous + n];
    }

    static i64 penalizedLinear(const vector<int> &nums, int start, i64 fee)
    {
        const int n = static_cast<int>(nums.size());
        const i64 packedFee = fee * PACK_BASE;

        i64 closed = 0;
        i64 low = NEG;
        i64 high = NEG;

        auto step = [&](int value)
        {
            const i64 x = static_cast<i64>(value) * PACK_BASE;
            const i64 oldClosed = closed;

            closed = max(
                closed, max(low + x - packedFee + 1, high - x - packedFee + 1));

            low = max(low, oldClosed - x);
            high = max(high, oldClosed + x);
        };

        for (int i = start; i < n; ++i)
        {
            step(nums[i]);
        }
        for (int i = 0; i < start; ++i)
        {
            step(nums[i]);
        }

        return closed;
    }

    static i64 penalizedBoth(const vector<int> &nums, int base, i64 fee)
    {
        const int next =
            base + 1 == static_cast<int>(nums.size()) ? 0 : base + 1;

        return max(penalizedLinear(nums, base, fee),
                   penalizedLinear(nums, next, fee));
    }

    static i64 wqs(const vector<int> &nums, int base, int k, i64 span)
    {
        i64 key = penalizedBoth(nums, base, 0);

        if ((key & PACK_MASK) <= k)
        {
            return key / PACK_BASE;
        }

        i64 low = 0;
        i64 high = span;

        while (low < high)
        {
            const i64 middle = (low + high + 1) >> 1;

            key = penalizedBoth(nums, base, middle);

            if ((key & PACK_MASK) >= k)
            {
                low = middle;
            }
            else
            {
                high = middle - 1;
            }
        }

        key = penalizedBoth(nums, base, low);
        return key / PACK_BASE + low * k;
    }

public:
    long long maximumScore(vector<int> &nums, int k)
    {
        const int n = static_cast<int>(nums.size());

        if (n < 2)
        {
            return 0;
        }

        k = min(k, n / 2);
        if (k == 0)
        {
            return 0;
        }

        int base = 0;
        int minimum = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < n; ++i)
        {
            const int x = nums[i];

            if (x < minimum)
            {
                minimum = x;
                base = i;
            }
            if (x > maximum)
            {
                maximum = x;
            }
        }

        const i64 span = static_cast<i64>(maximum) - minimum;

        if (span == 0)
        {
            return 0;
        }
        if (k == 1)
        {
            return span;
        }

        int bits = 0;
        for (i64 value = span; value != 0; value >>= 1)
        {
            ++bits;
        }

        // Measured crossover for GCC/Clang scalar code.
        const int threshold = max(8, 2 * bits);

        if (k <= threshold)
        {
            array<i64, 2002> work;

            const i64 first = exactLinear(nums, base, k, work);

            const int next = base + 1 == n ? 0 : base + 1;

            const i64 second = exactLinear(nums, next, k, work);

            return max(first, second);
        }

        return wqs(nums, base, k, span);
    }
};