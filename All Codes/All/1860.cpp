// Link: https://leetcode.com/problems/incremental-memory-leak/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)), SC: O(1)
// Approach:
//   1. We can use a while loop to simulate the memory leak process.
//   2. We can use a variable t to keep track of the current time step.
//   3. In each iteration of the loop, we can check if memory1 is greater than or equal to memory2. If it is, we can decrement memory1 by t. Otherwise, we can decrement memory2 by t.
//   4. We can increment t by 1 in each iteration of the loop.
//   5. We can continue the loop until both memory1 and memory2 are less than t.
//   6. Finally, we can return a vector containing t, memory1, and memory2.
class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int t = 1;
        while (t <= memory1 || t <= memory2)
        {
            if (memory1 >= memory2)
            {
                memory1 -= t;
            }
            else
            {
                memory2 -= t;
            }
            t++;
        }
        return {t, memory1, memory2};
    }
};
