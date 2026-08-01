// Link: https://leetcode.com/problems/lexicographically-smallest-generated-string/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+m) log or O(n+m))  SC: O(n+m)
// Approach: str1[i]=='T' forces str2 to occur starting at i in the
// result (n+m-1 length); overlapping T's are checked for consistency via
// str2's Z-function (self-overlap). Fill the rest greedily with 'a'
// (lexicographically smallest), then re-scan: wherever str1[i]=='F' but
// the current fill accidentally matches str2 there (detected via the
// Z-function of str2+'#'+candidate), bump the rightmost still-mutable
// ('a'-filled, not T-forced) position within that window to 'b' to break
// the match, tracked via a sliding-window deque of mutable indices.
class Solution
{
    vector<int> zFunction(const string &s)
    {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    string generateString(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        string candidate(n + m - 1, '*');
        vector<int> z = zFunction(str2);
        int prev = -m;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] != 'T')
                continue;
            int diff = i - prev;
            if (diff < m)
            {
                if (z[diff] == m - diff)
                {
                    for (int k = prev + m; k < i + m; k++)
                        candidate[k] = str2[m - diff + (k - (prev + m))];
                }
                else
                    return "";
            }
            else
            {
                for (int k = 0; k < m; k++)
                    candidate[i + k] = str2[k];
            }
            prev = i;
        }

        string result = str2 + "#" + candidate;
        vector<int> idxs;
        for (int i = m + 1; i < (int)result.size(); i++)
        {
            if (result[i] == '*')
            {
                result[i] = 'a';
                idxs.push_back(i);
            }
        }
        vector<int> zres = zFunction(result);

        deque<int> dq;
        int i = m + 1, j = 0;
        while (i - (m + 1) < n)
        {
            while (!dq.empty() && dq.front() < i)
                dq.pop_front();
            while (j < (int)idxs.size() && idxs[j] <= i + (m - 1))
            {
                dq.push_back(idxs[j]);
                j++;
            }
            if (str1[i - (m + 1)] == 'F' && zres[i] == m)
            {
                if (dq.empty())
                    return "";
                result[dq.back()] = 'b';
                i += m;
            }
            else
            {
                i++;
            }
        }
        return result.substr(m + 1);
    }
};
