// Link: https://leetcode.com/problems/sum-of-square-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(c)), where c is the input number. In the worst case, we may need to check all pairs of numbers from 0 to sqrt(c).
    // SC: O(1), as we are using only a constant amount of extra space
    // Approach:
    //  1. We initialize two pointers, a and b, where a starts from 0 and b starts from sqrt(c).
    //  2. We calculate the sum of squares of a and b.
    //  3. If the sum is equal to c, we return true.
    //  4. If the sum is less than c, we increment a to increase the sum.
    //  5. If the sum is greater than c, we decrement b to decrease the sum.
    //  6. We repeat steps 2-5 until a is less than or equal to b. If we exit the loop without finding a valid pair, we return false.
    //  This approach works because the sum of squares is a monotonically increasing function with respect to both a and b, allowing us to efficiently search for a valid pair using the two-pointer technique.
    bool judgeSquareSum(int c)
    {
        long long a = 0, b = (long long)sqrt(c);
        while (a <= b)
        {
            long long sum = a * a + b * b;
            if (sum == c)
                return true;
            else if (sum < c)
                a++;
            else
                b--;
        }
        return false;
    }
};
