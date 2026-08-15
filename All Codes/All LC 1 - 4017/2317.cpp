// Link: https://leetcode.com/problems/maximum-xor-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of elements in the array.
// SC: O(1), as we are using a constant amount of extra space.
//  Approach:
//   1. The maximum XOR value that can be obtained from the array is the bitwise OR of all the elements in the array. This is because we can perform any number of operations to change the elements of the array, and the bitwise OR operation will ensure that all bits that are set in any of the elements will be set in the final result.
//   2. We initialize a variable res to 0 and iterate through each element in the array, performing a bitwise OR operation with res. This will accumulate all the bits that are set in any of the elements.
//  3. Finally, we return the value of res, which will be the maximum XOR value that can be obtained from the array after performing the allowed operations.
class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int res = 0;
        for (int x : nums)
            res |= x;
        return res;
    }
};
