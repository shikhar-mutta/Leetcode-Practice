// Link: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1000) as we are iterating through the values of x from 1 to 1000 and for each value of x, we are checking the corresponding value of y using the given equation. The maximum number of iterations will be 1000.
    // SC: O(1) as we are using a constant amount of extra space for the result vector and the variables x and y.
    //   Approach:
    //   1. We will iterate through the values of x from 1 to 1000 and for each value of x, we will check the corresponding value of y using the given equation f(x, y) = z.
    //   2. If the value of f(x, y) is less than z, we will increment the value of x. If the value of f(x, y) is greater than z, we will decrement the value of y.
    //   3. If the value of f(x, y) is equal to z, we will add the pair (x, y) to the result vector and increment the value of x and decrement the value of y to check for other possible pairs.
    //   4. We will continue this process until we have checked all possible values of x and y.
    //   5. Finally, we will return the result vector containing all the pairs (x, y) that satisfy the equation f(x, y) = z.
    std::vector<std::vector<int>> findSolution(CustomFunction &getter, int z)
    {
        std::vector<std::vector<int>> result;
        for (int x = 1, y = 1000; x <= 1000 && y >= 1;)
        {
            if (getter.f(x, y) < z)
            {
                ++x;
            }
            else if (getter.f(x, y) > z)
            {
                --y;
            }
            else
            {
                result.push_back({x++, y--});
            }
        }
        return result;
    }
};