// Link: https://leetcode.com/problems/alphabet-board-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the target string
    // SC: O(n) for the result string
    //   Approach:
    //    1. Start at the position of 'a' on the board, which is at coordinates (0, 0).
    //    2. For each character in the target string, calculate its coordinates on the board using integer division and modulo operations.
    //    3. Move vertically first (up or down) to reach the target row, then move horizontally (left or right) to reach the target column. This order is important to avoid moving out of bounds when moving to 'z'.
    //    4. Append the corresponding move characters ('U', 'D', 'L', 'R') to the result string for each move made.
    // 5. After reaching the target character, append '!' to the result string to indicate selection.
    //    6. Update the current position to the target character's coordinates and repeat for the next character in the target string.
    //    7. Return the result string after processing all characters in the target string.
    string alphabetBoardPath(string target)
    {
        string res;
        int r = 0, c = 0; // start at 'a' = (0,0)

        for (char ch : target)
        {
            int nr = (ch - 'a') / 5;
            int nc = (ch - 'a') % 5;

            // move up and left first, down and right last
            while (r > nr)
            {
                res += 'U';
                r--;
            }
            while (c > nc)
            {
                res += 'L';
                c--;
            }
            while (c < nc)
            {
                res += 'R';
                c++;
            }
            while (r < nr)
            {
                res += 'D';
                r++;
            }

            res += '!';
        }
        return res;
    }
};