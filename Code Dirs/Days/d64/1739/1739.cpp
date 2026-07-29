// Link: https://leetcode.com/problems/building-boxes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) SC: O(1)
//   Approach: Math
//    We can use math to solve this problem. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use binary search to find the maximum height of the pyramid that can be built with n boxes. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid. We can use the formula for the sum of the first n natural numbers to calculate the number of boxes needed to build the pyramid
class Solution
{
public:
    int minimumBoxes(int n)
    {
        long long H = 0, total = 0;
        while (total + (H + 1) * (H + 2) / 2 <= n)
        {
            H++;
            total += H * (H + 1) / 2;
        }
        long long ground = H * (H + 1) / 2;
        long long remaining = n - total;
        long long y = 0;
        while (y * (y + 1) / 2 < remaining)
            y++;
        ground += y;
        return (int)ground;
    }
};
