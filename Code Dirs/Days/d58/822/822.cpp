// Link: https://leetcode.com/problems/card-flipping-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//  1. We can use an unordered_map to keep track of the numbers that are present on both the front and back of the cards. If a number is present on both sides of a card, we can ignore it as it cannot be the answer.
//  2. We can then iterate through the front and back of the cards and check if the number is present in the unordered_map.
//  3. If the number is not present in the unordered_map, we can update the answer with the minimum value of the number and the current answer.
//  4. Finally, we can return the answer if it is not equal to INT_MAX, otherwise we can return 0 as there is no valid number that can be chosen.
class Solution
{
public:
    int flipgame(vector<int> &front, vector<int> &back)
    {
        int n = front.size(), ans = INT_MAX;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            if (front[i] == back[i])
                um[front[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!um.count(front[i]))
            {
                ans = min(ans, front[i]);
                um[front[i]]++;
            }
            if (!um.count(back[i]))
            {
                ans = min(ans, back[i]);
                um[back[i]]++;
            }
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};
