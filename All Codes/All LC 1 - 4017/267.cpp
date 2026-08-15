// Link: https://leetcode.com/problems/palindrome-permutation-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (n/2)!)  SC: O(n)
// Approach: count char frequencies; fail fast if more than one odd count. Build the half-string from
// each char's floor(count/2) copies, backtrack all distinct permutations of that half (skipping
// duplicate values at the same recursion level), mirror each to form the full palindrome (with the
// single odd char, if any, in the middle)
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;
        string oddChar;
        string half;
        for (auto& [c, cnt] : freq) {
            if (cnt % 2) {
                if (!oddChar.empty()) return {};
                oddChar = string(1, c);
            }
            half += string(cnt / 2, c);
        }
        sort(half.begin(), half.end());
        vector<string> res;
        string cur;
        vector<bool> used(half.size(), false);
        function<void()> bt = [&]() {
            if (cur.size() == half.size()) {
                string rev = cur;
                reverse(rev.begin(), rev.end());
                res.push_back(cur + oddChar + rev);
                return;
            }
            for (int i = 0; i < (int)half.size(); i++) {
                if (used[i]) continue;
                if (i > 0 && half[i] == half[i-1] && !used[i-1]) continue;
                used[i] = true;
                cur += half[i];
                bt();
                cur.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};
