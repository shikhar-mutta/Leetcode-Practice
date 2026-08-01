// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
//  Approach: Find the GCD of numsDivide. Sort nums. Iterate through nums and find the first number that divides the GCD. The index of that number is the minimum deletions required.
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int g = numsDivide[0];
        for (int x : numsDivide)
            g = __gcd(g, x);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (g % nums[i] == 0)
                return i;
        }
        return -1;
    }
};