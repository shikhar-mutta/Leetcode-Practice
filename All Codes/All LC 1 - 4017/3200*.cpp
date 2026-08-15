// Link: https://leetcode.com/problems/maximum-height-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(red + blue). SC: O(1).
    int maxHeightOfTriangle(int red, int blue)
    {
        auto simulate = [](int a, int b)
        {
            int count = 1, ans = 0;
            while (true) // simulate the process of building the triangle
            {
                if (count % 2 == 1)
                {
                    if (a >= count)
                        a -= count;
                    else
                        break;
                }
                else
                {
                    if (b >= count)
                        b -= count;
                    else
                        break;
                }
                count++;
                ans++;
            }
            return ans;
        };
        // Try both possibilities
        return max(simulate(red, blue), simulate(blue, red));
    }
};
