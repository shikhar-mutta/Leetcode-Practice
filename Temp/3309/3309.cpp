// Link: https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toBinary(int x) {
        if (x == 0) return "0";
        string s;
        while (x > 0) { s += ('0' + (x & 1)); x >>= 1; }
        reverse(s.begin(), s.end());
        return s;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<int> idx = {0, 1, 2};
        sort(idx.begin(), idx.end());
        int best = 0;
        do {
            string s;
            for (int i : idx) s += toBinary(nums[i]);
            int val = stoi(s, nullptr, 2);
            best = max(best, val);
        } while (next_permutation(idx.begin(), idx.end()));
        return best;
    }
};
