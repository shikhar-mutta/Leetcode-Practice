// Link: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(neededApples)) where neededApples is the number of apples needed
// SC: O(1)
//  Approach: Binary Search
// 1. The number of apples in the garden is given by the formula: apples = 2 * n * (n + 1) * (2 * n + 1) where n is the side length of the garden.
// 2. We can use binary search to find the minimum side length n such that apples >= neededApples.
// 3. The perimeter of the garden is given by the formula: perimeter = 4 * side = 4 * 2n = 8n.
class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long lo = 1, hi = 100000;
        while (lo < hi)
        {
            long long n = lo + (hi - lo) / 2;
            long long apples = 2 * n * (n + 1) * (2 * n + 1);
            if (apples >= neededApples)
                hi = n;
            else
                lo = n + 1;
        }
        return lo * 8; // perimeter = 4 * side = 4 * 2n = 8n
    }
};