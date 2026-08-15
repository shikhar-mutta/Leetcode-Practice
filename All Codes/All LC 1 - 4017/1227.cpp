// Link: https://leetcode.com/problems/airplane-seat-assignment-probability/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // TC: O(1) as we are only performing a constant number of operations regardless of the input size.
    // SC: O(1) as we are using a constant amount of extra space for the variables and the return value.
    //   Approach:
    //   1. If there is only one person, they will always sit in their assigned seat, so the probability is 1.0.
    //   2. If there are more than one person, the first person has a 50% chance of sitting in their assigned seat and a 50% chance of sitting in the last person's seat. If the first person sits in their assigned seat, the last person will also sit in their assigned seat. If the first person sits in the last person's seat, the last person will not sit in their assigned seat. Therefore, the probability of the last person sitting in their assigned seat is 0.5.
    //   3. We can return the probability as a double value.
public:
    double nthPersonGetsNthSeat(int n) { return n == 1 ? 1.0 : 0.5; }
};