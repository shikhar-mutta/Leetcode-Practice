// Link: https://leetcode.com/problems/naming-a-company/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + 26^2), SC: O(N + 26^2)
//  Approach: For each suffix, maintain a bitmask of the first letters of the words that have that suffix. Then, for each pair of first letters (a, b), the number of valid pairs of words that can be formed by swapping the first letters is (total[a] - both[a][b]) * (total[b] - both[a][b]), where total[a] is the total number of words that start with letter a, and both[a][b] is the number of words that start with letter a and have a suffix that also has a word starting with letter b
class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_map<string, int> maskOf;
        maskOf.reserve(ideas.size() * 2);
        maskOf.max_load_factor(0.7f);

        for (const string &s : ideas)
        {
            maskOf[s.substr(1)] |= 1 << (s[0] - 'a');
        }

        long long total[26] = {};
        long long both[26][26] = {};

        for (const auto &[suf, m] : maskOf)
        {
            for (int x = m; x; x &= x - 1)
            {
                int a = __builtin_ctz(x);
                total[a]++;

                for (int y = x & (x - 1); y; y &= y - 1)
                    both[a][__builtin_ctz(y)]++;
            }
        }

        long long ans = 0;
        for (int a = 0; a < 26; a++)
        {
            for (int b = a + 1; b < 26; b++)
            {
                long long ua = total[a] - both[a][b];
                long long ub = total[b] - both[a][b];
                ans += ub * ua * 2;
            }
        }

        return ans;
    }
};