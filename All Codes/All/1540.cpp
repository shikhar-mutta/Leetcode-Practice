// Link: https://leetcode.com/problems/can-convert-string-in-k-moves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    //  Approach:
    //    1. We will keep track of the number of times we can use each shift (1 to 25) in the used array.
    //    2. We will iterate through the strings s and t and for each character, we will check if they are equal.
    //    3. If they are not equal, we will calculate the shift required to convert s[i] to t[i] and decrement the corresponding value in the used array.
    //    4. If the value in the used array becomes negative, we will return false.
    //    5. If we can convert all characters, we will return true.
    bool canConvertString(string s, string t, int k)
    {
        vector<int> used(26, k / 26);
        for (int i = 0; i < 26; i++)
        {
            if (i <= k % 26)
            {
                used[i]++;
            }
            else
                break;
        }
        int n = s.size();
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                int add = t[i] - s[i];
                if (s[i] > t[i])
                    add = 26 + add;
                used[add]--;
                if (used[add] < 0)
                    return false;
            }
        }
        return true;
    }
};