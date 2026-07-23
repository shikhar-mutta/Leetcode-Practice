// Link: https://leetcode.com/problems/broken-calculator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(target)) where target is the target value.
    // SC: O(1)
    // Approach:
    //   1. We will start from the target value and keep dividing it by 2 until it becomes less than or equal to the startValue.
    //   2. If the target value is odd, we will increment it by 1 to make it even and then divide it by 2.
    //   3. We will keep track of the number of operations performed and return the total number of operations required to reach the startValue from the target value.
    //   4. Finally, we will add the difference between startValue and target to the number of operations performed to get the final answer.
    int brokenCalc(int startValue, int target)
    {
        int ops = 0;
        while (target > startValue)
        {
            if (target % 2 == 1)
                target++;
            else
                target /= 2;
            ops++;
        }
        return ops + (startValue - target);
    }
};
