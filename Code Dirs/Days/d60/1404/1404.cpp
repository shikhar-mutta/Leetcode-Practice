// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. Start from the least significant bit (rightmost) and iterate towards the most significant bit (leftmost).
    //  2. Keep track of a carry variable to handle the addition when the current bit is 1.
    //  3. For each bit, if it's 1, we need to perform two operations: add 1 (which may cause a carry) and then divide by 2. If it's 0, we only need to perform one operation: divide by 2.
    //  4. The carry variable is updated based on the current bit and the previous carry. If the current bit is 1 and there's a carry, the next bit will also be affected, so we need to account for that in the next iteration.
    //  5. Finally, we return the total number of steps plus any remaining carry, which indicates that we need one more step to reduce the number to 1.
    int numSteps(string s)
    {
        int carry = 0, steps = 0;
        for (int i = s.size() - 1; i > 0; --i)
        {
            int bit = (s[i] - '0') + carry;
            if (bit == 1)
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps += 1;
                carry = (bit == 2) ? 1 : 0;
            }
        }
        return steps + carry;
    }
};