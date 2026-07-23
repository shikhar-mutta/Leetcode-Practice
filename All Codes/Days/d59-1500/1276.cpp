// Link: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    //  Approach:
    //  1. Let x be the number of jumbo burgers and y be the number of small burgers.
    //  2. We have two equations based on the ingredients:
    //     a. 4x + 2y = tomatoSlices (for tomato slices)
    //     b. x + y = cheeseSlices (for cheese slices)
    //  3. From the second equation, we can express y in terms of x:
    //     y = cheeseSlices - x
    //  4. Substitute y in the first equation:
    //     4x + 2(cheeseSlices - x) = tomatoSlices
    //     4x + 2cheeseSlices - 2x = tomatoSlices
    //     2x + 2cheeseSlices = tomatoSlices
    //     2x = tomatoSlices - 2cheeseSlices
    //     x = (tomatoSlices - 2 * cheeseSlices) / 2
    //  5. Now we can find y:
    //     y = cheeseSlices - x
    //  6. We need to ensure that x and y are non-negative integers. This means that:
    //     a. tomatoSlices - 2 * cheeseSlices >= 0 (so that x is non-negative)
    //     b. (tomatoSlices - 2 * cheeseSlices) % 2 == 0 (so that x is an integer)
    //     c. cheeseSlices - x >= 0 (so that y is non-negative)
    //  7. If any of these conditions are not met, return an empty vector. Otherwise, return the vector {x, y}.
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