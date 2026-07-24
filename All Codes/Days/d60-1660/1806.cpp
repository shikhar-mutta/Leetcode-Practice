// Link: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(logn), SC: O(1)
    // Approach: Math
    //  1. We can observe that the permutation will return to its original state after a certain number of operations.
    //  2. We can simulate the operations and keep track of the position of the first element. When it returns to its original position, we can return the number of operations performed.
    //  3. We can use the formula pos = (pos * 2) % (n - 1) to calculate the new position of the first element after each operation
    //  4. We can continue this process until the position of the first element returns to its original position, and we can return the number of operations performed.
    int reinitializePermutation(int n)
    {
        if (n == 2)
            return 1;
        int pos = 1, steps = 0;
        do
        {
            pos = (pos * 2) % (n - 1);
            ++steps;
        } while (pos != 1);
        return steps;
    }
};
