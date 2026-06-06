// Link: https://leetcode.com/problems/snake-in-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m). SC: O(1).
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int curr = 0;
        for (auto it : commands)
        {
            if (it == "UP")
                curr -= n;
            else if (it == "DOWN")
                curr += n;
            else if (it == "RIGHT")
                curr++;
            else if (it == "LEFT")
                curr--;
        }
        return curr;
    }
};
