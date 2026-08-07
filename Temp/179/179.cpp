// Link: https://leetcode.com/problems/largest-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort strings with a custom comparator: a should come before b if a+b > b+a
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int x : nums) strs.push_back(to_string(x));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        string res;
        for (auto& s : strs) res += s;
        return res;
    }
};
