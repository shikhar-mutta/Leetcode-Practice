// Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
//  Approach: contribution technique. For each character c at index i,
//  it counts as "unique" in exactly those substrings where no other
//  occurrence of c is present, i.e. substrings starting after the
//  previous occurrence of c and ending before the next occurrence. That
//  count is (i - prev) * (next - i), summed over all indices.
class Solution
{
public:
    int uniqueLetterString(string s)
    {
        vector<int> prev(26, -1), last(26, -1);
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans +=
                (last[s[i] - 'A'] - prev[s[i] - 'A']) * (i - last[s[i] - 'A']);
            prev[s[i] - 'A'] = last[s[i] - 'A'];
            last[s[i] - 'A'] = i;
        }
        for (int i = 0; i < 26; i++)
        {
            ans += (last[i] - prev[i]) * (n - last[i]);
        }

        return ans;
    }
};