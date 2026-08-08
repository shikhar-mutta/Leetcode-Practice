// Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        int best = -1;
        for (auto& [val, c] : cnt) {
            if (val == c) best = max(best, val);
        }
        return best;
    }
};
