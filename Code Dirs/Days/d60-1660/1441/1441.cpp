// Link: https://leetcode.com/problems/build-an-array-with-stack-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the input number.
    // SC: O(n) where n is the input number.
    // Approach:
    //  1. We iterate through all numbers from 1 to n.
    //  2. For each number, we push it to the stack and check if it is in the target array.
    //  3. If it is in the target array, we move to the next number in the target array.
    //  4. If it is not in the target array, we pop it from the stack.
    //  5. Finally, we return the result vector containing the stack operations.
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int j = 0;
        for (int i = 1; i <= n && j < target.size(); ++i)
        {
            res.push_back("Push");
            if (target[j] == i)
                ++j;
            else
                res.push_back("Pop");
        }
        return res;
    }
};