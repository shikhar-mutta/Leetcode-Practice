// Link: https://leetcode.com/problems/select-k-disjoint-special-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(1)
    //  Approach:
    //  1. Create two arrays fst and lst of size 26 to store the first and last occurrence of each character in the string s.
    //  2. Iterate through the string s and update the fst and lst arrays with the first and last occurrence of each character.
    //  3. Create a vector of pairs iv to store the intervals of the special substrings.
    //  4. Iterate through the characters from 'a' to 'z' and for each character, check if it has a valid interval. If it does, add the interval to the iv vector.
    //  5. Sort the iv vector based on the end of the intervals.
    //  6. Iterate through the sorted intervals and count the number of disjoint intervals.
    bool maxSubstringLength(string s, int k)
    {
        if (k == 0)
            return true;
        int n = s.size();
        vector<int> fst(26, -1), lst(26, -1);
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (fst[c] < 0)
                fst[c] = i;
            lst[c] = i;
        }
        vector<pair<int, int>> iv;
        for (int c = 0; c < 26; c++)
        {
            int i = fst[c];
            if (i < 0)
                continue;
            int r = lst[c];
            bool ok = true;
            for (int j = i; j <= r; j++)
            {
                int d = s[j] - 'a';
                if (fst[d] < i)
                {
                    ok = false;
                    break;
                }
                r = max(r, lst[d]);
            }
            if (ok && !(i == 0 && r == n - 1))
                iv.push_back({r, i});
        }
        sort(iv.begin(), iv.end());
        int cnt = 0, prevEnd = -1;
        for (auto &[r, l] : iv)
        {
            if (l > prevEnd)
            {
                cnt++;
                prevEnd = r;
            }
        }
        return cnt >= k;
    }
};
