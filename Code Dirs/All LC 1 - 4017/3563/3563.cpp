// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-adjacent-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)
// SC: O(n^2)
// Approach: DP
// 1. Let canRemove[i][j] = true if we can remove the substring s[i..j] completely, false otherwise.
// 2. Let f[i] = the lexicographically smallest string we can get from the substring s[i..n-1] after performing the operations.
// 3. The answer is f[0].
class Solution
{
    static constexpr int MAX_N = 250;
    static bool consecutive(char a, char b)
    {
        const int d = abs(static_cast<int>(a) - static_cast<int>(b));
        return d == 1 || d == 25;
    }

public:
    string lexicographicallySmallestString(string s)
    {
        const int n = static_cast<int>(s.size());
        array<bitset<MAX_N>, MAX_N> removable{};
        array<bitset<MAX_N>, MAX_N> startsBeforeEnd{};
        for (int len = 2; len <= n; len += 2)
        {
            for (int left = 0; left + len <= n; ++left)
            {
                const int right = left + len - 1;
                bool ok = consecutive(s[left], s[right]) &&
                          (len == 2 || removable[left + 1].test(right - 1));
                if (!ok && (removable[left] & startsBeforeEnd[right]).any())
                {
                    ok = true;
                }
                if (ok)
                {
                    removable[left].set(right);
                    if (left > 0)
                    {
                        startsBeforeEnd[right].set(left - 1);
                    }
                }
            }
        }
        vector<string> best(n + 1);
        for (int i = n - 1; i >= 0; --i)
        {
            if (removable[i].test(n - 1))
            {
                best[i].clear();
                continue;
            }
            bool hasCandidate = false;
            string chosen;
            for (int j = i; j < n; ++j)
            {
                if (j == i || removable[i].test(j - 1))
                {
                    string candidate;
                    candidate.reserve(best[j + 1].size() + 1);
                    candidate.push_back(s[j]);
                    candidate += best[j + 1];
                    if (!hasCandidate || candidate < chosen)
                    {
                        chosen = move(candidate);
                        hasCandidate = true;
                    }
                }
            }
            best[i] = move(chosen);
        }
        return best[0];
    }
};
