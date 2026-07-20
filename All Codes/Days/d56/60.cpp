// Link: https://leetcode.com/problems/permutation-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the input number
    // SC: O(n) for the output string
    //  Approach:
    //    1. Precompute the factorials of numbers from 1 to n and store them in a vector.
    //    2. Create a vector of numbers from 1 to n to represent the available digits for the permutation.
    //    3. Decrement k by 1 to convert it to a 0-based index.
    //    4. Iterate from n down to 1, and for each position, determine the index of the digit to be placed by dividing k by the factorial of (i-1).
    //    5. Update k to be the remainder of the division, and append the selected digit to the result string.
    //    6. Remove the selected digit from the available digits vector to avoid duplicates.
    string getPermutation(int n, int k)
    {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        k--;
        string res;
        for (int i = n; i >= 1; i--)
        {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return res;
    }
};
