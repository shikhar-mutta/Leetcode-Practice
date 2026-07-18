// Link: https://leetcode.com/problems/find-the-k-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + klogk) SC: O(k)
// Approach:
//  1. Calculate the maximum sum of the array by summing all positive elements.
//  2. Calculate the minimum loss by finding the smallest absolute value in the array.
//  3. Use a min-heap to generate the k smallest losses by exploring combinations of the smallest absolute values in the array.
//  4. Return the maximum sum minus the k-th smallest loss as the k-sum of the array.
class Solution
{
public:
    long long kSum(vector<int> &nums, int k)
    {
        using ll = long long;
        using ull = unsigned long long;

        ll maxSum = 0;
        int len = 0, zeros = 0;
        int minLoss = INT_MAX;

        // Compact non-zero absolute losses into nums[0..len-1].
        for (int x : nums)
        {
            if (x > 0)
                maxSum += x;

            int v = x < 0 ? -x : x;
            if (v)
            {
                nums[len++] = v;
                if (v < minLoss)
                    minLoss = v;
            }
            else
            {
                ++zeros;
            }
        }

        if (k == 1)
            return maxSum;

        // Each zero duplicates every possible loss.
        // Since k <= 2000, 2^11 already covers all possible k.
        if (zeros)
        {
            if (zeros >= 11)
                return maxSum;

            int mult = 1 << zeros;
            if (k <= mult)
                return maxSum;

            k = (k + mult - 1) >> zeros; // ceil(k / mult)
        }

        if (len == 0 || k == 1)
            return maxSum;
        if (k == 2)
            return maxSum - minLoss;

        int m = min(len, k - 1);

        auto first = nums.begin();
        auto mid = first + m;
        auto last = first + len;

        if (m < len)
        {
            nth_element(first, first + m - 1, last);
        }

        sort(first, mid);

        constexpr int BITS = 11;
        constexpr ull MASK = (1ULL << BITS) - 1;

        auto pack = [](ull loss, int idx) -> ull
        {
            return (loss << BITS) | (ull)idx;
        };

        ull heap[2005];
        int sz = 1;
        heap[0] = pack((ull)nums[0], 0);

        auto push = [&](ull val)
        {
            int i = sz++;
            while (i)
            {
                int p = (i - 1) >> 1;
                if (heap[p] <= val)
                    break;
                heap[i] = heap[p];
                i = p;
            }
            heap[i] = val;
        };

        auto pop = [&]() -> ull
        {
            ull res = heap[0];
            ull val = heap[--sz];

            int i = 0;
            while (true)
            {
                int l = i * 2 + 1;
                if (l >= sz)
                    break;

                int r = l + 1;
                int c = (r < sz && heap[r] < heap[l]) ? r : l;

                if (heap[c] >= val)
                    break;

                heap[i] = heap[c];
                i = c;
            }

            if (sz)
                heap[i] = val;
            return res;
        };

        ull loss = 0;

        // Pop and expand the first k - 2 non-empty losses.
        for (int count = 1; count < k - 1; ++count)
        {
            ull state = pop();

            loss = state >> BITS;
            int i = state & MASK;
            int j = i + 1;

            if (j < m)
            {
                ull next = nums[j];

                // Add nums[j].
                push(pack(loss + next, j));

                // Replace nums[i] with nums[j].
                push(pack(loss - (ull)nums[i] + next, j));
            }
        }

        // The next popped loss is the desired one.
        loss = pop() >> BITS;

        return maxSum - (ll)loss;
    }
};