// Link: https://leetcode.com/problems/swap-adjacent-in-lr-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. The function checks if the transformation from the start string to the result string is possible by comparing the positions of 'L' and 'R' characters in both strings.
    //  2. It uses two pointers, i and j, to traverse the start and result strings respectively, skipping 'X' characters.
    //  3. If the characters at the current positions of i and j are different, or if the positions of 'L' and 'R' characters violate the transformation rules (i.e., 'L' cannot move right and 'R' cannot move left), the function returns false.
    //  4. If the traversal completes without any violations, the function returns true, indicating that the transformation is possible.
    //  5. The function also checks if the lengths of the start and result strings are equal, returning false if they are not.
    bool canTransform(string start, string result)
    {
        int n = start.size();
        if ((int)result.size() != n)
            return false;
        int i = 0, j = 0;
        while (i < n || j < n)
        {
            while (i < n && start[i] == 'X')
                i++;
            while (j < n && result[j] == 'X')
                j++;
            if (i == n && j == n)
                break;
            if (i == n || j == n)
                return false;
            if (start[i] != result[j])
                return false;
            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;
            i++;
            j++;
        }
        return true;
    }
};
