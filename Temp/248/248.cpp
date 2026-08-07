// Link: https://leetcode.com/problems/strobogrammatic-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(5^(n/2)) across all lengths in range  SC: O(n) recursion depth (excluding output)
// Approach: for each length between low.size() and high.size(), generate all strobogrammatic numbers
// of that length (outside-in pair construction) and count those whose string falls within [low, high]
// (comparing same-length numeric strings lexicographically is equivalent to numeric comparison)
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for (int len = low.size(); len <= (int)high.size(); len++) {
            for (auto& s : build(len, len)) {
                if ((int)s.size() != len) continue;
                if ((int)s.size() == (int)low.size() && s < low) continue;
                if ((int)s.size() == (int)high.size() && s > high) continue;
                count++;
            }
        }
        return count;
    }
private:
    vector<string> build(int n, int m) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        vector<string> inner = build(n - 2, m);
        vector<string> res;
        vector<pair<char,char>> pairs = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        for (auto& s : inner) {
            for (auto& [a, b] : pairs) {
                if (n == m && a == '0' && n != 1) continue;
                res.push_back(string(1, a) + s + string(1, b));
            }
        }
        return res;
    }
};
