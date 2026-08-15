// Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n), SC: O(n) recursion depth
// Approach: Backtrack building strings of length n; '1' can always be
// appended, but '0' only when the previous character isn't '0', ensuring no
// two adjacent zeros.
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string cur;
        backtrack(n, cur, ans);
        return ans;
    }

private:
    void backtrack(int n, string& cur, vector<string>& ans) {
        if ((int)cur.size() == n) {
            ans.push_back(cur);
            return;
        }

        // always safe to append '1'
        cur.push_back('1');
        backtrack(n, cur, ans);
        cur.pop_back();

        // append '0' only if previous char isn't '0'
        if (cur.empty() || cur.back() != '0') {
            cur.push_back('0');
            backtrack(n, cur, ans);
            cur.pop_back();
        }
    }
};
