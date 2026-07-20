// Link: https://leetcode.com/problems/happy-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(logn) SC: O(logn)
    //  Approach:
    //  1. We can use a set to keep track of the numbers we have seen so far.
    //  2. We can keep calculating the sum of the squares of the digits of the number
    //    until we either reach 1 or we see a number that we have seen before.
    //  3. If we reach 1, then the number is happy. If we see a number that we have seen before, then the number is not happy.
    //  4. We can use a while loop to keep calculating the sum of the squares of the digits of the number until we either reach 1 or we see a number that we have seen before.
    //  5. We can use a set to keep track of the numbers we have seen so far.
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            int next = 0;
            while (n > 0)
            {
                int d = n % 10;
                next += d * d;
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};
