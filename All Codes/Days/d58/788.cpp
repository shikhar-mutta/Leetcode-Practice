// Link: https://leetcode.com/problems/rotated-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(1)
    // Approach:
    // 1. Iterate through all numbers from 1 to n.
    // 2. For each number, check if it is valid and changed after rotation.
    // 3. If it is valid and changed, increment the count.
    // 4. Return the count.
    int rotatedDigits(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = i;
            bool valid = true, changed = false;
            while (x > 0)
            {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7)
                {
                    valid = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9)
                    changed = true;
                x /= 10;
            }
            if (valid && changed)
                count++;
        }
        return count;
    }
};
