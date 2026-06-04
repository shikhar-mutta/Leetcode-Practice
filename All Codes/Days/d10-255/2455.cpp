// Link: https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: iterate. TC: O(n), SC: O(1)
    int averageValue(vector<int> &nums)
    {
        int sum = 0, count = 0;
        for (int num : nums)
        { // Check if the number is even and divisible by 3
            if (num % 2 == 0 && num % 3 == 0)
            {
                sum += num;
                count++;
            }
        }
        return count > 0 ? sum / count : 0;
    }
};
