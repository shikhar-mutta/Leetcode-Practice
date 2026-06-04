// Link: https://leetcode.com/problems/min-max-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Repeatedly reduce until only one element remains.
    // TC: O(nlogn). SC: O(n).
    int minMaxGame(vector<int> &nums)
    {
        vector<int> temp;
        // The game is played until there is more than one element in the array.
        while (nums.size() > 1)
        {
            temp.clear(); // Clear the temporary vector for the next round.
            for (int i = 0; i < nums.size(); i += 2)
                if (i % 4 == 0)
                    temp.push_back(min(nums[i], nums[i + 1]));
                else
                    temp.push_back(max(nums[i], nums[i + 1]));
            nums = temp; // Update the original vector with the results of the current round.
        }
        return nums[0];
    }
};
