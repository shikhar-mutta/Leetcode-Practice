// Link: https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)  SC: O(n) recursion depth (excluding output)
// Approach: backtracking trying every palindromic prefix at each starting index
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        function<void(int)> bt = [&](int start) {
            if (start == (int)s.size()) { res.push_back(cur); return; }
            for (int end = start; end < (int)s.size(); end++) {
                if (isPalindrome(s, start, end)) {
                    cur.push_back(s.substr(start, end - start + 1));
                    bt(end + 1);
                    cur.pop_back();
                }
            }
        };
        bt(0);
        return res;
    }
private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
};
