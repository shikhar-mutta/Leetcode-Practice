// Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the string s.
// SC: O(1)
// Approach:
//   1. We first check if the length of the string s is odd. If it is, we return false because a valid parentheses string must have an even length.
//   2. We then initialize two variables, bMin and bMax, to keep track of the minimum and maximum number of open parentheses that can be formed at each index of the string s. We iterate through the string s and for each character, we update bMin and bMax based on whether the character is an open or closed parenthesis and whether the corresponding character in the locked string is locked or unlocked. If the character is an open parenthesis or unlocked, we increment bMax. If the character is a closed parenthesis or unlocked, we decrement bMin. If at any point bMax becomes negative, we return false because it means that there are more closed parentheses than open parentheses. We also ensure that bMin is always non-negative by taking the maximum of bMin and 0.
//   3. Finally, we return true if bMin is equal to 0, which means that we can form a valid parentheses string with the given locked and unlocked characters.
class Solution
{
public:
    static bool canBeValid(string &s, string &locked)
    {
        const int n = s.size();
        if (n & 1)
            return 0;
        int bMin = 0, bMax = 0;
        for (int i = 0; i < n; i++)
        {
            bool op = s[i] == '(', wild = locked[i] == '0';
            bMin += (!op | wild) ? -1 : 1;
            bMax += (op | wild) ? 1 : -1;
            if (bMax < 0)
                return 0;
            bMin = max(bMin, 0);
        }
        return bMin == 0;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
