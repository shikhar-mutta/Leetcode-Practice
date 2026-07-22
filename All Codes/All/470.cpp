// Link: https://leetcode.com/problems/implement-rand10-using-rand7/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) on average, O(infinity) in worst case
// SC: O(1)
// Approach:
// 1. Generate a random number from 1 to 49 using rand7() twice.
// 2. If the number is less than or equal to 40, return the number modulo 10 plus 1. Otherwise, repeat the process.
// 3. This ensures that the numbers 1 to 10 are generated with equal probability.
class Solution
{
public:
    int rand10()
    {
        while (true)
        {
            int row = rand7();
            int col = rand7();

            int num = (row - 1) * 7 + col; // 1 to 49

            if (num <= 40)
                return (num - 1) % 10 + 1;
        }
    }
};
