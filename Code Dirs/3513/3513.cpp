// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. If the size of the array is less than or equal to 2, return the size of the array.
    //  2. Otherwise, find the highest power of 2 that is greater than the size of the array. This is because the maximum number of unique XOR triplets that can be formed
    //     is limited by the number of unique values that can be represented with the given number of elements. The highest power of 2 greater than n will give us the maximum number of unique
    //     XOR triplets that can be formed.
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        // highest power of 2 that is > n, i.e. all values 0..2^k-1 achievable
        int k = 1;
        while (k <= n)
            k <<= 1;
        return k;
    }
};