// Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach:
//   1. We will use recursion to find the kth bit in the nth binary string
//   2. We will find the length of the nth binary string and the middle index
//   3. If k is equal to the middle index, we will return '1
//   4. If k is less than the middle index, we will call the function recursively with n-1 and k
//   5. If k is greater than the middle index, we will call the function recursively with n-1 and len-k+1 and return the opposite of the result
class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';
        int len = (1 << n) - 1;
        int mid = len / 2 + 1;
        if (k == mid)
            return '1';
        if (k < mid)
            return findKthBit(n - 1, k);
        return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0';
    }
};