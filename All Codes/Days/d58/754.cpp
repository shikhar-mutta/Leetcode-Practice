// Link: https://leetcode.com/problems/reach-a-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(target)), SC: O(1)
    //  Approach:
    //   1. The sum of the first n natural numbers is given by the formula n*(n+1)/2. We need to find the smallest n such that this sum is greater than or equal to the absolute value of the target.
    //   2. If the difference between the sum and the target is even, we can reach the target by flipping the sign of some of the numbers in the sequence. If the difference is odd, we need to keep increasing n until we find a sum that satisfies the condition.
    //   3. We can use a while loop to increment n and calculate the sum until we find a valid n that satisfies the conditions.
    //   4. Finally, we return the value of n as the minimum number of moves required to reach the target.
    int reachNumber(int target)
    {
        target = abs(target);
        long long sum = 0;
        int n = 0;
        while (sum < target || (sum - target) % 2 != 0)
        {
            n++;
            sum += n;
        }
        return n;
    }
};
