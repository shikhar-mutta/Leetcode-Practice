// Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log3(n)), SC: O(1)
    // Approach: Greedy
    //   1. We can check if the number can be represented as a sum of distinct powers of three by checking if the number can be represented in base 3 without any digit being 2.
    //   2. If the number can be represented in base 3 without any digit being 2, then it can be represented as a sum of distinct powers of three.
    //   3. We can return true if the number can be represented in base 3 without any digit being 2, and false otherwise.
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};
