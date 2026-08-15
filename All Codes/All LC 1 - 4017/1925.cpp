// Link: https://leetcode.com/problems/count-square-sum-triples/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(1)
// Approach:
//   1. We can iterate through all possible values of a and b from 1 to n and calculate the sum of their squares. We can then check if the square root of that sum is an integer and less than or equal to n. If it is, we can increment the count of valid triples. Finally, we can return the count of valid triples.
class Solution
{
public:
    int countTriples(int n)
    {
        int res = 0;
        for (int a = 1; a <= n; ++a)
        {
            for (int b = 1; b <= n; ++b)
            {
                int sum = a * a + b * b;
                int c = (int)sqrt((double)sum);
                if (c <= n && c * c == sum)
                    ++res;
            }
        }
        return res;
    }
};