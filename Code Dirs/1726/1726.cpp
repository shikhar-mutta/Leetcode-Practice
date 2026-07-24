// Link: https://leetcode.com/problems/tuple-with-same-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n^2)
    //   Approach:
    //    1. We can use a hash map to store the product of each pair of numbers in the array and the count of how many pairs have that product.
    //    2. We can then iterate through the hash map and for each product that has more than one pair, we can calculate the number of tuples that can be formed using the formula: count * (count - 1) * 4, where count is the number of pairs that have that product.
    //    3. We can return the sum of all the tuples that can be formed as the answer.
    //  Note: We can use a hash map to store the product of each pair of numbers in the array and the count of how many pairs have that product. This will allow us to calculate the number of tuples that can be formed in O(n^2) time.
    int tupleSameProduct(vector<int> &nums)
    {
        const auto n{nums.size()};
        array<int, 1000 * 999 / 2> p;
        size_t size{0};
        for (size_t i{0}; i < n; ++i)
        {
            const auto a{nums[i]};
            for (size_t j{i + 1}; j < n; ++j)
            {
                p[size++] = a * nums[j];
            }
        }
        ranges::sort(p | views::take(size));
        int ans{0};
        for (size_t i{0}, j{1}, c{1}; i < size; ++i)
        {
            if (p[i] == p[j])
            {
                ++c;
                continue;
            }
            if (c > 1)
                ans += 4 * c * (c - 1);

            c = 1;
            j = i;
        }
        return ans;
    }
};