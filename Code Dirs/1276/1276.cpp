// Link: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        int rem = tomatoSlices - 2 * cheeseSlices;
        if (rem < 0 || rem % 2)
            return {};
        int x = rem / 2;
        int y = cheeseSlices - x;
        if (y < 0)
            return {};
        return {x, y};
    }
};