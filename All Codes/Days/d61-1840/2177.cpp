// Link: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
//    Approach:
//    1. We can check if the given number is divisible by 3.
//    2. If it is not divisible by 3, we can return an empty vector.
//    3. If it is divisible by 3, we can calculate the middle number by dividing the given number by 3.
//    4. We can then return a vector containing the three consecutive integers: middle number - 1, middle number, and middle number + 1 as the answer.
class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        if (num % 3 != 0)
            return {};
        long long x = num / 3;
        return {x - 1, x, x + 1};
    }
};
