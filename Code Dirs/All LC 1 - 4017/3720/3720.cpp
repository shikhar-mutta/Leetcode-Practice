// Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26) SC: O(n)
// Approach: greedily try to match target exactly using the available
// multiset of s's characters as far as possible; that longest matchable
// prefix is where any "increase" (strictly greater char) must happen for
// the smallest result — keeping the tie prefix as long as possible.
// Starting from that break point, walk backward: at each candidate
// position, look for the smallest available char strictly greater than
// target there; if found, place it and fill the rest ascending (smallest
// completion). If not found, undo the match at the previous position
// (restore its char to the pool) and try one position earlier.
class Solution
{
public:
    bool solve(vector<char> &path, vector<int> &cnt, string &target, bool big, string &ans)
    {
        int n = target.size();
        if (!ans.empty())
            return true;

        if (n == path.size())
        {
            if (big)
            {
                ans = string(path.begin(), path.end());
                return true;
            }
            return false;
        }
        int i = path.size();
        for (int c = 0; c < 26; c++)
        {
            if (cnt[c] == 0)
                continue;
            if (!big && (c + 'a' < target[i]))
                continue;
            path.push_back(c + 'a');
            cnt[c]--;
            bool newbig = big || (c + 'a' > target[i]);
            if (solve(path, cnt, target, newbig, ans))
                return true;
            path.pop_back();
            cnt[c]++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> cnt(26, 0);
        for (char ch : s)
        {
            cnt[ch - 'a']++;
        }
        string ans = "";
        vector<char> path;
        solve(path, cnt, target, false, ans);
        return ans;
    }
};