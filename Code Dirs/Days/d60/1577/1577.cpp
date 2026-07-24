// Link: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach:
//  1. We will create a frequency map for the second array.
//  2. We will iterate through the first array and for each element, we will calculate the square of that element and check if it can be expressed as a product of two elements from the second array.
// 3. We will do this by iterating through the frequency map and checking if the square of the element is divisible by the current element from the frequency map. If it is, we will check if the other element (square / current element) is also present in the frequency map. If both elements are present, we will calculate the number of pairs that can be formed using the counts of both elements and add it to the result.
// 4. We will repeat the same process for the second array and the first array to get the total number of triplets.
class Solution
{
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        return count(nums1, nums2) + count(nums2, nums1);
    }

private:
    int count(vector<int> &a, vector<int> &b)
    {
        unordered_map<long long, long long> freq;
        for (int x : b)
            ++freq[x];

        long long res = 0;
        for (int x : a)
        {
            long long sq = (long long)x * x;
            for (auto &[v, c] : freq)
            {
                if (sq % v)
                    continue;
                long long other = sq / v;
                auto it = freq.find(other);
                if (it == freq.end())
                    continue;
                if (other == v)
                    res += c * (c - 1) / 2;
                else if (other > v)
                    res += c * it->second;
            }
        }
        return res;
    }
};