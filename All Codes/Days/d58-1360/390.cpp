// Link: https://leetcode.com/problems/elimination-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) where n is the size of the input array. We are iterating through the array log n times, as we are halving the size of the array in each iteration.
    // SC: O(1) as we are using a constant amount of space to store the variables head, step, remaining, and leftToRight.
    //  Approach:
    //  1. We can keep track of the head of the array, the step size, the number of remaining elements, and the direction of elimination (left to right or right to left).
    //  2. In each iteration, we can update the head of the array based on the direction of elimination and the number of remaining elements.
    //  3. We can halve the number of remaining elements and double the step size in each iteration.
    //  4. We can continue this process until there is only one element remaining, which will be the last remaining element in the array.
    //  5. We can return the last remaining element as the result.
    int lastRemaining(int n)
    {
        long long head = 1, step = 1, remaining = n;
        bool leftToRight = true;
        while (remaining > 1)
        {
            if (leftToRight || remaining % 2 == 1)
                head += step;
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return (int)head;
    }
};
