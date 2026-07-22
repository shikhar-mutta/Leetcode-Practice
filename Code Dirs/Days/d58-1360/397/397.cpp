// Link: https://leetcode.com/problems/integer-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    //  Approach:
    //  1. If the number is even, divide it by 2.
    //  2. If the number is odd, check if it is equal to 3 or if it is congruent to 1 modulo 4. If either condition is true, decrement the number by 1. Otherwise, increment the number by 1.
    //  3. Repeat steps 1 and 2 until the number becomes 1, counting the number of steps taken.
    //  4. Return the total number of steps taken to reach 1.
    int integerReplacement(int n)
    {
        long long num = n;
        int steps = 0;
        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else if (num == 3 || num % 4 == 1)
                num--;
            else
                num++;
            steps++;
        }
        return steps;
    }
};
