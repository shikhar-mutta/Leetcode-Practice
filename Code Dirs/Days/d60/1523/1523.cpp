// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
//   Approach:
//     1. The number of odd numbers in the range [low, high] can be calculated by finding the number of odd numbers from 1 to high and subtracting the number of odd numbers from 1 to low-1.
//     2. The number of odd numbers from 1 to n can be calculated as (n + 1) / 2. Therefore,
//        the number of odd numbers in the range [low, high] is (high + 1) / 2 - (low) / 2.
class Solution
{
public:
    int countOdds(int low, int high) { return (high + 1) / 2 - low / 2; }
};
