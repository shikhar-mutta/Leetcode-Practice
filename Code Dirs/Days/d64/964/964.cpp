// Link: https://leetcode.com/problems/least-operators-to-express-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(target)) SC: O(1)
//  Approach: We can use a greedy approach to solve this problem. We can keep track of the positive and negative costs of expressing the target number using the given base x. We can iterate through each digit of the target number in base x and update the positive and negative costs accordingly. The final answer will be the minimum of the positive and negative costs minus 1 (to account for the initial multiplication by x).
class Solution
{
public:
    using ll = long long;
    int leastOpsExpressTarget(int x, int target)
    {
        if (x == 1)
            return target - 1;
        ll positive = 0;
        ll negative = 0;
        int power = 0;
        while (target > 0)
        {
            int digit = target % x;
            target /= x;

            if (power == 0)
            {
                positive = 2LL * digit;
                negative = 2LL * (x - digit);
            }
            else
            {
                ll nextPositive = min(positive + 1LL * digit * power,
                                      negative + 1LL * (digit + 1) * power);

                ll nextNegative = min(positive + 1LL * (x - digit) * power,
                                      negative + 1LL * (x - digit - 1) * power);

                positive = nextPositive;
                negative = nextNegative;
            }
            ++power;
        }
        return min(positive, negative + power) - 1;
    }
};