// Link: https://leetcode.com/problems/gray-code/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n) - We generate all 2^n Gray codes by iterating from 0 to 2^n - 1. For each number, we perform constant time operations to compute the corresponding Gray code.
    // SC: O(2^n) - We store all 2^n Gray codes in the result vector. Therefore, the space complexity is O(2^n).
    //   Approach:
    //     1. We calculate the total number of Gray codes, which is 2^n, and initialize a result vector of that size.
    //     2. We iterate from 0 to 2^n - 1. For each number i, we compute the corresponding Gray code using the formula: Gray(i) = i ^ (i >> 1). This formula ensures that each Gray code differs from the previous one by only one bit.
    //     3. We store the computed Gray code in the result vector.
    //     4. Finally, we return the result vector containing all the Gray codes.
    vector<int> grayCode(int n)
    {
        int size = 1 << n;
        vector<int> result(size);
        for (int i = 0; i < size; i++)
            result[i] = i ^ (i >> 1);
        return result;
    }
};
