// Link: https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n1*n2*range) with small constant (digit groups <=3 long)  SC: same
// Approach: memoized DFS over (i, j, diff) where diff = virtual chars s1 has
// matched ahead of s2 (negative if s2 is ahead). At diff==0 either match
// literal chars or start reading a number from either side (shifting diff by
// its value). When diff!=0, the "ahead" side's excess absorbs one character
// from the other side per step. Goal: reach the end with diff==0.
class Solution {
    string s1, s2;
    int n1, n2;
    map<tuple<int,int,int>, int> memo; // 0 unknown, 1 true, 2 false

    bool solve(int i, int j, int diff) {
        if (i == n1 && j == n2) return diff == 0;
        auto key = make_tuple(i, j, diff);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second == 1;

        bool res = false;
        if (diff == 0) {
            if (i < n1 && j < n2 && s1[i] == s2[j]) res = res || solve(i + 1, j + 1, 0);
        } else if (diff > 0) {
            if (j < n2) res = res || solve(i, j + 1, diff - 1);
        } else {
            if (i < n1) res = res || solve(i + 1, j, diff + 1);
        }

        if (!res && i < n1 && isdigit(s1[i])) {
            int val = 0;
            for (int k = i; k < n1 && k < i + 3 && isdigit(s1[k]); k++) {
                val = val * 10 + (s1[k] - '0');
                res = res || solve(k + 1, j, diff + val);
                if (res) break;
            }
        }
        if (!res && j < n2 && isdigit(s2[j])) {
            int val = 0;
            for (int k = j; k < n2 && k < j + 3 && isdigit(s2[k]); k++) {
                val = val * 10 + (s2[k] - '0');
                res = res || solve(i, k + 1, diff - val);
                if (res) break;
            }
        }

        memo[key] = res ? 1 : 2;
        return res;
    }
public:
    bool possiblyEquals(string s1_, string s2_) {
        s1 = s1_; s2 = s2_;
        n1 = s1.size(); n2 = s2.size();
        return solve(0, 0, 0);
    }
};
