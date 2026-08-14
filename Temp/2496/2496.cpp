// Link: https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int best = 0;
        for (auto &s : strs) {
            bool allDigits = true;
            for (char c : s) if (!isdigit(c)) allDigits = false;
            int val = allDigits ? stoi(s) : (int)s.size();
            best = max(best, val);
        }
        return best;
    }
};
