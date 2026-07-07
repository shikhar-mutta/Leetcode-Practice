// Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Any uncommon subsequence can be extended to a full string of the array,
    // so the answer is a whole string that is not a subsequence of any other.
    // TC: O(n^2 * m), where n is the number of strings and m is the average length of the strings. SC: O(1).
    int findLUSlength(vector<string> &strs)
    {
        int n = strs.size(), best = -1;
        for (int i = 0; i < n; i++)
        {
            bool uncommon = true;
            for (int j = 0; j < n && uncommon; j++)
                if (j != i && isSubseq(strs[i], strs[j]))
                    uncommon = false;
            if (uncommon)
                best = max(best, (int)strs[i].size());
        }
        return best;
    }

private:
    // true if a is a subsequence of b
    bool isSubseq(const string &a, const string &b)
    {
        size_t i = 0;
        for (char c : b)
            if (i < a.size() && a[i] == c)
                i++;
        return i == a.size();
    }
};
