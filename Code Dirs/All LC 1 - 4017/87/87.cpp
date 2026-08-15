// Link: https://leetcode.com/problems/scramble-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^4)  SC: O(n^3) memo
// Approach: memoized recursion — try every split point, checking both non-swapped and swapped pairings of the halves;
// prune early via character-count mismatch
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
private:
    unordered_map<string,bool> memo;
    bool solve(const string& s1, const string& s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        string key = s1 + "#" + s2;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        int n = s1.size();
        int cnt[26] = {0};
        for (int i = 0; i < n; i++) { cnt[s1[i]-'a']++; cnt[s2[i]-'a']--; }
        for (int c : cnt) if (c != 0) { memo[key] = false; return false; }
        bool res = false;
        for (int i = 1; i < n && !res; i++) {
            if (solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i), s2.substr(i))) res = true;
            else if (solve(s1.substr(0,i), s2.substr(n-i)) && solve(s1.substr(i), s2.substr(0,n-i))) res = true;
        }
        memo[key] = res;
        return res;
    }
};
