// Link: https://leetcode.com/problems/push-dominoes/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach:
    // 1. Add 'L' at the beginning and 'R' at the end of the string to handle edge cases.
    // 2. Use two pointers, i and j, to traverse the string.
    // 3. When we find a non-dot character at position j, we check the character at position i.
    // 4. If they are the same (both 'L' or both 'R'), we fill the characters between i and j with the same character.
    // 5. If they are different (one is 'R' and the other is 'L'),
    //    we fill the characters between i and j with 'R' from i to the middle and 'L' from the middle to j.
    // 6. Finally, we return the substring of d from index 1 to the length of the original dominoes string.
    string pushDominoes(string dominoes)
    {
        string d = "L" + dominoes + "R";

        int i = 0;
        for (int j = 1; j < d.length(); ++j)
        {
            if (d[j] == '.')
                continue;

            if (d[i] == d[j]) // L...L or R...R
            {
                for (int k = i; k <= j; ++k)
                    d[k] = d[i];
            }
            else if (d[i] == 'R' && d[j] == 'L')
            {
                int x = i + 1;
                int y = j - 1;
                while (x < y)
                {
                    d[x++] = d[i];
                    d[y--] = d[j];
                }
            }

            i = j;
        }

        return d.substr(1, dominoes.length());
    }
};