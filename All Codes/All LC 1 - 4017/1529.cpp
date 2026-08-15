// Link: https://leetcode.com/problems/minimum-suffix-flips/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    //  Approach:
    //    1. We will keep track of the current state of the string and the number of flips required to make the string equal to the target.
    //    2. We will iterate through the target string and for each character, we will check if it is equal to the current state of the string. If it is not, we will increment the number of flips and change the current state of the string to the opposite character.
    //    3. We will return the number of flips required to make the string equal to the target.
    int minFlips(string target)
    {
        int flips = 0;
        char current = '0';

        for (char c : target)
        {
            if (c != current)
            {
                flips++;
                current = (current == '0') ? '1' : '0';
            }
        }

        return flips;
    }
};