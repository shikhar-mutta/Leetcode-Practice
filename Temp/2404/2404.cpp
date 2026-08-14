// Link: https://leetcode.com/problems/most-frequent-even-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> freq;
        for (int x : nums) if (x % 2 == 0) freq[x]++;
        int best = -1, bestCount = 0;
        for (auto &[val, c] : freq) {
            if (c > bestCount) { bestCount = c; best = val; }
        }
        return best;
    }
};
