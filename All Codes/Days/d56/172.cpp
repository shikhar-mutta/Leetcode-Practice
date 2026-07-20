// Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log5(N)) SC: O(1)
    // Approach:
    // 1. The number of trailing zeroes in n! is equal to the number of times 5 is a factor in the numbers from 1 to n. This is because there are always more factors of 2 than factors of 5 in the numbers from 1 to n.
    // 2. We can count the number of times 5 is a factor in the numbers from 1 to n by repeatedly dividing n by 5 and adding the quotient to a count. We continue this process until n becomes 0.
    // 3. The final count will be the number of trailing zeroes in n!.
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};
