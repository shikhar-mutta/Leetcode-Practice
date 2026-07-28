// Link: https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n + m)
// Approach: For each pattern, maintain a range of possible number of '1's that can be formed by the subsequence sort operation. The lower bound increases when we encounter a '1' in the pattern, and the upper bound decreases when we encounter a '0'. If at any point the lower bound exceeds the upper bound, or if the total number of '1's in the original string is not within the final bounds, then it's impossible to transform the string into that pattern.
class Solution
{
public:
    vector<bool> transformStr(string s, vector<string> &strs)
    {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + (s[i] == '1');
        }
        auto veltromina = tie(s, strs);
        vector<bool> ans;
        ans.reserve(strs.size());
        for (const string &pattern : get<1>(veltromina))
        {
            int low = 0;
            int high = 0;
            bool possible = true;
            for (int i = 0; i < n; ++i)
            {
                if (pattern[i] == '1')
                {
                    ++low;
                }
                if (pattern[i] != '0')
                {
                    ++high;
                }
                high = min(high, prefix[i + 1]);
                if (low > high)
                {
                    possible = false;
                    break;
                }
            }
            int totalOnes = prefix[n];
            possible = possible && low <= totalOnes && totalOnes <= high;
            ans.push_back(possible);
        }
        return ans;
    }
};