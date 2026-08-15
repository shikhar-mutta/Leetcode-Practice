// Link: https://leetcode.com/problems/product-of-array-except-self/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(1)
    //  Approach:
    //  1. We can use a prefix and suffix product approach to solve this problem.
    //  2. We can create a result array of size n and initialize it with 1. We can then iterate through the input array and calculate the prefix product for each element and store it in the result array. We can then iterate through the input array in reverse and calculate the suffix product for each element and multiply it with the corresponding element in the result array. This way we can get the product of all elements except self for each element in the input array.
    //  3. We can return the result array as the final output.
    //  4. We can use two variables to store the prefix and suffix product and update them in each iteration. This way we can achieve O(1) space complexity.
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};
