// Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(max(start, goal))), SC: O(log(max(start, goal)))
    string toBinary(int n)
    {
        string res = "";
        while (n > 0)
        {
            res += (n % 2 == 0 ? "0" : "1");
            n /= 2;
        }
        return res;
    }
    int minBitFlips(int start, int goal)
    {
        string start_binary = toBinary(start);
        string goal_binary = toBinary(goal);
        // length of binary representation of start and goal
        int start_len = start_binary.length();
        int goal_len = goal_binary.length();
        // maximum length of binary representation of start and goal
        int max_len = max(start_len, goal_len);
        int count = 0;
        for (int i = 0; i < max_len; i++)
        {
            char start_bit = (i < start_len) ? start_binary[i] : '0';
            char goal_bit = (i < goal_len) ? goal_binary[i] : '0';
            if (start_bit != goal_bit)
                count++;
        }
        return count;
    }
};
