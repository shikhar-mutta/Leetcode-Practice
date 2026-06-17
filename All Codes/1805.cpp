// Link: https://leetcode.com/problems/number-of-different-integers-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int numDifferentIntegers(string word)
    {
        set<string> nums; // store as strings — values can exceed any int type
        int n = word.size();
        for (int i = 0; i < n;)
        {
            if (!isdigit((unsigned char)word[i]))
            {
                i++;
                continue;
            }
            int j = i;
            while (j < n && isdigit((unsigned char)word[j]))
                j++; // [i, j) is a digit run
            int s = i;
            while (s < j - 1 && word[s] == '0')
                s++; // skip leading zeros
            nums.insert(word.substr(s, j - s));
            i = j;
        }
        return nums.size();
    }
};
