// Link: https://leetcode.com/problems/optimal-division/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //   1. If there is only one number, return it as a string.
    //   2. If there are two numbers, return them in the format "a/b".
    //   3. If there are more than two numbers, return the first number followed by the division of the rest of the numbers in parentheses to maximize the result.
    //   4. This is because dividing by a fraction (which is the result of dividing the rest of the numbers) will yield a larger result than dividing by each number individually.
    //   5. Finally, return the result as a string.
    string optimalDivision(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return to_string(nums[0]);
        if (n == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++)
        {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};
