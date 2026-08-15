// Link: https://leetcode.com/problems/maximum-xor-of-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums[i]))), SC: O(log(max(nums[i])))
// Approach:
//  1. We can use a basis to represent the numbers in the array. The basis is a set of numbers such that any number in the array can be represented as a linear combination of the basis numbers using XOR operation.
//  2. We can build the basis by iterating through the numbers in the array and adding them to the basis if they cannot be represented as a linear combination of the existing basis numbers.
//  3. Once we have the basis, we can find the maximum XOR of any subsequence by iterating through the basis numbers and XORing them with the current maximum XOR value. The maximum XOR value will be the result.
//  4. The maximum XOR of any subsequence can be found by iterating through the basis numbers in decreasing order and XORing them with the current maximum XOR value. This ensures that we are always trying to maximize the XOR value at each step.
//  5. The time complexity of this approach is O(n * log(max(nums[i]))), where n is the number of elements in the array and max(nums[i]) is the maximum value in the array. The space complexity is O(log(max(nums[i]))), which is the size of the basis.
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    int maxXorSubsequences(vector<int> &nums)
    {
        int b[30]{}, cnt = 0, hi = -2;
        for (int n : nums)
        {
            if (cnt == hi + 1 && n < (1 << (hi + 1)))
                continue;
            for (int i = n; i;)
            {
                int p = 31 - __builtin_clz(i);
                if (b[p])
                    i ^= b[p];
                else
                {
                    b[p] = i;
                    ++cnt;
                    hi = max(hi, p);
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 29; i >= 0; --i)
            res = max(res, res ^ b[i]);
        return res;
    }
};
