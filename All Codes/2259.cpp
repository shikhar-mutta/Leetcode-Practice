// Link: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of number; SC: O(n)
    string removeDigit(string number, char digit)
    {
        string best = "";
        // try removing each occurrence of digit; keep the largest result
        for (int i = 0; i < (int)number.size(); i++)
            if (number[i] == digit)
            {
                string cand = number.substr(0, i) + number.substr(i + 1);
                best = max(best, cand); // equal length => lexicographic == numeric
            }
        return best;
    }
};
