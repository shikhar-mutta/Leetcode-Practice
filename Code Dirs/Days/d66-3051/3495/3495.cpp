// Link: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n)) SC: O(1)
// Approach: We can use the fact that the number of operations required to make an element zero is equal to the number of 1s in its binary representation. We can precompute the sum of the number of 1s in the binary representation of all numbers from 0 to n using a recursive formula. The number of operations required to make all elements in the range [l, r] zero is equal to the sum of the number of 1s in the binary representation of all numbers from l to r. We can calculate this sum using our precomputed values.
long long expSum4[18] = {0};
class Solution
{
public:
    static long long expSum(unsigned x)
    {
        if (x == 0)
            return 0;
        int log4 = (31 - countl_zero(x)) / 2;
        int r = x - (1 << (2 * log4));
        return expSum4[log4] + r * (log4 + 1LL);
    }
    static void precompute()
    {
        if (expSum4[0] == 1)
            return;
        expSum4[0] = 1;
        for (int i = 1; i < 18; i++)
        {
            expSum4[i] = expSum4[i - 1] + 3LL * i * (1LL << (2 * (i - 1))) + 1;
            //    cout<<i<<"->"<<expSum4[i]<<", ";
        }
    }
    static long long minOperations(vector<vector<int>> &queries)
    {
        precompute();
        long long op = 0;
        for (auto &q : queries)
        {
            int l = q[0] - 1, r = q[1];
            op += (expSum(r) - expSum(l) + 1) /
                  2; // ceiling of (expSum(r)-expSum(l))/2
        }
        return op;
    }
};
