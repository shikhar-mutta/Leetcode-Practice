// Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Hash Set(Unordered Set). TC: O(n) SC: O(n)
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original))
            original *= 2;
        return original;
    }
    // // Approach 2: Brute Force. TC: O(n^2) SC: O(1)
    // int findFinalValue(vector<int> &nums, int original)
    // {
    //     while (1)
    //     {
    //         for (int i = 0; i < nums.size(); i++)
    //         {
    //             if (nums[i] == original)
    //             {
    //                 original *= 2;
    //                 break;
    //             }
    //             if (i == nums.size() - 1)
    //             {
    //                 return original;
    //             }
    //         }
    //     }
    //     return original;
    // }
};
