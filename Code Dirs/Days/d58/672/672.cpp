// Link: https://leetcode.com/problems/bulb-switcher-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) since the number of unique states is limited to 8 (2^3) for n >= 3, and we only consider a constant number of combinations of button presses.
    // SC: O(1) since we are using a set to store the unique states
    //  Approach:
    //  1. We limit n to a maximum of 3 since the pattern of bulb states repeats every 3 bulbs.
    //  2. We use a set to store unique states of the bulbs after applying the button presses.
    //  3. We iterate through all combinations of button presses (a, b, c, d) where each button can be pressed 0 or 1 times.

    //  4. For each combination, we check if the total number of presses is less than or equal to the allowed presses and if the parity of the remaining presses is even (to ensure we can reach that state).
    //  5. We calculate the resulting state of the bulbs based on the button presses and store it in the set.
    //  6. Finally, we return the size of the set, which represents the number of unique states of the bulbs after the allowed presses.
    int flipLights(int n, int presses)
    {
        n = min(n, 3);
        set<int> seen;
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                for (int c = 0; c <= 1; c++)
                    for (int d = 0; d <= 1; d++)
                    {
                        int total = a + b + c + d;
                        if (total > presses)
                            continue;
                        if ((presses - total) % 2 != 0)
                            continue;

                        int state = 0;
                        for (int j = 0; j < n; j++)
                        {
                            int val = 1;
                            val ^= a;
                            if (j % 2 == 1)
                                val ^= b;
                            if (j % 2 == 0)
                                val ^= c;
                            if (j % 3 == 0)
                                val ^= d;
                            if (val)
                                state |= (1 << j);
                        }
                        seen.insert(state);
                    }
        return seen.size();
    }
};
