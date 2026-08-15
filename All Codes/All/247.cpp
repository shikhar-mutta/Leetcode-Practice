// Link: https://leetcode.com/problems/strobogrammatic-number-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(5^(n/2))  SC: O(n) recursion depth (excluding output)
// Approach: build from the outside in, recursively wrapping each valid pair (0-0,1-1,6-9,8-8,9-6)
// around a shorter strobogrammatic core; skip leading '0' unless the whole number is length core==n
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return build(n, n);
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
                if (n == m && a == '0') continue;
                res.push_back(string(1, a) + s + string(1, b));
            }
        }
        return res;
    }
};
