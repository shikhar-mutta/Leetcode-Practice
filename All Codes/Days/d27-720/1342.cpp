// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(1).
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num > 0 && ++steps)
            if (num % 2 == 0)
                num /= 2;
            else
                num -= 1;
        return steps;
    }
};
