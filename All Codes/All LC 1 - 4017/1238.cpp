// Link: https://leetcode.com/problems/circular-permutation-in-binary-representation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n) where n is the number of bits in the binary representation. This is because we are generating all possible combinations of the binary numbers with n bits, which takes O(2^n) time.
    // SC: O(2^n) for the result vector, which stores all the numbers in the circular permutation.
    //  Approach:
    //  1. We will generate all the numbers in the circular permutation using the formula:
    //     circular_permutation[i] = start ^ (i ^ (i >> 1))
    //     where i is the index of the number in the circular permutation and start is the starting number of the circular permutation.
    //  2. We will iterate through all the numbers from 0 to 2^n - 1 and calculate the corresponding number in the circular permutation using the formula above.
    //  3. We will store the calculated numbers in a result vector and return it as the final result.
    vector<int> circularPermutation(int n, int start)
    {
        int size = 1 << n; // 2^n total numbers
        vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            result[i] = start ^ (i ^ (i >> 1));
        }
        return result;
    }
};