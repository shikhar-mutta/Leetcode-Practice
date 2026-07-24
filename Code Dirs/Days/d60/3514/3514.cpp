// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + n*2^k) SC: O(2^k) where k is the number of bits in the maximum number in nums
    // Approach:
    //  1. We can use the Fast Subset Transform (FST) to compute the number of unique XOR triplets in the given array. The FST is a technique that allows us to compute the XOR of all subsets of a set in O(n*2^k) time, where n is the size of the set and k is the number of bits in the maximum number in the set. We can use the FST to compute the number of unique XOR triplets in the given array by first computing the frequency of each number in the array, and then applying the FST to the frequency array. Finally, we can count the number of unique XOR triplets by counting the number of non-zero entries in the resulting array.
    int uniqueXorTriplets(vector<int> &nums)
    {
        const auto &bit_length = [](int64_t x)
        {
            return (x ? std::__lg(x) : -1) + 1;
        };

        vector<int64_t> a(1 << bit_length(ranges::max(nums)));
        for (const auto &x : nums)
        {
            ++a[x];
        }
        FST(a, false);
        for (int i = 0; i < size(a); i++)
        {
            a[i] = a[i] * a[i] * a[i];
        }
        FST(a, true);
        int result = 0;
        for (const auto &x : a)
        {
            if (x)
            {
                ++result;
            }
        }
        return result;
    }

private:
    // Template:
    // https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastSubsetTransform.h
    void FST(auto &a, bool inv)
    {
        for (int n = size(a), step = 1; step < n; step <<= 1)
        {
            for (int i = 0; i < n; i += step << 1)
            {
                for (int j = i; j < i + step; ++j)
                {
                    auto &u = a[j], &v = a[j + step];
                    tie(u, v) = pair(u + v, u - v); // XOR
                }
            }
        }
        if (inv)
        {
            for (auto &x : a)
            {
                x /= size(a); // XOR only /// include-line
            }
        }
    }
};

// Time:  O(n^2)
// Space: O(n)
// hash table
class Solution2
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        const auto &bit_length = [](int64_t x)
        {
            return (x ? std::__lg(x) : -1) + 1;
        };

        unordered_set<int> cnt2 = {0};
        unordered_set<int> cnt3;
        const int max_cnt = 1 << bit_length(ranges::max(nums));
        for (const auto &x : nums)
        {
            for (const auto &y : cnt2)
            {
                cnt3.emplace(x ^ y);
            }
            for (const auto &y : nums)
            {
                cnt2.emplace(x ^ y);
            }
            if (size(cnt3) == max_cnt)
            {
                break;
            }
        }
        return size(cnt3);
    }
};